#version 450

layout(location = 0) in vec3 fragPos;

layout(location = 0) out vec4 outColor;
layout(binding = 3) uniform sampler2D normMap;
layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;
	vec4 lightColor;
	vec3 eyePos;
} gubo;
void main() {
	vec3 Norm = normalize(fragNorm);