// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>
#include"snake.h"

using namespace std;

void initialize();
void draw();
void Timer(int value);
void TimerLevel(int value);
void move(int key, int x, int y);

snake game;
int sec = 1000;
bool lose = false;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Snake Game");

	initialize();

	glutDisplayFunc(draw);
	glutSpecialFunc(move);
	glutTimerFunc(sec, Timer, 0);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 10, 0, 10);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (!lose)
	{
		glColor3f(0, 0.5, 0);
	}
	else
	{
		glColor3f(0, 0, 0);
	}

	int x, y;

	for (int i = 0; i < game.tail.size(); i++)
	{
		x = (game.tail[i]) % 10;
		y = (game.tail[i]) / 10;

		glBegin(GL_QUADS);
		glVertex2i(x, y);
		glVertex2i(x, y + 1);
		glVertex2i(x + 1, y + 1);
		glVertex2i(x + 1, y);
		glEnd();
	}

	glColor3f(0.5, 0, 0);

	x = (game.egg) % 10;
	y = (game.egg) / 10;

	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x, y + 1);
	glVertex2i(x + 1, y + 1);
	glVertex2i(x + 1, y);
	glEnd();

	glutPostRedisplay();
	glFlush();
}

void move(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		game.move = 10;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		game.move = -10;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		game.move = 1;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		game.move = -1;
	}
}

void Timer(int value)
{
	if (lose)
	{
		game.tail.erase(game.tail.begin(), game.tail.end());
		game.tail.push_back(54);
		game.add();
		lose = false;
		sec = 1000;
	}

	if (game.move == 1 && game.tail.back() % 10 == 9)
	{
		lose = true;
	}
	else if (game.move == -1 && game.tail.back() % 10 == 0)
	{
		lose = true;
	}
	else if(game.tail.back() + game.move > 100)
	{
		lose = true;
	}
	else if (game.tail.back() + game.move < 0)
	{
		lose = true;
	}
	else if (game.tail.back() + game.move == game.egg)
	{
		game.tail.push_back(game.tail.back() + game.move);
		game.add();
		glutTimerFunc(0, TimerLevel, 0);
	}
	else
	{
		game.tail.push_back(game.tail.back() + game.move);
		game.tail.erase(game.tail.begin());
	}

	if (game.check() == 0)
	{
		lose = true;
	}

	glutTimerFunc(sec, Timer, 0);
}

void TimerLevel(int value)
{
	if (sec > 500)
	{
		sec = sec - 100;
	}
}
