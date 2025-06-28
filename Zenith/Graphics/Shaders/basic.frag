#version 330 core

in vec3 v_Color;
in vec2 v_TexCoords;

out vec4 FragColor;

void main() {
    FragColor = vec4(v_Color, 1.0);
}
