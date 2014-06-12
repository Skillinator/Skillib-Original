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


WindowSystem::WindowSystem(){
	std::string str = "SkilLib test";
	title = new char[str.length() + 1];
	strcpy(title, str.c_str());

	width = 512;
	height = 512;
	id = SYSTEM_WINDOW;
	initializeWindow();
}

WindowSystem::WindowSystem(int gwidth, int gheight, char* gtitle){
	title = gtitle;
	width = gwidth;
	height = gheight;
	id = SYSTEM_WINDOW;
	initializeWindow();
}

void WindowSystem::update(int delta){
    glViewport(0,0,width,height);
    glClearColor(0.0f, 0.0f, 1.0f, 0.5f);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glFlush();
    glTranslatef(0.0f,0.0f,-5.0f);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glfwPollEvents();
    glfwSwapBuffers(window);
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) || glfwWindowShouldClose(window)){
    	closeWindow();
	}
}


void WindowSystem::initializeWindow(){
	glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    
    if(!window){
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void WindowSystem::closeWindow(){
	glfwDestroyWindow(window);
    glfwTerminate();
    shutDownEverything();
}