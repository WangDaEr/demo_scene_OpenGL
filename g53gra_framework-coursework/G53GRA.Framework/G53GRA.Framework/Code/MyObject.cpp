#include "MyObject.h"
#include <fstream>
#include <iostream>
using namespace std;


MyObject::MyObject(string fileName)
{
	loadObject(fileName);
}

//basic function for every object in the scene using .obj file
//read the file line by line and change the form of input from text to desirable type such as float for vertex
//store inputs in different vector based on different purpose, such as vertex vector for coordinates of each vertex.
//using a vector to record index of each vertex
void MyObject::loadObject(string fileName)
{
	string line;
	fstream f;
	f.open(fileName, ios::in);

	while (!f.eof())
	{
		getline(f, line);
		vector<string>parameters;
		string endMark = " ";
		string answer = "";

		line = line.append(endMark);
		for (int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			if (c != ' ')
			{
				answer += c;
			}
			else
			{
				parameters.push_back(answer);
				answer = "";
			}
		}
		if (parameters.size() != 4 && parameters[0] != "usemtl")
		{
			continue;
		}
		if (parameters[0] == "v")
		{
			vector<GLfloat>point;
			for (int i = 1; i < 4; i++)
			{
				GLfloat xyz = atof(parameters[i].c_str());
				point.push_back(xyz);
			}
			vertexSets.push_back(point);
		}
		else if (parameters[0] == "vn")
		{
			vector<GLfloat> Npoint;
			for (int i = 1; i < 4; i++)
			{
				GLfloat Nxyz = atof(parameters[i].c_str());
				Npoint.push_back(Nxyz);
			}
			NormalSets.push_back(Npoint);
		}
		else if (parameters[0] == "usemtl")
		{
			meterialNumber[meterialNumber[0] + 1] = meterialNumber[meterialNumber[0]];
			meterialNumber[0] += 1;
		}
		else if (parameters[0] == "f")
		{
			vector<int>vertexIndexSets;
			vector<int>vertexNormalIndexSets;
			for (int i = 1; i < 4; i++)
			{
				string x = parameters[i];
				string vIndex = "";
				string vNormalIndex = "";;
				int n = 0;
				for (int j = 0; j < x.length(); j++)
				{
					char c = x[j];
					if (c != '/')
					{
						if (n == 0)
						{
							vIndex += c;
						}
						else if (n == 2)
						{
							vNormalIndex += c;
						}
					}
					else
					{
						n += 1;
					}
				}
				int vIndexNum = atof(vIndex.c_str()) - 1;
				int vNormalIndexNum = atof(vNormalIndex.c_str()) - 1;
				vertexIndexSets.push_back(vIndexNum);
				vertexNormalIndexSets.push_back(vNormalIndexNum);
			}
			faceVectorSets.push_back(vertexIndexSets);
			faceNormalSets.push_back(vertexNormalIndexSets);
			meterialNumber[meterialNumber[0]] += 1;
		}
	}
	printf("%d, %d", meterialNumber[0], meterialNumber[meterialNumber[0]]);
	f.close();
}
