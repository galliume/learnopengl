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
        -0.9f, -0.9f, 0.0f,
         0.9f, -0.9f, 0.0f,
         0.0f,  0.9f, 0.0f
    };
    float vertices2[] = {
         0.2f, -0.2f, 0.0f,  // bottom right
         0.2f,  0.2f, 0.0f,  // top right
        -0.2f, -0.2f, 0.0f,  // bottom left
        -0.2f,  0.2f, 0.0f   // top left 
    };
    float vertices3[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    const char* vertexShaderSource = "#version 460 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 460 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
            "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n";
    const char* fragmentShaderSource2 = "#version 460 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "FragColor = vec4(0.1f, 0.8f, 0.6f, 1.0f);\n"
        "}\n";

    Shader shader;
    shader.AddVertex(1, &vertexShaderSource);
    shader.AddFragment(1, &fragmentShaderSource);

    Shader shader2;
    shader2.AddVertex(1, &vertexShaderSource);
    shader2.AddFragment(1, &fragmentShaderSource2);

    IndexVertexBuffer indexedVertexBuffer(vertices2, sizeof(vertices2), indices, sizeof(indices));
    VertexArray vertexArray(1, indexedVertexBuffer);
    vertexArray.Bind();
    vertexArray.SetAttribPointer(3, 12);

    IndexVertexBuffer indexedVertexBuffer2(vertices3, sizeof(vertices3), indices, sizeof(indices));
    VertexArray vertexArray2(1, indexedVertexBuffer2);
    vertexArray2.Bind();
    vertexArray2.SetAttribPointer(3, 12);
    
    
    while (!m_Window->ShouldClose())
    {
        m_Window->ProcessInput();
        
        m_Renderer->Clear();
        
        shader.Bind();
        vertexArray2.Bind();
        m_Renderer->Draw(6);

        shader2.Bind();
        vertexArray.Bind();
        m_Renderer->Draw(6);

        m_Window->SwapBuffers();
        m_Window->PollEvents();
    }

    vertexArray2.Delete();
    indexedVertexBuffer2.Delete();
    indexedVertexBuffer.Delete();   
    vertexArray.Delete();
    shader2.Delete();
    shader.Delete();

    m_Window->Terminate();
}