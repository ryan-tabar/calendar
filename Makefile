CC = gcc
CFLAGS = -Wall -Wextra

SRCS = mini_calendar.c functions.c
OBJS = $(SRCS:.c=.o)
HEADER = functions.h
TARGET = mini_calendar

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

