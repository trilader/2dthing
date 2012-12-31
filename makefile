LIBS=-lSDL

all: src/*.cpp
	g++ $? -o 2d $(LIBS)
