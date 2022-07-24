#include <functional>
#include <filesystem>
#include <lucio.hpp>
#include <lucio/render/vertex.hpp>
#include <lucio/render/mesh.hpp>
#include <lucio/render/shader.hpp>
#include <lucio/render/texture.hpp>

int main()
{ 
	lucio::App myApp = lucio::App();

	std::string assetPath = "../../sandbox/asset/";
	
	// Load Vertecis & Shaders
	lucio::vertex_t vertices[] = {						// Position, 						Color, 				TextureCoords
								  lucio::vertex_t(glm::fvec3(0.5f, 0.5f, 0.0f), glm::fvec3(1.0f, 1.0f, 0.0f), glm::fvec2(1.0f, 1.0f)),	 // Top Right
								  lucio::vertex_t(glm::fvec3(0.5f, -0.5f, 0.0f), glm::fvec3(1.0f, 0.0f, 0.0f), glm::fvec2(1.0f, 0.0f)),	 // Bottom Right
								  lucio::vertex_t(glm::fvec3(-0.5f, -0.5f, 0.0f), glm::fvec3(0.0f, 0.0f, 0.0f), glm::fvec2(0.0f, 0.0f)), // Bottom Left
								  lucio::vertex_t(glm::fvec3(-0.5f, 0.5f, 0.0f), glm::fvec3(0.0f, 1.0f, 1.0f), glm::fvec2(0.0f, 1.0f))}; // Top left

	unsigned int indices[] = { 0, 1, 3,
								1, 2, 3 };

	lucio::Mesh simpleShape = lucio::Mesh(vertices, 4, indices, 6);
	lucio::Shader simpleShader = lucio::Shader(assetPath + "shader/primitiveTexture.vs", assetPath + "/shader/primitiveTexture.fs");
	simpleShader.setUniform(0, 0.0f, 0.0f, 0.0f);

	lucio::Texture simpleTexture = lucio::Texture(assetPath + "texture/crate.png");

	myApp.run(lucio::CallBack<void>([&simpleTexture, &simpleShader, &simpleShape] {
		
		simpleTexture.bind();
		simpleShader.bind();
		simpleShape.bind();

		}));

	return 0;
}
