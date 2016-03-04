#pragma once
#include <string>
#include <GL\glew.h>

class GLSLProgram
{
public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

	void linkShaders();

	void addAttribute(std::string attributeName);

	void use();
	void unUse();

private:
	void compileShader(const std::string& filePath, GLuint id);

	int _numAttributes;

	GLuint _programId;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

