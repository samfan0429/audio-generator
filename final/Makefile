CXX		:= g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
GRAPHICS := include/GraphicObject
LIB		:= lib
LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system -lportaudio
PORT := -lportaudio -L ../libraries/portaudio/build
EXECUTABLE	:= main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(GRAPHICS) $(PORT) $^ -o$@ $(LIBRARIES)

clean:
	-rm $(BIN)/*