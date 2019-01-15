#pragma once
#include "DisplayableObject.h"
#include "MyScene.h"
#include <cmath>

class Sun:
	public DisplayableObject
{
public:
	Sun();
	~Sun(){};

	void Display();

private:
	//MyScene* ms;
	GLfloat *_ambient, *_diffuse, *_specular;
	float billboardMatrix[16];

	void setLight();
};

