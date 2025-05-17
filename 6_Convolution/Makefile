# Nombre del ejecutable
TARGET = my_program

# Archivos fuente
SRC = my_code.c waveforms.c

# Compilador y banderas
CC = gcc
LDFLAGS = -lm

all: $(TARGET)
	./$(TARGET)
# Regla principal
$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(LDFLAGS)

# Limpiar archivos generados
clean:
	rm -f $(TARGET)
	rm -f *.dat
