#pragma once
#include "DisplayableObject.h"
#include "Camera.h"
#include <string>

using namespace std;

class SunTexture :
	public DisplayableObject
{
public:
	SunTexture(string fileName, Camera* c);
	~SunTexture(){};

	void Display();
	void Update(const double& deltaTime);

private:
	float cameraPosition[3];
	int textureID;
	Camera* camera;

	void Draw();
	void updateCameraPosition();
	void changeDirection(float camX, float camY, float camZ,
		float objPosX, float objPosY, float objPosZ); //using "Billboard" to create fake 3D texture and rotate the surface to looking at camera
};

