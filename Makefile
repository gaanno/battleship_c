#c++ 20
CC = g++
CFLAGS = -std=c++2a -I./tablero -I./jugador -I./barco -I./

# Especifica solo los archivos .cpp para la compilación
FILES = tablero/comun.cpp tablero/guerra.cpp tablero/registro.cpp jugador/persona.cpp flota/barco.cpp 

# Nombre del ejecutable
TARGET = main

all: $(TARGET)

$(TARGET): $(FILES) main.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)