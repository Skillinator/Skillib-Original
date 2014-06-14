#ifndef _skilLibComponents
#define _skilLibComponents

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <string>
#include "skilLib.h"
#include "systems.h"
#include "messages.h"

const int COMPONENT_POSITION = 1;
const int COMPONENT_VELOCITY = 2;
const int COMPONENT_COLOR = 3;
const int COMPONENT_DIMENSIONS = 4;
const int COMPONENT_LIVES = 5;
const int COMPONENT_CHECKCOLLISIONS = 6;
const int COMPONENT_FRAGILITY = 7;

class Position : public Component{
public:
	Position();
	Position(Chefloat gx, float gy);
	float getX();
	float getY();
	void setX(float newx);
	void setY(float newy);
protected:
	float x;
	float y;
};

class Velocity : public Component{
public:
	Velocity();
	Velocity(float r, float s);
	float getDir();
	float getSpeed();
	void setDir(float r);
	void setSpeed (float s);
protected:
	float dir;
	float speed;
};

class Color : public Component{
public:
	Color();
	Color(float r, float g, float b);
	float getRed();
	float getGreen();
	float getBlue();
	void setRed(float r);
	void setGreen(float g);
	void setBlue(float b);
protected:
	float red;
	float green;
	float blue;
};

class Dimensions : public Component{
public:
	Dimensions();
	Dimensions(int w, int h);
	int getHeight();
	int getWidth();
	void setHeight(int h);
	void setWidth(int w);
protected:
	int width;
	int height;
};

class Lives : public Component{
public:
	Lives();
	Lives(int l);
	int getLives();
	void setLives(int l);
protected:
	int lives;
};

class CheckCollisions : public Component{
public:
	CheckCollisions();
};

class Fragility : public Component{
public:
	Fragility();
	Fragility(int f);
	int getFragility();
	void setFragility();
protected:
	int fragility;
};

#endif
