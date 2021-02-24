#include "App.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer/OpenGL/VertexArray.h"
#include "Renderer/OpenGL/VertexBuffer.h"
#include "Renderer/OpenGL/IndexVertexBuffer.h"
#include "Renderer/OpenGL/Shader.h"
#include "Renderer/OpenGL/OpenGLRenderer.h"
#include "Renderer/OpenGL/Texture.h"

App::App(int width, int height, std::string name)
{
	m_Window = PlatformFactory::GetPlatform(width, height, name);
    m_Renderer = RendererFactory::GetRenderer();
}

void App::Run()
{
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };
    
    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3
    };

    Shader shader("shaders/triangle.vert", "shaders/triangle.frag");
    
    IndexVertexBuffer indexedVertexBuffer(vertices, sizeof(vertices), indices, sizeof(indices));
    VertexArray vertexArray(1, indexedVertexBuffer);
    vertexArray.SetAttrib();
    
    Texture texture("textures/container.jpg", GL_TEXTURE0);
    Texture texture2("textures/awesomeface.png", GL_TEXTURE1);

    shader.Bind();
    shader.SetInt("texture1", 0);
    shader.SetInt("texture2", 1);
    
    while (!m_Window->ShouldClose())
    {
        m_Window->ProcessInput();
        
        m_Renderer->Clear();

        shader.Bind();
        vertexArray.BindTexture(texture.GetTexture());
        vertexArray.BindTexture(texture2.GetTexture());
        vertexArray.Bind();
        m_Renderer->Draw(6);
        
        m_Window->SwapBuffers();
        m_Window->PollEvents();
    }

    indexedVertexBuffer.Delete();
    vertexArray.Delete();
    shader.Delete();

    m_Window->Terminate();
}