#pragma once

#include "../Framework/Engine/Scene.h"
#include "Airplane.h"
#include "Cloud.h"
#include "Mountain.h"
#include "Sun.h"
#include "Fire.h"
#include "SunTexture.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
	void Initialise();
	void Projection();
};