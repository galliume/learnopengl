#include "App.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer/OpenGL/VertexArray.h"
#include "Renderer/OpenGL/VertexBuffer.h"
#include "Renderer/OpenGL/IndexVertexBuffer.h"
#include "Renderer/OpenGL/Shader.h"
#include "Renderer/OpenGL/OpenGLRenderer.h"

#include "stb_image.h"

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

    Shader shader(
        "shaders/triangle.vert", 
        "shaders/triangle.frag"
    );
    
    IndexVertexBuffer indexedVertexBuffer(vertices, sizeof(vertices), indices, sizeof(indices));
    VertexArray vertexArray(1, indexedVertexBuffer);
    vertexArray.SetAttribPointer(6, 8);

    stbi_set_flip_vertically_on_load(1);

    unsigned int texture;
    glGenTextures(1, &texture);

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //for jpeg, if width is not a multiple of 4 it doesn't work properly
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char* data = stbi_load("textures/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    stbi_set_flip_vertically_on_load(0);

    while (!m_Window->ShouldClose())
    {
        m_Window->ProcessInput();
        
        m_Renderer->Clear();      

        shader.Bind();
        vertexArray.Bind();
        //vertexArray.BindTexture(texture);
        m_Renderer->Draw(6);

        m_Window->SwapBuffers();
        m_Window->PollEvents();
    }

    indexedVertexBuffer.Delete();
    vertexArray.Delete();
    shader.Delete();

    m_Window->Terminate();
}