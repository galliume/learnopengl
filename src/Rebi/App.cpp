#include "App.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Renderer/OpenGL/VertexArray.h"
#include "../Renderer/OpenGL/VertexBuffer.h"
#include "../Renderer/OpenGL/IndexVertexBuffer.h"
#include "../Renderer/OpenGL/Shader.h"
#include "../Renderer/OpenGL/OpenGLRenderer.h"

App::App(int width, int height, std::string name)
{
	m_Window = PlatformFactory::GetPlatform(width, height, name);
    m_Renderer = RendererFactory::GetRenderer();
}

void App::Run()
{
    float vertices[] = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    };

    unsigned int indices[] = {
        0, 1, 2   // first triangle
    };

    Shader shader(
        "shaders/triangle.vert", 
        "shaders/triangle.frag"
    );
    
    IndexVertexBuffer indexedVertexBuffer(vertices, sizeof(vertices), indices, sizeof(indices));
    VertexArray vertexArray(1, indexedVertexBuffer);
    vertexArray.SetAttribPointer(3, 6);
    
    while (!m_Window->ShouldClose())
    {
        m_Window->ProcessInput();
        
        m_Renderer->Clear();
        
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;

        shader.Bind();
        shader.SetFloat("u_Time", greenValue);
        vertexArray.Bind();
        m_Renderer->Draw(3);

        m_Window->SwapBuffers();
        m_Window->PollEvents();
    }

    indexedVertexBuffer.Delete();
    vertexArray.Delete();
    shader.Delete();

    m_Window->Terminate();
}