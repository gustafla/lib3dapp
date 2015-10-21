# A makefile to build gl-rpg.

SRCS=main.cpp window.cpp game.cpp config.cpp vectors.cpp program.cpp util.cpp mesh.cpp buffer.cpp static_model.cpp obj_file.cpp matrices.cpp mvp.cpp resource_handler.cpp primitives.cpp rgba_image.cpp texture.cpp paths.cpp tga_file.cpp
TARGET=game
OBJS=$(SRCS:.cpp=.o)
CFLAGS=-O2 -MMD -MP
debug:CFLAGS=-g -MMD -MP
INCLUDES=-I./
LFLAGS=
LIBS=-lGL -lSDL2 -lGLEW
LIBS_CUSTOM=
CC=g++

all: $(TARGET)
	strip --strip-all $(TARGET)
	@echo "Finished."
	
debug: $(TARGET)
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
