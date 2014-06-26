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
#include "components.h"

int windowheight = 736;
int windowwidth = 736;
const char* title = "SkilLib 0.1 Testing";
double libVersion = 0.1;


GLFWwindow* window;
/*
void GLFWCALL windowResize(int getwidth, int getheight){
    windowheight=getheight;
    windowwidth=getwidth;
}
*/

Engine *theEngine;

int main(){
    std::cout<<"Loaded SkilLib v" << libVersion << "\n";
    theEngine = new Engine();
    theEngine->addSystem(new WindowSystem());
    theEngine->addSystem(new TimekeeperSystem());
   	theEngine->start();
}

