CXX		:= g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src/main.cpp src/pa.cpp
SIMP	:= src/simple.cpp src/pa.cpp

INCLUDE	:= -I include 
INCLUDE	+= -I ../libraries/portaudio/include 

COMMON	:= common
# LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system

PORT = -lportaudio
PORT += -L ../libraries/portaudio/build

EXECUTABLE	:= main
SIMPLE		:= simple

all: $(BIN)/$(EXECUTABLE)

simple: $(BIN)/$(SIMPLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(INCLUDE) $(CXX_FLAGS) $(SRC) -o $(BIN)/$(EXECUTABLE) $(PORT)

$(BIN)/$(SIMPLE): $(SIMP)
	$(CXX) $(INCLUDE) $(CXX_FLAGS) $(SIMP) -o $(BIN)/$(SIMPLE) $(PORT)

# $(BIN)/$(SINE): $(SRC)/paex_sine_c++.cpp
# 	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $(PORT) $^ -o$@

remove-simp:
	-rm $(BIN)/simple

clean:
	-rm $(BIN)/*