#ifndef _skilLibSystems
#define _skilLibSystems

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <string>
#include "skilLib.h"

const int SYSTEM_DEBUG = 0;	
const int SYSTEM_WINDOW = 1;
const int SYSTEM_TIMEKEEPER = 2;

class WindowSystem : public System{
public:
	WindowSystem();
	WindowSystem(int gwidth, int gheight, char* gtitle);
	void initializeWindow();
	void closeWindow();
	void update(int delta);
protected:
	GLFWwindow* window;
	int width;
	int height;
	char* title;
};

class TimekeeperSystem : public System{
public:
	TimekeeperSystem();
	void update(int delta);
	double getCurrentTime();
	int getDelta();
	int getFPS();
protected:
	int ticks;
	int fps;
	int delta;
	double lastTime;
	double lastSecond;
	double currentTime;
};

#endif
