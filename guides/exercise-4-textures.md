# Activity 4 - Textures

## Goal

Map an image onto geometry using UV coordinates and a sampler in the
fragment shader.

## Tasks

1. Add two UV values to each quad vertex and update the stride and offset.
2. Create a 2D texture, load `assets/wall.jpg` with stb_image, and upload it
   with the texture-storage functions.
3. Configure wrapping and filtering, then bind the texture to texture unit 0.
4. Connect the sampler uniform in `shaders/exo4.fsh` to unit 0 and sample
   using the interpolated UV value.
5. Flip the image vertically at load time if its orientation is incorrect.

## OpenGL functions you may need

### Geometry and shaders

Reuse the functions from Activities 1–3:
`glCreateBuffers`, `glNamedBufferData`, `glCreateVertexArrays`,
`glVertexArrayVertexBuffer`, `glVertexArrayElementBuffer`,
`glVertexArrayAttribFormat`, `glVertexArrayAttribBinding`,
`glEnableVertexArrayAttrib`, `glCreateShader`, `glShaderSource`,
`glCompileShader`, `glCreateProgram`, `glAttachShader`, `glLinkProgram`,
`glUseProgram`, `glBindVertexArray`, and `glDrawElements`.

Use `Files::loadFileContent` from
[`src/Files.h`](../src/Files.h) to read the vertex and fragment shader files.

### Textures

- `glCreateTextures`
- `glTextureStorage2D`
- `glTextureSubImage2D`
- `glTextureParameteri`
- `glBindTextureUnit`
- `glDeleteTextures`

The image itself is loaded with stb_image rather than OpenGL:
`stbi_set_flip_vertically_on_load`, `stbi_load`, and `stbi_image_free`.
The sampler uniform can be assigned with `glGetUniformLocation` and
`glUniform1i`.

## Checkpoint

The wall image should cover the entire quad without a solid color replacing
it. If it is upside down, fix the load orientation or the UV coordinates.

## Optional challenges

- Set `GL_REPEAT` and use UVs from 0.0 to 2.0 so the image repeats twice.
- Change one pair of UV coordinates to mirror the image on one triangle.
