# Breakout

A classic breakout game clone.

![Gameplay](https://github.com/EzTaah/cpp-breakout/blob/main/assets/gameplay.gif)


### Controls
- Use `Q` to move the paddle left and `D` to move it right
- Press `space` to restart

---

# Building and Development

## Informations
- Game developed using the [Raylib](https://www.raylib.com/) library.
- Your best score is saved to your local storage. You can find it in the following directory:  
```C:\Users\USERNAME\AppData\Local```

## Prerequisites
- Ensure you have a compiler installed on your computer.
- There's no need to install Raylib separately. It is already precompiled and stored in the 'lib' folder.

## Compilation instructions

1. Open a PowerShell/cmd terminal and navigate to the project's directory.

2. Navigate to the build directory : 
```
cd build 
```

3. Compile the project : (assuming that you use the minGW compiler)   
``` 
mingw32-make 
```

4. Run the game :   
```
.\debug.exe
```
