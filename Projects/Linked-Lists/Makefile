# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Source files
SRC = src/main.cpp

# Output binary
OUTPUT = LinkedListProgram

# Build rule
all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUTPUT)

# Clean rule to remove the compiled files
clean:
	rm -f $(OUTPUT)

# Run rule
run: all
	./$(OUTPUT)
