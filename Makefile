CC = gcc
CFLAGS = -Wall -Wextra -g -IInclude

SRC = SRC/main.c SRC/tarefa.c SRC/arquivo.c SRC/UI.c

TARGET = tracker.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run:
	$(TARGET)

clean:
	del /Q $(TARGET)