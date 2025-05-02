
# Raytracer

- Ray tracing is a technique used to generate realistic digital images by simulating the inverse path of light. Your goal is to create a program able to generate an image from a file describing the scene.

## Prerequisites

You need to install :

- SFML : [2.6.2](https://www.sfml-dev.org/fr/)
- [CMAKE](https://cmake.org/cmake/help/latest/command/install.html) to compile project
## Installation

Clone the project

```bash
    git clone git@github.com:EpitechPromo2028/B-OOP-400-LIL-4-1-raytracer-mathis.bukowski.git raytracer
    cd raytracer
```

Init and create the project

```bash
    mkdir -p build && cd build
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build .
    cd ..
```

Run the project!

```bash
    ./raytracer [scene_file]
```

## Documentation

On the directory, you will be able to find the technical documentation to build with:
```bash
    doxide build
    mkdocs build
    mkdocs serve
```

You will also find a guide (below) for creating a scene.

## Guide

### How to create a scene for RayTracer Project ? Let's dive in !
#### Here you will find all tools to build your own scene.

- File :
```cfg
    
```


## Authors

- Mathis Bukowski - Developer, Mail: mathis.bukowski@epitech.eu
- Rafael Drouart - Developer. Mail: rafael.drouart@epitech.eu
- Valentin Frappart - Developer. Mail: valentin.frappart@epitech.eu


