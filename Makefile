# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDES = -I./include
SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = ./bin/my_program

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up
clean:
	@echo "Deleting object files: $(OBJ)"
	rm -f $(OBJ)
	@echo "Deleting target file: $(TARGET)"
	rm -f $(TARGET)

.PHONY: all clean