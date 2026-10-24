# Activity 1 - Hello Triangle

## Goal

Create the smallest modern OpenGL render path: vertex data, a vertex array,
two shaders, and a draw call.

## Tasks

1. Put three 3D positions in a CPU array.
2. Create a VBO and VAO, upload the array, and describe attribute location 0
   with `glVertexArrayAttribFormat`.
3. Read `shaders/exo1.vsh` and `shaders/exo1.fsh`, compile both shaders, link
   them into a program, and print compilation/link errors.
4. In `render()`, bind the program and VAO, call `glDrawArrays(GL_TRIANGLES, 0, 3)`,
   then leave OpenGL state in a predictable state.
5. Release the OpenGL objects in the destructor.

## OpenGL functions you may need

You do not need to discover the function names from scratch. These are the
functions used by this activity:

### Buffers and vertex arrays

- `glCreateBuffers`
- `glNamedBufferData`
- `glCreateVertexArrays`
- `glVertexArrayVertexBuffer`
- `glVertexArrayAttribFormat`
- `glVertexArrayAttribBinding`
- `glEnableVertexArrayAttrib`

### Shaders and programs

- `glCreateShader`
- `glShaderSource`
- `glCompileShader`
- `glGetShaderiv`
- `glGetShaderInfoLog`
- `glCreateProgram`
- `glAttachShader`
- `glLinkProgram`
- `glGetProgramiv`
- `glGetProgramInfoLog`
- `glDeleteShader`

### Drawing and cleanup

- `glUseProgram`
- `glBindVertexArray`
- `glDrawArrays`
- `glDeleteVertexArrays`
- `glDeleteBuffers`
- `glDeleteProgram`

## Loading shader files

The template already provides a small helper in
[`src/Files.h`](../src/Files.h). Include it with `#include "Files.h"` and use
`Files::loadFileContent("shaders/exo1.vsh")` (and the fragment shader path)
to get a `std::string`. Pass its `c_str()` to `glShaderSource`; you do not
need to write your own file-reading code.

## Checkpoint

You should see one triangle on the grey background. If it is invisible, check
the vertex coordinates, attribute stride, shader locations, and current working
directory.

## Optional challenges

- Change the three positions to make a wider or inverted triangle.
- Use a constant in the fragment shader to change its color.
- Add a second triangle to the same VBO and draw six vertices.
- Make a small `ShaderProgram` helper that owns a program and hides shader
  compilation/linking.
- Replace the repeated VAO/VBO cleanup with a small RAII wrapper.
