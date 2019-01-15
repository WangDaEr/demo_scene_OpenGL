#include "Sun.h"


Sun::Sun()
{
	static GLfloat ambient[] = { 0.15f, 0.15f, 0.1f, 1.0f };
	static GLfloat diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	static GLfloat specular[] = { 0.7f, 0.7f, 0.7f, 1.0f };

	_ambient = ambient;
	_diffuse = diffuse;
	_specular = specular;
}

//reset light position and set its properties
void Sun::Display()
{
	
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glPopMatrix();
	glPopAttrib();
	
	setLight();
}

//set properties of lights
void Sun::setLight()
{
	float lightDirection[] = { 0.0f, -1.0f, 1.0f };
	GLfloat lPosition[4] = { 0.0F, 200.0F, 300.0F, 1.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, _ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, _diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, _specular);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0F);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, static_cast<GLfloat*>(lightDirection));
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, static_cast<GLfloat>(90.0F));
	glLightfv(GL_LIGHT1, GL_POSITION, lPosition);
	glEnable(GL_LIGHT1);
}