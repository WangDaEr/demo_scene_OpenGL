#include "SunTexture.h"
#include "VectorMath.h"


SunTexture::SunTexture(string fileName, Camera* c)
{
	camera = c;
	textureID = Scene::GetTexture(fileName);
}

//reset textured surface position and start drawing surface
void SunTexture::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);


	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, 1.f, 0.f);
	glRotatef(rotation[2], 0.0f, 0.f, 1.f);
	updateCameraPosition();
	changeDirection(cameraPosition[0], cameraPosition[1], cameraPosition[2], pos[0], pos[1], pos[2]);
	Draw();
	glPopAttrib();
	glPopMatrix();
}

//update when camera is moved or rotated
void SunTexture::updateCameraPosition()
{
	camera->GetEyePosition(cameraPosition[0], cameraPosition[1], cameraPosition[2]);
}

//create a surface and bind texture
void SunTexture::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glDisable(GL_COLOR_MATERIAL);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(25.0f, 90.0f, 250.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(25.0f, 140.0f, 250.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-25.0f, 140.0f, 250.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-25.0f, 90.0f, 250.0f);
	glEnd();
}

//make the surface always look to the camera's position
void SunTexture::changeDirection(
	float camX, float camY, float camZ,
	float objPosX, float objPosY, float objPosZ) {

	float lookAt[3], objToCamProj[3], objToCam[3], upAux[3];
	float angleCosine;

	objToCamProj[0] = camX - objPosX;
	objToCamProj[1] = 0;
	objToCamProj[2] = camZ - objPosZ;

	lookAt[0] = 0;
	lookAt[1] = 0;
	lookAt[2] = 1;
	norm(objToCamProj);
	cross(lookAt, objToCamProj, upAux);
	dot(lookAt, objToCamProj, angleCosine);
	if ((angleCosine < 0.99990) && (angleCosine > -0.9999))
	{
        glRotatef(acos(angleCosine) * 180 / 3.14, upAux[0], upAux[1], upAux[2]);
	}

	objToCam[0] = camX - objPosX;
	objToCam[1] = camY - objPosY;
	objToCam[2] = camZ - objPosZ;

	norm(objToCam);
	dot(objToCamProj, objToCam, angleCosine);

	if ((angleCosine < 0.99990) && (angleCosine > -0.9999))
	{
		if (objToCam[1] < 0)
		{
			glRotatef(acos(angleCosine) * 180 / 3.14, 1, 0, 0);
		}
			
		else
		{
			glRotatef(acos(angleCosine) * 180 / 3.14, -1, 0, 0);
		}
			
	}
		

}
