# all:
# 	g++ -o autoCompleteSuggestionSystem main.cpp trie/Trie.cpp utils/FileUtils.cpp

# 	./autoCompleteSuggestionSystem



# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++17 -Wall -I./

# Sources
SRC = main.cpp trie/Trie.cpp utils/FileUtils.cpp

# Output
OUT = autoCompleteSuggestionSystem

# Default build
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

# Clean build files
clean:
	rm -f $(OUT)
