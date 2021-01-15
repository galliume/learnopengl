#pragma once

class AbstractWindow
{
public:
	virtual void ProcessInput() {};
	virtual bool ShouldClose() = 0;
	virtual void SwapBuffers() {};
	virtual void PollEvents() {};
	virtual void Terminate() {};
};