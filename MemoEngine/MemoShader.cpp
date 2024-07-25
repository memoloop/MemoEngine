#include "pch.h"
#include "MemoShader.h"

MEMOENGINE_API Shader::Shader(std::string filename)
{
	// Create program
	program = glCreateProgram();

	// Create shaders
	vertexShader = createShader(GL_VERTEX_SHADER, loadSource("res/shaders/"+filename+".vert").c_str());
	fragmentShader = createShader(GL_FRAGMENT_SHADER, loadSource("res/shaders/"+filename+".frag").c_str());

	// Attach shaders at program
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	// Link the program
	glLinkProgram(program);

	int linkStatus;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE) 
	{
		char infoLog[512];
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << "Unable to link the shader at program: " << infoLog << std::endl;
		std::exit(-1);
	}

	// Validate program
	glValidateProgram(program);

	int validateStatus;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &validateStatus);
	if (validateStatus != GL_TRUE)
	{
		char infoLog[512];
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		std::cerr << "Unable to validate the program: " << infoLog << std::endl;
		std::exit(-1);
	}

	// Destroy shaders
	// Now the program has their
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

MEMOENGINE_API Shader::~Shader()
{
	// Delete program on finishing
	glDeleteProgram(program);
}

MEMOENGINE_API void Shader::useProgram()
{
	// Use program for drawing
	glUseProgram(program);
}

MEMOENGINE_API void Shader::setUniform(std::string name, int value)
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniform1i(location, value);
}

MEMOENGINE_API void Shader::setUniform(std::string name, float value)
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniform1f(location, value);
}

MEMOENGINE_API void Shader::setUniform(std::string name, Vector2D* value)
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniform2f(location, value->x, value->y);
}

MEMOENGINE_API void Shader::setUniform(std::string name, Vector3D* value)
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniform3f(location, value->x, value->y, value->z);
}

MEMOENGINE_API void Shader::setUniform(std::string name, Vector4D* value)
{
	int location = glGetUniformLocation(program, name.c_str());
	glUniform4f(location, value->x, value->y, value->z, value->w);
}

MEMOENGINE_API GLuint Shader::createShader(int type, const GLchar* source)
{
	// Create and compile the shader code
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	// Check shader status
	GLint status;
	GLchar infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != 1) 
	{
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cerr << "Unable to compile shader: " << infoLog << std::endl;
		std::exit(-1);
	}

	return shader;
}

MEMOENGINE_API std::string Shader::loadSource(std::string filename)
{
	// Load file
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Unable to load file: " << filename << std::endl;
		std::exit(-1);
	}

	// Read file context and add to buffer
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}