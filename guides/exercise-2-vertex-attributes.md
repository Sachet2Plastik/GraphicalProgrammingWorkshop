# Activity 2 - Adding Colors

## Goal

Store more than one attribute per vertex and observe interpolation between
the values supplied at the triangle's corners.

## Tasks

1. Extend each vertex with an RGB color, producing a six-float interleaved
   layout.
2. Keep position at location 0 and describe color at location 1 with the
   correct offset and stride.
3. Add a color input and output to the vertex shader, then receive it in the
   fragment shader.
4. Render the same triangle and inspect the smooth color gradients.

## OpenGL functions you may need

Most of the setup is the same as Activity 1.

### Buffers and vertex attributes

- `glCreateBuffers`
- `glNamedBufferData`
- `glCreateVertexArrays`
- `glVertexArrayVertexBuffer`
- `glVertexArrayAttribFormat`
- `glVertexArrayAttribBinding`
- `glEnableVertexArrayAttrib`

### Shaders and drawing

- `glCreateShader`
- `glShaderSource`
- `glCompileShader`
- `glCreateProgram`
- `glAttachShader`
- `glLinkProgram`
- `glUseProgram`
- `glBindVertexArray`
- `glDrawArrays`

### Shader files, debugging, and cleanup

Use `Files::loadFileContent` from
[`src/Files.h`](../src/Files.h) to read both shader files. For debugging and
cleanup, the Activity 1 functions
`glGetShaderiv`, `glGetShaderInfoLog`, `glGetProgramiv`,
`glGetProgramInfoLog`, `glDeleteShader`, `glDeleteVertexArrays`,
`glDeleteBuffers`, and `glDeleteProgram` are useful too.

## Checkpoint

Each corner should have its chosen color and the interior should be a blend.
A black triangle usually means the fragment shader output or interface
matching is incomplete.

## Optional challenges

- Swap two colors and predict the new gradient before running the program.
- Mark the fragment input `flat` and explain why interpolation disappears.
- Extract one helper such as `configureAttribute(...)` or `createProgram(...)`
  and use it in this exercise.
