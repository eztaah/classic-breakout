@echo off

cls

if exist .\debug.exe (
    del .\debug.exe
)

C:/raylib/w64devkit/bin/mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=debug OBJS="src/*.cpp" BUILD_MODE=DEBUG CFLAGS="-I./include -mwindows"

if exist .\debug.exe (
    .\debug.exe
) else (
    echo Compilation failed, not running the executable.
)