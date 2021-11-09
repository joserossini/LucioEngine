#include <lucio.hpp>
#include <functional>
#include <filesystem>
#include <engine/graphics/vertex.hpp>
#include <engine/graphics/mesh.hpp>
#include <engine/graphics/shader.hpp>
#include <engine/graphics/texture.hpp>

lucio::App * myApp;
lucio::Mesh * simpleShape;
lucio::Shader * simpleShader;
lucio::Texture * simpleTexture;

std::string assetPath = "C:/Users/JR/Desktop/Repos/lucio/asset";

void GameLoop() {

	simpleTexture->bind();
	simpleShader->bind();
	simpleShape->bind();

}

int main()
{ 

	// Generate Application
	myApp = new lucio::App();

	// Load Vertecis & Shaders
	lucio::vertex_t vertices[] = { // Position, Color, TextureCoords
	lucio::vertex_t(glm::fvec3(0.5f, 0.5f, 0.0f), glm::fvec3(1.0f, 1.0f, 0.0f), glm::fvec2(1.0f, 1.0f)), // Top Right
	lucio::vertex_t(glm::fvec3(0.5f, -0.5f, 0.0f), glm::fvec3(1.0f, 0.0f, 0.0f), glm::fvec2(1.0f, 0.0f)), // Bottom Right
	lucio::vertex_t(glm::fvec3(-0.5f, -0.5f, 0.0f), glm::fvec3(0.0f, 0.0f, 0.0f), glm::fvec2(0.0f, 0.0f)), // Bottom Left
	lucio::vertex_t(glm::fvec3(-0.5f, 0.5f, 0.0f), glm::fvec3(0.0f, 1.0f, 1.0f), glm::fvec2(0.0f, 1.0f)) }; // Top left

	unsigned int indices[] = { 0, 1, 3,
						1, 2, 3 };

	simpleShape = new lucio::Mesh(vertices, 4, indices, 6);
	simpleShader = new lucio::Shader(assetPath + "/shader/primitiveTexture.vs", assetPath + "/shader/primitiveTexture.fs");
	simpleShader->setUniform(0, 10.0f, 0.0f, 0.0f);

	simpleTexture = new lucio::Texture(assetPath + "/texture/crate.png");

	myApp->run(lucio::CallBack<void>(GameLoop));

	return 0;
}