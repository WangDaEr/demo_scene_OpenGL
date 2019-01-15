#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Airplane.h"

class Fire:
	public DisplayableObject,
	public Animation
{
public:
	Fire(Airplane* a, float x, float y, float z);
	~Fire(){};

	void Display();
	void Update(const double& deltaTime);

private:
	double time;
	float sensitivity;
	float apPosition[3];
	float adjust[3];
	Airplane* ap;

	void Draw();
};

