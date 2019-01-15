#pragma once
#include "MyObject.h"
#include "Animation.h"

class Cloud:
	public MyObject,
	public Animation
{
public:
	Cloud(string fileName);
	~Cloud(){};

	void Display();
	void Update(const double& deltaTime);

private:
	double time;
	float sensitivity;

	void Draw();
};

