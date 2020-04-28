def Settings(**kwargs):
    INC = ['-Igodot-cpp/include', '-Igodot-cpp/include/core',
           '-Igodot-cpp/include/gen', '-Igodot-cpp/godot_headers']
    return {
        'flags': ['-x', 'c++', '-Wall', '-Wextra', '-Werror'] + INC,
    }
