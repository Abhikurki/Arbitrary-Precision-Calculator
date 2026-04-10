# Name        : Abhishek Y
# Project     : Arbitrary Precision Calculator (APC)
# File        : Makefile
# Description : This Makefile is used to automate the compilation of the
#               APC project. It compiles multiple source files, links
#               object files to generate the executable, and manages
#               dependencies efficiently. It also provides commands to
#               clean intermediate files and rebuild the project.

CC = gcc
CFLAGS = -Wall
TARGET = apc

SRC = APC_main.c DLL.c Conversion.c ADDITION.c SUBSTRACTION.c MULTIPLICATION.c DIVISION.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c APC.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)