#pragma once
#include "MyObject.h"
#include "Animation.h"

class Mountain :
	public MyObject,
	public Animation
{
public:
	Mountain(string fileName);
	~Mountain(){};

	void Display();
	void Update(const double& deltaTime);

private:
	double time;
	float sensitivity;

	void Draw();
};

