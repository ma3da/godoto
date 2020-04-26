#!/bin/bash

mkdir bin
mkdir src
git clone --recursive https://github.com/GodotNativeTools/godot-cpp

# build C++ bindings lib for linux, debug
. venv/bin/activate
cd godot-cpp
scons platform=<your platform> generate_bindings=yes
cd ..
deactivate
