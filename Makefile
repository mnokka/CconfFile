
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm
INCLUDES = -I./inih
SOURCES = main.c inih/ini.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = cparser

# Verbose support, use make VERBOSE=1
ifeq ($(VERBOSE), 1)
    Q =
else
    Q = @
endif


all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)
	chmod u+x $(EXECUTABLE)
	@echo "$(EXECUTABLE) created.  Execute ./$(EXECUTABLE) or make run"


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)


run: $(EXECUTABLE)
	./$(EXECUTABLE)
