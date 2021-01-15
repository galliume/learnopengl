#include "App.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Renderer/OpenGL/VertexArrayObject.h"
#include "../Renderer/OpenGL/VertexBuffer.h"
#include "../Renderer/OpenGL/Shader.h"

App::App(int width, int height, std::string name)
{
	window = PlatformFactory::GetPlatform(width, height, name);
}

void App::Run()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
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
    shader.AddVertexShader(1, &vertexShaderSource);
    shader.AddFragmentShader(1, &fragmentShaderSource);
    shader.Link();

    VertexArrayObject vertexArrayObject(1, GL_ARRAY_BUFFER, vertices, GL_STATIC_DRAW);
    vertexArrayObject.SetAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3, 0);

    while (!window->ShouldClose())
    {
        window->ProcessInput();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Draw(vertexArrayObject.GetVAO(), GL_TRIANGLES, 0, 3);

        window->SwapBuffers();
        window->PollEvents();
    }

    vertexArrayObject.Delete();
    shader.Delete();

    window->Terminate();
}