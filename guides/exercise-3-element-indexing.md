# Activity 3 - Element Indexing

## Goal

Build a quad from two triangles while storing each corner only once.

## Tasks

1. Replace the triangle data with four corners and keep the position/color
   attribute layout from Activity 2.
2. Create an element buffer containing six indices and attach it to the VAO
   with `glVertexArrayElementBuffer`.
3. Use `glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr)`.
4. Try changing the index order and identify the winding direction of each
   triangle.

## OpenGL functions you may need

### Vertex and element buffers

- `glCreateBuffers`
- `glNamedBufferData`
- `glCreateVertexArrays`
- `glVertexArrayVertexBuffer`
- `glVertexArrayElementBuffer`
- `glVertexArrayAttribFormat`
- `glVertexArrayAttribBinding`
- `glEnableVertexArrayAttrib`

### Shaders

Use `Files::loadFileContent` from
[`src/Files.h`](../src/Files.h) for `shaders/exo3.vsh` and
`shaders/exo3.fsh`, then use the shader functions from Activity 1:
`glCreateShader`, `glShaderSource`, `glCompileShader`, `glCreateProgram`,
`glAttachShader`, and `glLinkProgram`.

### Drawing and object lifetime

- `glUseProgram`
- `glBindVertexArray`
- `glDrawElements`
- `glDeleteVertexArrays`
- `glDeleteBuffers`
- `glDeleteProgram`

The shader functions from Activity 1 are still required:
`glCreateShader`, `glShaderSource`, `glCompileShader`, `glCreateProgram`,
`glAttachShader`, and `glLinkProgram`.

## Checkpoint

The result should be a single rectangular quad made from two triangles. The
shared diagonal must not create a visible gap.

## Optional challenges

- Add one more triangle by editing only the index array.
- Reverse the order of one triangle's three indices and describe what changes.
