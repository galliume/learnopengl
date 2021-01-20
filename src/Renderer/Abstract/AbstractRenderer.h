#pragma once

class AbstractRenderer
{
public:
	virtual void Clear() { };
	virtual void Draw(int count) { };
};