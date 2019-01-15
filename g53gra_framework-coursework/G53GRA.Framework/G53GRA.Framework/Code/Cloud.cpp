#include "Cloud.h"

Cloud::Cloud(string fileName):
	MyObject(fileName)
{
	sensitivity = 4.0f;
}

//reset cloud position and start drawing object based on data retrived from .obj file
void Cloud::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);


	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, 1.f, 0.f);
	glRotatef(rotation[2], 0.0f, 0.f, 1.f);

	Draw();
	glPopAttrib();
	glPopMatrix();
}

//moving cloud backwards, recreate it at front of scene when it reach the boundary
void Cloud::Update(const double& deltaTime)
{
	time += deltaTime;
	if (pos[2] <= 570.0f)
	{
        pos[2] += 30 * sensitivity * static_cast<float>(deltaTime);
	}
	else
	{
		pos[2] = 0.0f;
	}
	
};

//create object based on retrived .obj file
void Cloud::Draw()
{
	int currentMaterial = 1;

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glBegin(GL_TRIANGLES);
	glColor3ub(240, 240, 240);
	for (int i = 0; i < faceVectorSets.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int vertexIndex = faceVectorSets[i][j];
			int normalIndex = faceNormalSets[i][j];
			glNormal3f(NormalSets[normalIndex][0], NormalSets[normalIndex][1], NormalSets[normalIndex][2]);
			glVertex3f(vertexSets[vertexIndex][0], vertexSets[vertexIndex][1], vertexSets[vertexIndex][2]);
		}
	}
	glEnd();
}
