#include "Airplane.h"



Airplane::Airplane(string fileName):
	MyObject(fileName)
{
	sensitivity = 4.0f;
	isRight = 0;
	isLeft = 0;
	isForward = 0;
	isBackward = 0;
	reachTheBoundary = false;
}

//reset airplane position and start drawing object based on data retrived from .obj file
void Airplane::Display()
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
};

//provide animationbased on input from user
void Airplane::Update(const double& deltaTime)
{
	time += deltaTime;

	if (isLeft && rotation[2] >= -60.0f)
	{
		rotation[2] -= 10 * sensitivity * deltaTime;
		pos[0] -= scale[0] * sensitivity * static_cast<float>(deltaTime);
	}
	if (isRight && rotation[2] <= 60.0f)
	{
		rotation[2] += 10 * sensitivity * deltaTime;
		pos[0] += scale[0] * sensitivity * static_cast<float>(deltaTime);
	}
	if (isForward && pos[2] >= 400.0f)
	{
		pos[2] -= scale[0] * sensitivity * static_cast<float>(deltaTime);
	}
	if (isBackward && pos[2] <= 560.0f)
	{
		pos[2] += scale[0] * sensitivity * static_cast<float>(deltaTime);
	}

	isLeft = 0;
	isRight = 0;
	isForward = 0;
	isBackward = 0;
};

//produce instructions on different animation based on which key is pressed by user.
//four different state indicate different direction of animation which are moving left, right, forward and backward
void Airplane::HandleKey(unsigned char key, int state, int x, int y)
{
	if (key == 'j' && state)
	{
		isLeft = state;
	}
	else if (key == 'l' && state)
	{
		isRight = state;
	}
	else if (key == 'i' && state)
	{
		isForward = state;
	}
	else if (key == 'k' && state)
	{
		isBackward = state;
	}
}

//create object based on retrived .obj file and assign different color to corresponding part on the plane
void Airplane::Draw()
{
	int currentMaterial = 1;

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < faceVectorSets.size(); i++)
	{
		if (i == meterialNumber[currentMaterial])
		{
			currentMaterial += 1;
		}

		switch (currentMaterial)
		{
		case 1:
			glColor3ub(100, 100, 100);
			break;
		case 2:
			glColor3ub(30, 30, 30);
			break;
		case 3:
			glColor3ub(220, 220, 220);
			break;
		case 4:
			glColor3ub(20, 20, 20);
			break;
		case 5:
			glColor3ub(150, 150, 150);
			break;
		}
		
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
