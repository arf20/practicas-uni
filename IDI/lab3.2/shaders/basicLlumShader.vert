#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;
out vec3 _matamb;
out vec3 _matdiff;
out vec3 _matspec;
out float _matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem del focus de llum

uniform vec3 colorFocus;
uniform vec3 posFocus;  // en SCO

out vec4 vertexSCO;
out vec3 normalSCO;

void main() {	
    vertexSCO = view * TG * vec4(vertex, 1.0);
    normalSCO = normalize(vec3(inverse(transpose(view * TG)) * vec4(normal, 1.0)));

    gl_Position = proj * view * TG * vec4(vertex, 1.0);

    _matamb = matamb;
    _matdiff = matdiff;
    _matspec = matspec;
    _matshin = matshin;
}

