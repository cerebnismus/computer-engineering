CC = g++
CFLAGS = -Wall -Iinclude -std=c++11

SRC_DIR := ./src
OBJ_DIR := ./lib

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

compile: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o ./bin/huffman_tree main.cpp $^
	cp -f ./data/dene.txt ./bin/

test:
	cd bin; ./huffman_tree ; cd -

clean:
	rm -rf ./bin/* ./lib/*.o

.PHONY: clean

all: compile
