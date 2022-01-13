SRC=src
OBJ=obj
BINDIR=bin

CXX=g++
CXXFLAGS=-Wall -g -std=c++2a
LDLIBS=-lSDL2main -lSDL2
INCLUDE_FLAGS=-I include -I include/cookie

SRCS=$(wildcard $(SRC)/*.cc)
OBJS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SRCS))
DEPENDS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.d, $(SRCS))
BIN=$(BINDIR)/random_walker

.PHONY: all run clean

all: $(BIN)

run: all
	./$(BIN)

-include $(DEPENDS)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE_FLAGS) -MMD -MP -c -o $@ $<

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

clean:
	$(RM) $(OBJ)/*.o $(OBJ)/*.d $(BIN)