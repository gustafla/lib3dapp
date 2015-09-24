# A makefile to build gl-rpg.

SRCS=main.cpp window.cpp game.cpp config.cpp vectors.cpp shader.cpp util.cpp
TARGET=game
OBJS=$(SRCS:.cpp=.o)
CFLAGS=-g -MMD -MP
INCLUDES=-I./
LFLAGS=
LIBS=-lGL -lSDL2 -lGLEW
LIBS_CUSTOM=
CC=g++

all: $(TARGET)
	@echo "Finished."

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS) $(LIBS_CUSTOM)
#	strip --strip-all $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	find ./ -type f -name "*.o" -delete
	find ./ -type f -name "*.d" -delete
	rm -f $(TARGET)

-include *.d
