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
    theEngine->addSystem(new MovementSystem());
    theEngine->addSystem(new CollisionSystem());
    theEngine->addSystem(new RenderSystem());
    theEngine->addSystem(new GarbageCollectSystem());

    Entity *leftWall = new Entity();
    leftWall->addComponent(new Position(0, 0));
    leftWall->addComponent(new Color(0.7, 0.7, 0.7));
    leftWall->addComponent(new Dimensions(16, 512));
    leftWall->addComponent(new Fragility(-1));
    theEngine->addEntity(leftWall);
	
	Entity *rightWall = new Entity();
    rightWall->addComponent(new Position(496, 0));
    rightWall->addComponent(new Color(0.7, 0.7, 0.7));
    rightWall->addComponent(new Dimensions(16, 512));
    rightWall->addComponent(new Fragility(-1));
    theEngine->addEntity(rightWall);
    
    Entity *topWall = new Entity();
    topWall->addComponent(new Position(0, 480));
    topWall->addComponent(new Color(0.7, 0.7, 0.7));
    topWall->addComponent(new Dimensions(512, 32));
    topWall->addComponent(new Fragility(-1));
    theEngine->addEntity(topWall);

    Color red = Color(0.7, 0.0, 0.0);
    Color orange = Color(1.0, 0.6, 0.0);
    Color darkorange = Color(0.9, 0.6, 0.2);
    Color yellow = Color(0.9, 0.9, 0.0);
    Color green = Color(0.3, 1.0, 0.0);
    Color blue = Color(0.2, 0.0, 0.9);

	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 436));
	    brick->addComponent(&red);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}
	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 420));
	    brick->addComponent(&orange);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}
	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 404));
	    brick->addComponent(&darkorange);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}
	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 388));
	    brick->addComponent(&yellow);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}
	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 372));
	    brick->addComponent(&green);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}
	for(int y = 0; y < 15; y++){
	    Entity *brick = new Entity(new TileHandler());
	    brick->addComponent(new Position(16 + (32*y), 356));
	    brick->addComponent(&blue);
	    brick->addComponent(new Dimensions(32, 16));
	    brick->addComponent(new Fragility(1));
	    theEngine->addEntity(brick);
	}

	Entity *paddle = new Entity();
	paddle->addComponent(new Position(256-32, 128));
	paddle->addComponent(&red);
	paddle->addComponent(new Dimensions(64, 16));
	//paddle->addComponent(new CheckCollisions());
	paddle->addComponent(new Velocity(0.0, 0.0));
	theEngine->addEntity(paddle);

	Entity *ball = new Entity(new BallHandler());
	ball->addComponent(new Position(256-8, 148));
	ball->addComponent(new Velocity(3.14/4, 100));
	ball->addComponent(&red);
	ball->addComponent(new Dimensions(16, 16));
	ball->addComponent(new Lives(3));
	ball->addComponent(new CheckCollisions());
	ball->addComponent(new Bounce());
	theEngine->addEntity(ball);

   	theEngine->start();
}

