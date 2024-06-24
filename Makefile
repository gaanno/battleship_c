#c++ 20
CC = g++
CFLAGS = -std=c++2a -I./src

# Especifica solo los archivos .cpp para la compilación
FILES = src/comun.cpp src/guerra.cpp src/registro.cpp src/persona.cpp src/barco.cpp 

# Nombre del ejecutable
TARGET = main

all: $(TARGET)

$(TARGET): $(FILES) main.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)