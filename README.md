# Rhythm Tetris

Tetris with pieces that drop to your claps!
Or to the beat of your own music files! Made with C++ / Python2.7

Python Modules:
 - PyAudio

Dependencies:
 - PortAudio
 - SDL2
 - SDL2-gfx
 
Ubuntu/Linux Mint:
<pre>
sudo apt-get install portaudio19-dev
sudo apt-get install python-pyaudio
sudo apt-get install build-essential
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-gfx-dev
</pre>
 
GAME MODES:
- Standard:
  Standard game of Tetris
- Clap 2 Drop:
  Clapping or making sudden noises drops the pieces
- Play 2 Music:
  Pieces drop to the beat of music (from file)
- Louder and Faster:
  Pieces drop faster depending on the loudness of the environment
  
 
Controls:

 CLAP: Instantly Drop Piece
 
 Left/Right Arrow Keys: Move Left/Right
 
 Up Arrow Key: Rotate Piece
 
 Down Array Key: Move Piece Down (faster than autodrop)
 
 Space Key: Instantly Drop Piece
 
 R Key: Resets the Game
