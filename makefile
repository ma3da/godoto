INC = -Igodot-cpp/include -Igodot-cpp/include/core -Igodot-cpp/include/gen -Igodot-cpp/godot_headers

default:
	echo No

build:
	clang -fPIC -o src/init.os -c src/init.cpp -g -O3 -std=c++14 $(INC)
	clang -o bin/libtest.so -shared src/init.os -Lgodot-cpp/bin -lgodot-cpp.linux.debug.64
