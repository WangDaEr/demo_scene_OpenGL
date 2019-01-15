#include "Fire.h"

Fire::Fire(Airplane* a, float x, float y, float z)
{
	sensitivity = 400.0f;
	ap = a;
	adjust[0] = x;
	adjust[1] = y;
	adjust[2] = z;
}

//reset fire position and start drawing object as acube
void Fire::Display()
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

//moving the cube very quickly to make it looks like multiple replicas of it
void Fire::Update(const double& deltaTime)
{
	
	time += deltaTime;

	if (time <= 0.05f)
	{
		pos[2] += sensitivity * static_cast<float>(deltaTime);
		scale[0] -= 15 * deltaTime;
		scale[1] -= 15 * deltaTime;
		scale[2] -= 15 * deltaTime;
	}
	else
	{
		pos[0] = ap->position()[0];
		pos[1] = ap->position()[1];
		pos[2] = ap->position()[2] + 60;
		scale[0] = 1.5;
		scale[1] = 1.5;
		scale[2] = 1.5;
		time = 0;
	}

	rotation[0] = ap->orientation()[0];
	rotation[1] = ap->orientation()[1];
	rotation[2] = ap->orientation()[2];
}

void Fire::Draw()
{
	glColor3ub(255, 40, 0);
	glutSolidCube(5);
}