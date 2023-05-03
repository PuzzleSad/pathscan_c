CC := gcc
CFLAGS := -Wall -Wextra



BIN:= a.elf

STATICLIB:= pathscan.a
DYNAMICLIB:= pathscan.so

all: bin run

bin: $(BIN)

run: $(BIN)
	./$(BIN)

staticlib: $(STATICLIB)


SOURCES:= 	$(wildcard src/*.c)\
		$(wildcard src/scanner/src/*.c)

OBJECTS:= $(patsubst %.c, build/%.o, $(notdir $(SOURCES)) )



$(BIN): build/selftest.o $(OBJECTS)
	@echo "linking..."
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(STATICLIB): $(OBJECTS)
	ar -rc $@ $^




build/selftest.o: selftest.c
	@$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/scanner/src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
