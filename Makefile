#c++ 20
CC = g++
CFLAGS = -std=c++2a -I./src

# Especifica solo los archivos .cpp para la compilación
FILES = src/tablero_comun.cpp src/tablero_guerra.cpp src/tablero_registro.cpp src/persona.cpp src/barco.cpp 

# Nombre del ejecutable
TARGET = main

all: $(TARGET)

$(TARGET): $(FILES) main.cpp
	$(CC) $(CFLAGS) $^ -o $@ -fopenmp

clean:
	rm -f $(TARGET)