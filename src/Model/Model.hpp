#pragma once

#include <glew.h>
#include <glm.hpp>
#include <vector>

#include "Bone.hpp"
#include "Vertex.hpp"
#include "..\Transform.hpp"

class Model : public Transform
{
protected:
	GLuint VAO, VBO, IBO;
	aiNode *rootNode;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	
	unsigned int loadVertices(const aiMesh *mesh, const aiColor3D &fallbackColor = aiColor3D(0.7f, 0.7f, 0.7f));
	void loadIndices(const aiMesh *mesh, unsigned int startingVertex);

public:
	Model(const glm::vec3 &position = glm::vec3(0.0f));
	~Model();

	bool load(const std::string &filename, const aiColor3D &fallbackColor = aiColor3D(0.7f, 0.7f, 0.7f));
	void update(float deltaTime);
	void render() const;
};