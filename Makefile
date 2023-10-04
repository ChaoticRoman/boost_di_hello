build:
	mkdir -p build
	g++ -std=c++17 -O2 -fno-exceptions -fno-rtti -Wall -Werror -pedantic-errors src/main.cpp -I include -o build/hello

run: build
	build/hello
