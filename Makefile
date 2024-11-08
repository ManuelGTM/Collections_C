#Compiler
CC = gcc

#Compiler flags | Adding the files to the Compiler
CFLAGS = -Werror -Ilib/Node -I/Queue -Ilib/Stack

# Object files 
OBJ_FILES = build/Node.o build/Queue.o build/Stack.o build/main.o

# Output executable
OUTPUT = build/Collections

# Default target
all: $(OUTPUT)

# Rule to create build directory
$(OUTPUT): $(OBJ_FILES) | build
	@echo "Linking object files into executable: $@"
	@$(CC) $(OBJ_FILES) -o $(OUTPUT)

# Rule to compile main.c
build/main.o: src/main.c | build
	@echo "Compiling main.c..."
	@$(CC) $(CFLAGS) -c src/main.c -o build/main.o

# Rule to compile Node.c
build/Node.o: lib/Node/Node.c | build
	@echo "Compiling Node.c..."
	@$(CC) $(CFLAGS) -c lib/Node/Node.c -o build/Node.o

# Rule to compile Stack.c
build/Stack.o: lib/Stack/Stack.c | build
	@echo "Compiling Stack.c..."
	@$(CC) $(CFLAGS) -c lib/Stack/Stack.c -o build/Stack.o

# Rule to compile Queue.c
build/Queue.o: lib/Queue/Queue.c | build
	@echo "Compiling Queue.c..."
	@$(CC) $(CFLAGS) -c lib/Queue/Queue.c -o build/Queue.o

# Rule to create build directory if it doesn't exist
build:
	@echo "Creating build folder... "
	@mkdir -p build
	@sleep 1
	@echo "Build directory created"

# Clean up build directory
clean:
	@echo "Cleaning up build files..."
	@rm -rf build/*.o build/Collections	
	@sleep 1
	@echo "Cleaned up build files..."


.PHONY: all clean
