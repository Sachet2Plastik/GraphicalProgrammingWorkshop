# Activity 5 - Going 3D: Rotating Cube and Depth Buffer

## Goal

Move from clip-space coordinates to a real 3D scene. You will build an
indexed cube, transform it through model/view/projection matrices, animate it,
and use the depth buffer to hide faces correctly.

## Tasks

1. Use the 24 cube vertices and 36 indices already provided in
   `exercises/exo5.h`. There are four vertices per face so every face can have
   its own complete UV rectangle. Each vertex contains position and UV
   attributes; focus on uploading the arrays and drawing them with
   `glDrawElements`.
2. Reuse the texture setup from Activity 4. Bind the cube texture before the
   draw call.
3. In the vertex shader, declare `model`, `view`, and `projection` uniforms
   and calculate `projection * view * model * vec4(aPos, 1.0)`.
4. Build a model matrix with GLM rotation. Use elapsed time, not a fixed
   angle, so the cube keeps moving every frame.
5. Build a view matrix that moves the camera away from the origin and a
   perspective projection with a 45-degree field of view, the 800:600 aspect
   ratio, and near/far planes such as 0.1 and 100.
6. Query the three uniform locations once after linking and upload the matrices
   every frame with `glUniformMatrix4fv`.
7. Ensure `GL_DEPTH_TEST` is enabled and clear `GL_DEPTH_BUFFER_BIT` every
   frame. The renderer already performs both operations; identify where.

## OpenGL functions you may need

### Geometry, textures, and shaders

Reuse the functions from Activities 1–4:
`glCreateBuffers`, `glNamedBufferData`, `glCreateVertexArrays`,
`glVertexArrayVertexBuffer`, `glVertexArrayElementBuffer`,
`glVertexArrayAttribFormat`, `glVertexArrayAttribBinding`,
`glEnableVertexArrayAttrib`, `glCreateTextures`, `glTextureStorage2D`,
`glTextureSubImage2D`, `glTextureParameteri`, `glBindTextureUnit`,
`glCreateShader`, `glShaderSource`, `glCompileShader`, `glCreateProgram`,
`glAttachShader`, `glLinkProgram`, `glUseProgram`, `glBindVertexArray`,
and `glDrawElements`.

Use `Files::loadFileContent` from
[`src/Files.h`](../src/Files.h) to read `shaders/exo5.vsh` and
`shaders/exo5.fsh`, just as in the previous activities.

### Matrices and uniforms

- `glGetUniformLocation`
- `glUniformMatrix4fv`

These send the GLM matrices from C++ to the shader. The sampler still uses
`glGetUniformLocation` and `glUniform1i`.

### Depth testing and cleanup

- `glEnable(GL_DEPTH_TEST)`
- `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`
- `glDeleteTextures`
- `glDeleteVertexArrays`
- `glDeleteBuffers`
- `glDeleteProgram`

The template's `Renderer` already enables depth testing and clears both
buffers. You should recognize these calls even if you do not move them into
the exercise class.

## Checkpoint

The textured cube should rotate around the origin, with nearer faces hiding
farther faces. If the cube is flat, inspect the Z coordinates and projection.
If faces flicker or appear through one another, check depth testing and the
depth-buffer clear.

## Optional challenges

- Change the rotation axis only, keeping the speed unchanged, and describe
  which faces become easier to see.
- Set a different UV layout for one face and verify that only that face changes.
