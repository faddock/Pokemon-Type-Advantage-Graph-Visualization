# Executable names:
EXE = draw-graph
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
CPP_FILES += $(wildcard graphStructure/*.cpp)
CPP_FILES += $(wildcard graphAlgorithms/*.cpp)
CPP_FILES += $(wildcard graphUtil/*.cpp)
OBJS = main.o $(CPP_FILES:.cpp=.o)

# Use the cs225 makefile template:
include cs225/make/cs225.mk
