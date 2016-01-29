# A makefile.

SRCS=main.cpp window.cpp application.cpp config.cpp vectors.cpp program.cpp util.cpp mesh.cpp buffer.cpp static_model.cpp obj_file.cpp matrices.cpp mvp.cpp resource_handler.cpp geo_quad.cpp geo_triangle_equilateral.cpp rgba_image.cpp texture.cpp paths.cpp tga_file.cpp shader.cpp graphics.cpp framebuffer.cpp renderbuffer.cpp
TARGET=3dapp
OBJS=$(SRCS:.cpp=.o)
CFLAGS=-O2 -MMD -MP
debug:CFLAGS=-g -MMD -MP -DDEBUG_BUILD
INCLUDES=-I./
LFLAGS=
LIBS=-lGL -lSDL2 -lGLEW
LIBS_CUSTOM=
CC=g++

raspi:CFLAGS=-O2 -MMD -MP -DRASPI_BUILD
raspi:INCLUDES=-I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/src/hello_pi/libs/ilclient -I/opt/vc/src/hello_pii/libs/vgfont -I./
raspi:LFLAGS=-L/opt/vc/lib
raspi:LIBS=-lGLESv2 -lEGL -lbcm_host -lSDL2

all: $(TARGET)
	strip --strip-all $(TARGET)
	@echo "Finished."
	
debug: $(TARGET)
	@echo "Finished."

raspi: $(TARGET)
	@echo "Finished."

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS) $(LIBS_CUSTOM)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	find ./ -type f -name "*.o" -delete
	find ./ -type f -name "*.d" -delete
	rm -f $(TARGET)

-include *.d
