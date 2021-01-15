#include <iostream>
#include "Window.h"

int main(int argc, char** argv)
{
    Window window(2048, 1080, "Learn OpenGL");

    while (!window.ShouldClose())
    {
        window.ProcessInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.SwapBuffers();
        glfwPollEvents();
    }

    glfwTerminate();

	return 0;
}