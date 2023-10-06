SRC = main.cpp

all: dir src

src: $(SRC)
	clang++ -std=c++17 -o bin/executable $(SRC)

dir:
	mkdir -p bin

clean:
	rm -rf bin

run: all
	bin/executable