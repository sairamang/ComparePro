# ComparePro
Desktop Application to provide Comparison between Files

## Prerequisites
- CMake
- glfw
- OpenGL
- pkgconfig
- gcc

## Prerequisites Install Script
```
        sudo apt-get update
        sudo apt install libgl1-mesa-dev
        sudo apt install freeglut3-dev
        sudo apt-get install libglfw3
        sudo apt-get install libglfw3-dev
        sudo apt-get install libglew2.2
        sudo apt-get install libglew-dev
```

## Build Instructions
```
    mkdir build
    cd build
    cmake -DTEST=1
    make
```

## Features

- User can select files for compare
- Based on the differences, you can view the files
- User can edit both files at same time and copy contents to and from both files


## Support 
For any bugs/queries, please contact sairaman28@gmail.com