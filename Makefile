OBJS = src/*.cpp
CC = g++
COMPILER_FLAGS = -g -Wall -std=c++11
LINKER_FLAGS = -lSDL2
OBJ_NAME = bin/sierpinksi-gasket

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)