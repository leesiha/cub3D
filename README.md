# cub3D

## Overview
Cub3D is a simple 3D game engine project inspired by Wolfenstein 3D, created using the MiniLibX graphics library. This project is part of the 42 curriculum and demonstrates fundamental concepts of 3D graphics rendering through raycasting.

## Features
- Basic 3D rendering using raycasting
- Textured walls and sprites
- Player movement and rotation
- Simple map parsing

## Getting Started

### Prerequisites
- Make sure you have `gcc` and `make` installed.
- MiniLibX library is required.

### Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/leesiha/cub3D.git
   cd cub3D
   ```
2. Compile the project:
   ```sh
   make
   ```

### Running the Project
1. Execute the binary with a map file:
   ```sh
   ./cub3D maps/sample_map.cub
   ```

## Controls
- `W`, `A`, `S`, `D`: Move the player
- `Left Arrow`, `Right Arrow`: Rotate the player
- `ESC`: Exit the game

## Code Structure
- `src/`: Source code files
- `include/`: Header files
- `maps/`: Sample map files
- `textures/`: Texture files

## Map File Format
Maps are simple text files with the following elements:
- `1`: Wall
- `0`: Empty space
- `W`: Player start position

Example:
```
1111111
1000001
100W001
1000001
1111111
```


## Code Convention

### 1. All directory and file names must be written in noun form.
- Directory names should describe all the files they contain.
- File names should describe all the functions written within them.
- In other words, directory names should indicate the purpose of use, and file names should indicate functionality.
```
pars/strlen.c
-> Used for parsing, with the functionality to count the length of a string.

pars/strjoin.c
-> Used for parsing, with the functionality to join two strings into one.
```

### 2. Each file must contain one function with the same name as the file.
- A file can contain up to 5 functions.
- Each function should perform a single task, and the function name should clearly indicate its purpose.

### 3. All variable names must have a clear purpose.
- Instead of using meaningless variable names like i, j, k, use names like idx, len, cnt that clearly indicate the role of the variable.
```
p_idx : Index of the string p
p_len : Length of the string p
p_cnt : Count of the character p
```

### 4. After creating a file, you must test if it functions as intended.
- Perform tests by writing a main function.
- Do not delete the main function you wrote for testing; comment it out with `//` to remember the test cases.

### 5. After finishing the implementation, proceed with integrating the code together.
- The project proceeds with the following steps:
```
step 1. Assign parts to be implemented individually
step 2. Implement and refactor functions
step 3. Combine the individually implemented functions and verify they work correctly
```