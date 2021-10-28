CC = gcc
CFLAGS += -Wall -Wextra -Werror
DEPS += ./include/my_bc.h
OBJFILES = src/main.o src/lexer.o src/\
	           src/string_management.o src/utility.o\
			   src/solving_tree.o src/postfix.o

TARGET = my_bc
all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

.PHONY: clean
clean:
		rm -f src/*.o $(TARGET)
