CC = clang
SRC = src/main.c src/builtins.c src/executor.c
OUT = build/sheL

all:
	$(CC) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)