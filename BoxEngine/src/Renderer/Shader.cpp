#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>

enum class ShaderType : unsigned char
{
	NONE, VertexShader, FragmentShader
};

static std::string readFile(const std::string& filepath);
static uint32_t compileShader(const std::string& shaderSrc, ShaderType type);
static uint32_t linkProgram(const uint32_t vertexShader, const uint32_t fragmentShader);

Shader::Shader()
	: m_RendererID { 0 }
{
}

Shader::Shader(const std::string& vertexSrc, const std::string& fragSrc, bool isLoadedFromFile)
	: m_RendererID { 0 }
{
	if (isLoadedFromFile)
		loadFromFile(vertexSrc, fragSrc);
	else
		loadFromSource(vertexSrc, fragSrc);
}

Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

void Shader::loadFromFile(const std::string& vertexPath, const std::string& fragPath)
{
	if (m_RendererID) glDeleteProgram(m_RendererID);

	std::string vertexSource;
	std::string fragmentSource;
	vertexSource = readFile(vertexPath);
	fragmentSource = readFile(fragPath);
	uint32_t vertexShader = compileShader(vertexSource, ShaderType::VertexShader);
	uint32_t fragmentShader = compileShader(fragmentSource, ShaderType::FragmentShader);
	m_RendererID = linkProgram(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::loadFromSource(const std::string& vertexSrc, const std::string& fragSrc)
{
	if (m_RendererID) glDeleteProgram(m_RendererID);

	uint32_t vertexShader = compileShader(vertexSrc, ShaderType::VertexShader);
	uint32_t fragmentShader = compileShader(fragSrc, ShaderType::FragmentShader);
	m_RendererID = linkProgram(vertexShader, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() const
{
	glUseProgram(m_RendererID);
}

void Shader::loadUniform1i(const std::string& name, int v)
{
	int location = getUniformLocation(name);
	glUniform1i(location, v);
}

void Shader::loadUniform2i(const std::string& name, int v0, int v1)
{
	int location = getUniformLocation(name);
	glUniform2i(location, v0, v1);
}

void Shader::loadUniform3i(const std::string& name, int v0, int v1, int v2)
{
	int location = getUniformLocation(name);
	glUniform3i(location, v0, v1, v2);
}

void Shader::loadUniform4i(const std::string& name, int v0, int v1, int v2, int v3)
{
	int location = getUniformLocation(name);
	glUniform4i(location, v0, v1, v2, v3);
}

void Shader::loadUniform1f(const std::string& name, float v)
{
	int location = getUniformLocation(name);
	glUniform1f(location, v);
}

void Shader::loadUniform2f(const std::string& name, float v0, float v1)
{
	int location = getUniformLocation(name);
	glUniform2f(location, v0, v1);
}

void Shader::loadUniform3f(const std::string& name, float v0, float v1, float v2)
{
	int location = getUniformLocation(name);
	glUniform3f(location, v0, v1, v2);
}

void Shader::loadUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	int location = getUniformLocation(name);
	glUniform4f(location, v0, v1, v2, v3);
}

void Shader::loadUniform2iv(const std::string& name, const glm::ivec2& v)
{
	int location = getUniformLocation(name);
	glUniform2iv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniform3iv(const std::string& name, const glm::ivec3& v)
{
	int location = getUniformLocation(name);
	glUniform3iv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniform4iv(const std::string& name, const glm::ivec4& v)
{
	int location = getUniformLocation(name);
	glUniform4iv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniform2fv(const std::string& name, const glm::fvec2& v)
{
	int location = getUniformLocation(name);
	glUniform2fv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniform3fv(const std::string& name, const glm::fvec3& v)
{
	int location = getUniformLocation(name);
	glUniform3fv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniform4fv(const std::string& name, const glm::fvec4& v)
{
	int location = getUniformLocation(name);
	glUniform4fv(location, 1, glm::value_ptr(v));
}

void Shader::loadUniformMat3(const std::string& name, const glm::mat3& mat)
{
	int location = getUniformLocation(name);
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::loadUniformMat4(const std::string& name, const glm::mat4& mat)
{
	int location = getUniformLocation(name);
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

int Shader::getUniformLocation(const std::string& name)
{
	if (m_UniformLocations.find(name) != m_UniformLocations.end())
	{
		return m_UniformLocations[name];
	}

	int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
	m_UniformLocations[name] = location;
	return location;
}

std::string readFile(const std::string& filepath)
{
	std::string result;
	std::ifstream file(filepath, std::ios::in | std::ios::binary);
	if (file)
	{
		file.seekg(0, std::ios::end);
		size_t size = file.tellg();
		if (size != -1)
		{
			result.resize(size);
			file.seekg(0, std::ios::beg);
			file.read(result.data(), size);
		}
		else
		{
			printf("Read File Failed: [From Shader Creation] -> \n\treading %s", filepath.c_str());
		}
	}
	else
	{
		printf("Open File Failed: [From Shader Creation] -> \n\topening %s", filepath.c_str());
	}

	return result;
}

uint32_t compileShader(const std::string& shaderSrc, ShaderType type)
{
	GLenum shaderType = type == ShaderType::VertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
	GLuint shader = glCreateShader(shaderType);

	const char* source = shaderSrc.c_str();
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	int success = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		int length = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		GLchar* log = new GLchar[1024];
		glGetShaderInfoLog(shader, 1024, nullptr, log);

		printf("%s Error: , \n\t%s", type == ShaderType::VertexShader ? "Vertex Shader" : "Fragment Shader", log);

		delete[] log;
	}

	return shader;
}

uint32_t linkProgram(const uint32_t vertexShader, const uint32_t fragmentShader)
{
	uint32_t program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	int success = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		int length = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		GLchar* log = new GLchar[length];
		glGetProgramInfoLog(program, length, &length, log);

		printf("Shader Program Error: \n\t%s", log);

		delete[] log;
	}

	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	return program;
}
