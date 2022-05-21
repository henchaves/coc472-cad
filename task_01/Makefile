# Compilers
CC = gcc
CF = gfortran

# the build target executable:
TARGET = main

all: $(TARGET)_c $(TARGET)_f 

$(TARGET)_c: $(TARGET).c
	$(CC) $(TARGET).c -o $(TARGET)_c 

$(TARGET)_f: $(TARGET).f95
	$(CF) $(TARGET).f95 -o $(TARGET)_f 

clean:
	$(RM) $(TARGET)_c
	$(RM) $(TARGET)_f