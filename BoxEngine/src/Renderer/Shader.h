#pragma once
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader();
	Shader(const std::string& vertexSrc, const std::string& fragSrc, bool loadFromFile = true);
	~Shader();

	void loadFromFile(const std::string& vertexPath, const std::string& fragPath);
	void loadFromSource(const std::string& vertexSrc, const std::string& fragSrc);
	void use() const;

	void loadUniform1i(const std::string& name, int v);
	void loadUniform2i(const std::string& name, int v0, int v1);
	void loadUniform3i(const std::string& name, int v0, int v1, int v2);
	void loadUniform4i(const std::string& name, int v0, int v1, int v2, int v3);
	void loadUniform1f(const std::string& name, float v);
	void loadUniform2f(const std::string& name, float v0, float v1);
	void loadUniform3f(const std::string& name, float v0, float v1, float v2);
	void loadUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void loadUniform2iv(const std::string& name, const glm::ivec2& v);
	void loadUniform3iv(const std::string& name, const glm::ivec3& v);
	void loadUniform4iv(const std::string& name, const glm::ivec4& v);
	void loadUniform2fv(const std::string& name, const glm::fvec2& v);
	void loadUniform3fv(const std::string& name, const glm::fvec3& v);
	void loadUniform4fv(const std::string& name, const glm::fvec4& v);
	void loadUniformMat3(const std::string& name, const glm::mat3& mat);
	void loadUniformMat4(const std::string& name, const glm::mat4& mat);
private:
	int getUniformLocation(const std::string& name);
private:
	uint32_t m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocations;
};
