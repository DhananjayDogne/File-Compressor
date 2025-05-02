# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable and object files
EXEC = my_program
OBJECTS = main.o compressor.o decompressor.o

# Default rule: make the executable
all: $(EXEC)

# Rule to link object files into the final executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

# Rule to compile source files into object files
main.o: main.cpp compressor.h decompressor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

compressor.o: compressor.cpp compressor.h
	$(CXX) $(CXXFLAGS) -c compressor.cpp

decompressor.o: decompressor.cpp decompressor.h
	$(CXX) $(CXXFLAGS) -c decompressor.cpp

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(EXEC)

