#version 330 core

layout (location=0) in vec3 vertex;
layout (location=1) in vec3 color;

uniform mat4 transform;

out vec4 vertexColor;

void main()  {
    gl_Position = transform * vec4(vertex, 1.0);
    vertexColor = vec4(color, 1);
}

