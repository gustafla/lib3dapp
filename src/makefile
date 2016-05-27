# Copyright 2016 Lauri Gustafsson
#This file is part of lib3dapp.

#lib3dapp is free software: you can redistribute it and/or modify
#it under the terms of the GNU Lesser General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.

#lib3dapp is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU Lesser General Public License for more details.

#You should have received a copy of the GNU Lesser General Public License
#along with lib3dapp.  If not, see <http://www.gnu.org/licenses/>.*/

# A makefile.

SRCS=$(wildcard *.cpp)
TARGET=lib3dapp.a
OBJS=$(SRCS:.cpp=.o)
CFLAGS=-O2 -MMD -MP -fPIC -pg -g
debug:CFLAGS=-g -MMD -MP -DDEBUG_BUILD
INCLUDES=-I./ -Iinclude/
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
