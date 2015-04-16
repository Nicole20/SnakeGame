#pragma once
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

class snake
{
public:
	snake();

	int egg, move;
	vector<int> tail;

	void add();
	bool check();

	~snake();
};
