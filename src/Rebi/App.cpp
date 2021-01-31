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
         0.0f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f   // top 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec3 aColor;\n"
        "out vec3 v_Color;\n"
        "void main()\n"
        "{\n"
        "   v_Color = aColor;\n"
        "   gl_Position = vec4(aPos, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "layout(location = 0) out vec4 color;\n"
        "in vec3 v_Color;\n"
        "uniform float u_Time;\n"
        "void main()\n"
        "{\n"
        "   color = vec4(v_Color, 1.0f);\n"
        "}\n\0";

    Shader shader;
    shader.AddVertex(1, &vertexShaderSource);
    shader.AddFragment(1, &fragmentShaderSource);


    IndexVertexBuffer indexedVertexBuffer(vertices, sizeof(vertices), indices, sizeof(indices));
    VertexArray vertexArray(1, indexedVertexBuffer);
    //vertexArray.Bind();
    vertexArray.SetAttribPointer(3, 24);

    /*
    IndexVertexBuffer indexedVertexBuffer2(vertices2, sizeof(vertices2), indices, sizeof(indices));
    VertexArray vertexArray2(1, indexedVertexBuffer2);
    vertexArray2.Bind();
    vertexArray2.SetAttribPointer(3, 12);
    */
    
    while (!m_Window->ShouldClose())
    {
        m_Window->ProcessInput();
        
        m_Renderer->Clear();
        
        /*
        shader.Bind();
        vertexArray2.Bind();
        m_Renderer->Draw(6);
        */
        shader.Bind();
        vertexArray.Bind();
        m_Renderer->Draw(3);

        m_Window->SwapBuffers();
        m_Window->PollEvents();
    }

    //vertexArray2.Delete();
    //indexedVertexBuffer2.Delete();
    indexedVertexBuffer.Delete();   
    vertexArray.Delete();
    shader.Delete();

    m_Window->Terminate();
}