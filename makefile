CC = clang
INC = -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot_headers

sources=$(wildcard src/*.cpp)
objects=$(patsubst %.cpp, %.o, $(sources))

default:
	echo No

build-debug: $(objects) debug
build-release: $(objects) release

$(objects): src/%.o: src/%.cpp
	$(CC) -fPIC -o $@ -c $< -g -O3 -std=c++14 $(INC)

debug:
	$(CC) -o bin/libdebug.so -shared src/*.o -Lgodot-cpp/bin -lgodot-cpp.linux.debug.64

release:
	$(CC) -o bin/librelease.so -shared src/*.o -Lgodot-cpp/bin -lgodot-cpp.linux.release.64

clean:
	rm src/*.o
