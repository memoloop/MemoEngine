#include "pch.h"
#include "MemoGraphic.h"

MEMOENGINE_API Shape::Shape(float vertices[], size_t verticesSize, int indices[], size_t indicesSize)
{
	verticesNum = verticesSize / (3 * sizeof(float));
	indicesNum = indicesSize / sizeof(int);

	// Generate
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vboPos);
	glGenBuffers(1, &ebo);

	// Bind VAO
	glBindVertexArray(vao);
	
	// Bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, vboPos);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	// Bind EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

	// Configure vertex attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

MEMOENGINE_API Shape::~Shape()
{
	// Delete buffers
	glDeleteBuffers(1, &vboPos);
	glDeleteBuffers(1, &ebo);

	// Delete vertex array
	glDeleteVertexArrays(1, &vao);
}

MEMOENGINE_API void Shape::draw()
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indicesNum, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}