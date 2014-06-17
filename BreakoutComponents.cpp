#include <iostream>
#include <ctime>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h> 
#include <string.h>
#include <vector>
#include "SOIL.h"
#include "skilLib.h"
#include "systems.h"
#include "messages.h"
#include "components.h"

Position::Position(){
	x = 0.0;
	y = 0.0;
	id = COMPONENT_POSITION;
}

Position::Position(float gx, float gy){
	x = gx;
	y = gy;
	id = COMPONENT_POSITION;
}

float Position::getX(){ return x; }
float Position::getY(){ return y; }
void Position::setX(float gx){ x = gx; }
void Position::setY(float gy){ y = gy; }

Velocity::Velocity(){
	dir = 0.0;
	speed = 0.0;
	id = COMPONENT_VELOCITY;
}

Velocity::Velocity(float r, float s){
	dir = r;
	speed = s;
	id = COMPONENT_VELOCITY;
}

float Velocity::getDir(){ return dir; }
float Velocity::getSpeed(){ return speed; }
void Velocity::setDir(float r){ dir = r; }
void Velocity::setSpeed(float s){ speed = s; }

Color::Color(){
	red = blue = green = 0.0;
	id = COMPONENT_COLOR;
}

Color::Color(float r, float g, float b){
	red = r;
	green = g;
	blue = b;
	id = COMPONENT_COLOR;
}

float Color::getRed(){ return red; }
float Color::getGreen(){ return green; }
float Color::getBlue(){ return blue; }
void Color::setRed(float r){ red = r; }
void Color::setGreen(float g){ green = g; }
void Color::setBlue(float b){ blue = b; }

Dimensions::Dimensions(){
	width = 16;
	height = 16;
	id = COMPONENT_DIMENSIONS;
}

Dimensions::Dimensions(int w, int h){
	width = w;
	height = h;
	id = COMPONENT_DIMENSIONS;
}

int Dimensions::getWidth(){ return width; }
int Dimensions::getHeight(){ return height; }
void Dimensions::setWidth(int w){ width = w; }
void Dimensions::setHeight(int h){ height = h; }


Lives::Lives(){
	lives = 1;
	id = COMPONENT_LIVES;
}

Lives::Lives(int l){
	lives = l;
	id = COMPONENT_LIVES;
}

int Lives::getLives(){ return lives; }
void Lives::setLives(int l){ lives = l; }

CheckCollisions::CheckCollisions(){
	id = COMPONENT_CHECKCOLLISIONS;
}

Fragility::Fragility(){
	id = COMPONENT_FRAGILITY;
	fragility = 1;
}

Fragility::Fragility(int f){
	fragility = f;
	id = COMPONENT_FRAGILITY;
}

Bounce::Bounce(){
	id = COMPONENT_BOUNCE;
}