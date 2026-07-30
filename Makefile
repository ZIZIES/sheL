CC = clang
SRC = src/main.c
OUT = build/sheL

all:
	$(CC) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
run: all
	./build/sheL