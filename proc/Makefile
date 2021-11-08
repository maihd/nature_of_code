SRC=$(wildcard framework/*.cpp)

all:
	g++ -o proc.exe \
		main.cpp $(SRC) \
		raylib-mingw64/lib/libraylib.a -Iraylib-mingw64/include \
		-lgdi32 -luser32 -lwinmm
	./proc.exe