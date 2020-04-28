#!/bin/bash

# fetch godot-cpp (incl. godot-headers)
mkdir bin
mkdir src
git clone --recursive https://github.com/GodotNativeTools/godot-cpp

# create python venv w. scons
python3 -m venv venv
. venv/bin/activate
pip install -r requirements.txt

# build C++ bindings lib, in godot-cpp/bin 
cd godot-cpp
scons platform=linux generate_bindings=yes target=debug --jobs 8
scons platform=linux generate_bindings=yes target=release --jobs 8
cd ..
deactivate
