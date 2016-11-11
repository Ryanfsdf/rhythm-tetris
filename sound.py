#!python

# Clap/Beat Detection made by Ryan Kim

import pyaudio
import sys
import audioop
import time

chunk = 512
FORMAT = pyaudio.paInt16
CHANNELS = 1
RATE = 48000
RECORD_DURATION = 500
NOISE_FLOOR_BASE = 100 #Higher for louder environments.

ampArray = [0,0,0]
data = ""
numBeatTimes = 0
#Log resets every time. Change between "w" and "a" to wipe or append
file = open("logRMS.txt","w")
floorNoise = 0

#Wipe file
fileC = open("SendToC","w")
fileC.close()

p = pyaudio.PyAudio()

#PyAudio sometimes takes too long with the "open" call and there is a
# large buffer buildup which causes an IOError when "read" is called.
# I used the 3 "read" calls as a testers to see if "open" took too 
# long or not.
while(1):
    stream = p.open(format=FORMAT,
                channels=CHANNELS, 
                rate=RATE, 
                input=True,
                output=True,
                frames_per_buffer=chunk)
    try:
        #Test 3 times
        data = stream.read(chunk)
        data = stream.read(chunk)
        data = stream.read(chunk)
    except IOError:
        print("PyAudio Open Failed")
        continue
    break


print("Setting Noise Cancellation Based on Background Noise")
NCSampleSize = 5;
for i in range(NCSampleSize):
    try:
        data = (stream.read(chunk))
        floorNoise += audioop.rms(data, 2)
    except IOError:
        print("Noise Cancellation Setup Failed")
floorNoise = floorNoise / NCSampleSize
print("Noise Floor is:" + str(floorNoise))


print("Starting Data Loop")
#Approximately 100 "read"s per second
#These are the threshold level that worked for me. May vary depending
# on microphone
for i in range(0, 48000 / chunk * RECORD_DURATION):
    try:
        data = (stream.read(chunk))
    except IOError:
        print("Frames were lost")

    rms = audioop.rms(data, 2)	    

    #Threshold value depends on what kind of noise is made. To make sure
    # only sudden, quick noises are detected, the code below guarantees
    # that the noise was not gradually increased
    threshold = (ampArray[0] + ampArray[1] + ampArray[2]) * 50 + \
        NOISE_FLOOR_BASE + floorNoise

    #If a noise is above threshold, it is written to SendToC
    if (rms > threshold):
        print("Beat Detected")
        print(rms)
        fileC = open("SendToC","a")
        fileC.write(str(numBeatTimes) + "\n")
        fileC.close()
        numBeatTimes += 1
        
    ampArray = ampArray[1:3]

    if (rms > NOISE_FLOOR_BASE + floorNoise):
        ampArray.append(rms)
    else:
        ampArray.append(0)

    file.write(str(rms)+ "\n")

print("Finished Data Loop")

print("Terminating Stream")
file.close()
stream.stop_stream()
stream.close()
p.terminate()
