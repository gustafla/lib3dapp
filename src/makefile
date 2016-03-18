# A makefile.

SRCS=window.cpp window_rpi.cpp application.cpp config.cpp vectors.cpp program.cpp util.cpp gfx_utils.cpp mesh.cpp buffer.cpp static_model.cpp obj_file.cpp matrices.cpp mvp.cpp resource_handler.cpp geo_quad.cpp geo_triangle_equilateral.cpp rgba_image.cpp texture.cpp paths.cpp tga_file.cpp shader.cpp graphics.cpp framebuffer.cpp renderbuffer.cpp scaling_rectangle.cpp uniforms.cpp lighting_state.cpp light.cpp
TARGET=lib3dapp.a
OBJS=$(SRCS:.cpp=.o)
CFLAGS=-O2 -MMD -MP -fPIC -pg -g
debug:CFLAGS=-g -MMD -MP -DDEBUG_BUILD
INCLUDES=-I./
LFLAGS=
#LIBS=-lGL -lSDL2 -lGLEW
LIBS_CUSTOM=
CC=g++

raspi:CFLAGS=-O2 -MMD -MP -fPIC -DRASPI_BUILD
raspi:INCLUDES=-I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/src/hello_pi/libs/ilclient -I/opt/vc/src/hello_pi/libs/vgfont -I./
raspi:LFLAGS=-L/opt/vc/lib
#raspi:LIBS=-lGLESv2 -lEGL -lbcm_host

all: $(TARGET)
	@echo "Finished."
	
debug: $(TARGET)
	@echo "Finished."

raspi: $(TARGET)
	@echo "Finished."

$(TARGET): $(OBJS)
	#$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS) $(LIBS_CUSTOM)
	ar rcs $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	find ./ -type f -name "*.o" -delete
	find ./ -type f -name "*.d" -delete
	rm -f $(TARGET)

-include *.d
