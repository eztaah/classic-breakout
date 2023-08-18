# Breakout Game with Raylib

A classic breakout game developed using the [Raylib](https://www.raylib.com/) library.

![Démonstration de mon jeu](https://github.com/EzTaah/cpp-breakout/main/assets/gameplay.gif)


## Features
- Classic brick-breaking action.
- Persistent high score saving.

### Keys
- Use `Q` to move the paddle left and `D` to move it right.

---

## Building and Development

### Informations
- Your best score is automatically saved to your local storage. You can find it in the following directory:   
```C:\Users\USERNAME\AppData\Local```

### Compilation instructions ( if you are using the minGW compiler)

1. Navigate to the build directory : 
```
cd build 
```

2. Generate the makefiles :  
``` 
cmake -G "MinGW Makefiles" .. 
```

3. Compile the project :   
``` 
mingw32-make 
```

4. Run the game :   
```
.\debug.exe
```