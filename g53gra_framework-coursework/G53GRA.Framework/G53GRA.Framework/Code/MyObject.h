#pragma once

#include "DisplayableObject.h"
#include <string>
#include <vector>
using namespace std;


class MyObject:
	public DisplayableObject
{
public:
	MyObject(string fileName);
	~MyObject(){};

	void loadObject(string fileName);

	vector<vector<GLfloat>>vertexSets; //vector for coordinates of each vertex
	vector<vector<int>>faceVectorSets; //vector for index of each vertex used in a a face
	vector<vector<GLfloat>>NormalSets; //vector for coordinates of normal of each vertex
	vector<vector<int>>faceNormalSets; //vector for index of normal each vertex used in a a face

	int meterialNumber[15]; //used color, [0] indicates how many color are used, each of rest inedx stores the index of last face used such color
};

