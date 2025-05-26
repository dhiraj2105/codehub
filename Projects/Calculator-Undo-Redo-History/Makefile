# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Executable name
TARGET = calculator

# Source files in src directory
SRCS = src/main.cpp \
       src/Calculator.cpp \
       src/OperationStack.cpp \
       src/History.cpp

# Output object files (optional if needed for advanced rules)
OBJS = $(SRCS:.cpp=.o)

# Default build rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)
