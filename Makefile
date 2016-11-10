BINARY 			:= Tetris
SRCS			:= $(wildcard *.cpp)
OBJS			:= $(SRCS:.cpp=.o)

DEBUG			:= -g

SDL_INCLUDE		:= `sdl2-config --cflags`
SDL_LIB			:= `sdl2-config --libs` -lSDL2_gfx
CPPFLAGS		+= $(SDL_INCLUDE)
CXXFLAGS		+= $(DEBUG) -Wall -std=c++0x
LDFLAGS			+= $(SDL_LIB)

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(OBJS)
	$(LINK.cpp) $(OBJS) -o $(BINARY) $(LDFLAGS)

.depend: $(SRCS)
	@- $(RM) .depend
	@- $(CXX) $(CPPFLAGS) $(CXXFLAGS)

clean:
	@- $(RM) $(BINARY)
	@- $(RM) $(OBJS)
