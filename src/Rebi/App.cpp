#include "App.h"

App::App(int width, int height, std::string name)
{
	window = PlatformFactory::GetPlatform(width, height, name);
}

void App::Run()
{
    while (!window->ShouldClose())
    {
        window->ProcessInput();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window->SwapBuffers();
        window->PollEvents();
    }

    window->Terminate();
}