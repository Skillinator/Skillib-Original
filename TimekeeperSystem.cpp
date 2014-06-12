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

TimekeeperSystem::TimekeeperSystem(){
	ticks = 0;
	fps = 0;
	delta = 0;
	lastSecond = 0;
	lastTime = 0;
	currentTime = 0;
}

void TimekeeperSystem::update(int delta){
	lastTime = currentTime;
	currentTime = glfwGetTime();
	ticks++;
	if(currentTime - lastSecond > 1){
		fps = ticks;
		lastSecond = currentTime;
		ticks = 0;
		std::cout<<fps<<" FPS\n";
	}

	delta = currentTime - lastTime;
}

int TimekeeperSystem::getFPS(){
	return fps;
}

double TimekeeperSystem::getCurrentTime(){
	return currentTime;
}

int TimekeeperSystem::getDelta(){
	return delta;
}