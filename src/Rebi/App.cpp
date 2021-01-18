#include "App.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Renderer/OpenGL/VertexBuffer.h"
#include "../Renderer/OpenGL/IndexVertexBuffer.h"
#include "../Renderer/OpenGL/Shader.h"
#include "../Renderer/OpenGL/Renderer.h"

App::App(int width, int height, std::string name)
{
	window = PlatformFactory::GetPlatform(width, height, name);
}

void App::Run()
{
    float vertices[] = {
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
        
    Shader shader;
    shader.AddVertex(1, &vertexShaderSource);
    shader.AddFragment(1, &fragmentShaderSource);
    shader.Bind();

    //VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    //vertexBuffer.SetAttribPointer(3, 3, (void*)0);

    IndexVertexBuffer indexedVertexBuffer(vertices, sizeof(vertices), indices, sizeof(indices));
    indexedVertexBuffer.SetAttribPointer(3, 3, (void*)0);

    while (!window->ShouldClose())
    {
        window->ProcessInput();
        
        Renderer::Clear();
        //Renderer::DrawArrays(vertexBuffer.GetVAO(), 3);
        Renderer::DrawElements(indexedVertexBuffer.GetVAO(), 6);

        window->SwapBuffers();
        window->PollEvents();
    }

    indexedVertexBuffer.Delete();
    //vertexBuffer.Delete();
    shader.Delete();

    window->Terminate();
}