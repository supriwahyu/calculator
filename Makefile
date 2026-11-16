CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -O2
LDFLAGS = -lm

TARGET = calculator

.PHONY: all clean

all: $(TARGET)

$(TARGET): calculator.c
	$(CC) $(CFLAGS) -o $(TARGET) calculator.c $(LDFLAGS)

clean:
	rm -f $(TARGET)
