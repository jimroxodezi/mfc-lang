# MFC

mfc stands for my first compiler. It is a compiler for a statically typed, compiled language with Java-like class syntax, C-like function syntax, and support for generic programming via templates. It emphasizes composition over inheritance. 

## Overview
- **Typing**: Static, with type names before identifiers.
- **Classes**: Java-style, supporting fields and methods, no inheritance, only composition.
- **Functions**: C-style syntax.
- **Templates**: Generic classes with `<T>` syntax.
- **Types**: Basic types (`int`, `float`, `bool`, `char`, `void`, `string`), class types, and template types.
- **Literals**: Integer, float, boolean, character, and string literals.


## Building

Dependencies:

 - CMake
 - A C++ compiler (any will do)


Firstly, generate a build tree using CMake.
```sh
cmake -B build
```

Then, invoke the build tree to build the library, tests, and everything else involved with mfc.
```sh
cmake --build build
```