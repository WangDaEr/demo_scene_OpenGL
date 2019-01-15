#pragma once
#include "MyObject.h"
#include "Animation.h"
#include "Input.h"
#include "Scene.h"

class Airplane:
	public MyObject,
	public Animation,
	public Input
{
public:
	Airplane(string fileName);
	~Airplane(){};

	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);

private:
	double time;
	float sensitivity;
	int isRight;
	int isLeft;
	int isForward;
	int isBackward;
	bool reachTheBoundary;

	void Draw();
};

