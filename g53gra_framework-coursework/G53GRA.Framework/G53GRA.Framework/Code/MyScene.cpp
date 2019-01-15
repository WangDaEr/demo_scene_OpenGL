#include "MyScene.h"


MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
	Reshape(1200, 800);
}

void MyScene::Initialise()
{
	GetCamera()->Reset();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//create a airplane and add it to the scene
	Airplane* a = new Airplane("./Object/plane2.obj");
	a->size(10);
	a->position(0.0f, -50.0f, 500.0f);
	a->orientation(0.0f, 180.0f, 0.0f);
	AddObjectToScene(a);
    
	//create clouds and add them to the scene
	Cloud* c = new Cloud("./Object/cloud.obj");
	Cloud* c1 = new Cloud("./Object/cloud.obj");
	Cloud* c2 = new Cloud("./Object/cloud.obj");
	Cloud* c3 = new Cloud("./Object/cloud.obj");
	Cloud* c4 = new Cloud("./Object/cloud.obj");
	Cloud* c5 = new Cloud("./Object/cloud.obj");
	c->size(20);
	c1->size(20);
	c2->size(25);
	c3->size(20);
	c4->size(25);
	c5->size(25);
	c->position(180.0f, -100.0f, 20.0f);
	c1->position(-20.0f, -120.0f, 30.0f);
	c2->position(-40.0f, 60.0f, -20.0f);
	c3->position(90.0f, -90.0f, 250.0f);
	c4->position(-150.0f, -80.0f, 140.0f);
	c5->position(80.0f, -100.0f, 190.0f);
	c->orientation(45.0f, 90.0f, 220.0f);
	c1->orientation(80.0f, 10.0f, 230.0f);
	c2->orientation(60.0f, 80.0f, 170.0f);
	c3->orientation(50.0f, 120.0f, 160.0f);
	c4->orientation(90.0f, 40.0f, 140.0f);
	c5->orientation(100.0f,70.0f, 120.0f);
    AddObjectToScene(c);
	AddObjectToScene(c1);
	AddObjectToScene(c2);
	AddObjectToScene(c3);
	AddObjectToScene(c4);
	AddObjectToScene(c5);
	
	//create mountains and add them to the scene
	Mountain* m = new Mountain("./Object/mountain.obj");
	Mountain* m1 = new Mountain("./Object/mountain.obj");
	Mountain* m2 = new Mountain("./Object/mountain.obj");
	Mountain* m3 = new Mountain("./Object/mountain.obj");
	Mountain* m4 = new Mountain("./Object/mountain.obj");
	Mountain* m5 = new Mountain("./Object/mountain.obj");
	m->size(30);
	m1->size(30);
	m2->size(30);
	m3->size(30);
	m4->size(30);
	m5->size(30);
	m->position(0.0f, -200.0f, 250.0f);
	m1->position(150.0f, -200.0f, 250.0f);
	m2->position(-150.0f, -200.0f, 250.0f);
	m3->position(0.0f, -200.0f, 400.0f);
	m4->position(150.0f, -200.0f, 400.0f);
	m5->position(-150.0f, -200.0f, 400.0f);
	AddObjectToScene(m);
	AddObjectToScene(m1);
	AddObjectToScene(m2);
	AddObjectToScene(m3);
	AddObjectToScene(m4);
	AddObjectToScene(m5);

	//create light and add it to the scene
	Sun* s = new Sun();
	glDisable(GL_LIGHT0);
	s->size(5);
	AddObjectToScene(s);

	//create fire and add it to the scene
	Fire* f = new Fire(a, 0, 0, 60);
	f->position(a->position()[0], a->position()[1], a->position()[2] + 60);
	f->size(1.5);
	AddObjectToScene(f);

	//create the textured surface and add it to the scene
	SunTexture* st = new SunTexture("./Textures/moon.bmp", GetCamera());
	AddObjectToScene(st);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}