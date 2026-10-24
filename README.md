# OpenGL Workshop

A hands-on introduction to modern OpenGL with C++.

The goal is to understand the fundamentals of real-time graphics by progressively building a small rendering application.

## Workshop progression

1. **First triangle** — shaders, vertex data, and draw calls.
2. **Vertex attributes** — colors and interpolation.
3. **Indexed drawing** — quads, vertex buffers, and element buffers.
4. **Textures** — UV coordinates, texture sampling, and image loading.
5. **3D rendering** — transformations, depth testing, and a rotating cube.

The student path is documented in [`guides/`](guides/). Start with
[`guides/exercise-1-hello-triangle.md`](guides/exercise-1-hello-triangle.md)
and complete the activities in order. The files in `exercises/` are deliberately
scaffolds with TODOs. Completed instructor material is kept separately in
`reference-solutions/` and should only be consulted after attempting an activity.
Presentation support for the workshop leader is available in


## Requirements

* Linux
* GCC or Clang with C++20 support
* CMake 3.21 or newer
* Git
* A graphics driver supporting OpenGL 4.6 Core
* SDL3 requirements

## Build

Clone the repository and enter the project directory:

```bash
git clone git@github.com:Sachet2Plastik/GraphicalProgrammingWorkshop.git
cd GraphicalProgrammingWorkshop
```

Configure the project:

```bash
cmake -S . -B build
```

Build it:

```bash
cmake --build build
```

Run the application:

```bash
./build/opengl-workshop
```

The first configuration downloads and builds the required dependencies, so it may take a little longer.

## Choosing an exercise

The default entry point is the activity currently selected in `src/main.cpp`.
To work on another
activity, include its header and instantiate its class (`Exo1` through `Exo4`)
in `main()`. The shader and asset paths are relative to the repository root,
so run the executable from the repository root.

### Running a reference solution

Reference solutions are not selected automatically. To test an activity,
temporarily change both the include and the class in `src/main.cpp`. For
example, for Activity 1:

```cpp
#include "reference-solutions/exercises/exo1.h"
Exo1 exercise;
```

Use the matching `exo2.h`/`Exo2`, `exo3.h`/`Exo3`, `exo4.h`/`Exo4`, or
`exo5.h`/`Exo5` pair for the other activities. Then rebuild and run from the
repository root:

```bash
cmake --build build
./build/opengl-workshop
```

Do not copy only a reference header into `exercises/`: the reference headers
load their matching shaders from `reference-solutions/shaders/`, while the
student shaders intentionally contain TODOs. Restore the include and class in
`src/main.cpp` after testing.

## Dependencies

* **SDL3** — window creation, OpenGL context, and event handling.
* **GLAD** — loading OpenGL functions.
* **GLM** — vector and matrix mathematics.
* **stb_image** — image loading for the texture exercises.

SDL3, GLM, and their dependencies are managed through CMake FetchContent. GLAD and stb_image are included in the repository.

## Development

The workshop uses an OpenGL 4.6 Core context.
