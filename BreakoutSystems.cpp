#include <iostream>
#include <ctime>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include "SOIL.h"
#include "skilLib.h"
#include "systems.h"
#include "messages.h"
#include "components.h"

extern Engine *theEngine;

RenderSystem::RenderSystem(){
	id = SYSTEM_RENDER;
	handler = new MessageHandler();
}

void RenderSystem::update(float delta){
	for(int z = 0; z < numEntities(); z++){
		Entity *tmp = entityAt(z);
		if(tmp->hasComponent(COMPONENT_POSITION) && tmp->hasComponent(COMPONENT_DIMENSIONS) && tmp->hasComponent(COMPONENT_COLOR)){
			Color *color = static_cast<Color*>(tmp->getComponent(COMPONENT_COLOR));
			Position *pos = static_cast<Position*>(tmp->getComponent(COMPONENT_POSITION));
			Dimensions *dim = static_cast<Dimensions*>(tmp->getComponent(COMPONENT_DIMENSIONS));

			int x = pos->getX();
			int y = pos->getY();

			int w = dim->getWidth();
			int h = dim->getHeight();

			glColor3f(color->getRed(), color->getGreen(), color->getBlue());
			
			glBegin(GL_QUADS);
				glVertex2i(x,y);
				glVertex2i(x,y+h);
				glVertex2i(x+w,y+h);
				glVertex2i(x+w,y);
			glEnd();

		}
	}
}

MovementSystem::MovementSystem(){
	id = SYSTEM_MOVEMENT;
	handler = new MessageHandler();
}

void MovementSystem::update(float delta){
	for(int z = 0; z < numEntities(); z++){
		Entity *tmp = entityAt(z);
		if(tmp->hasComponent(COMPONENT_POSITION) && tmp->hasComponent(COMPONENT_VELOCITY)){
			Position *pos = static_cast<Position*>(tmp->getComponent(COMPONENT_POSITION));
			Velocity *vel = static_cast<Velocity*>(tmp->getComponent(COMPONENT_VELOCITY));

			float x = pos->getX();
			float y = pos->getY();

			float changex = delta * vel->getSpeed() * cos(vel->getDir());
			float changey = delta * vel->getSpeed() * sin(vel->getDir());
			pos->setX(x+changex);
			pos->setY(y+changey);
		}
	}
}

bool CollisionSystem::inside(float pointx, float pointy, float boxx, float boxy, int w, int h){
	return pointx >= boxx && pointx <= boxx+w && pointy >= boxy && pointy <= boxy+h;
}

CollisionSystem::CollisionSystem(){
	id = SYSTEM_COLLISION;
	handler = new MessageHandler();
}

void CollisionSystem::update(float delta){
	for(int z = 0; z < numEntities(); z++){
		Entity *tmp = entityAt(z);
		if(tmp->hasComponent(COMPONENT_CHECKCOLLISIONS) && tmp->hasComponent(COMPONENT_POSITION) && tmp->hasComponent(COMPONENT_DIMENSIONS)){
			Position *pos = static_cast<Position*>(tmp->getComponent(COMPONENT_POSITION));
			Dimensions *dim = static_cast<Dimensions*>(tmp->getComponent(COMPONENT_DIMENSIONS));

			int left = pos->getX();
			int right = pos->getX() + dim->getWidth();

			int top = pos->getY() + dim->getHeight();
			int bottom = pos->getY();


			for(int y = 0; y < numEntities(); y++){
				if(z != y){
					Entity *tmp2 = entityAt(y);
					if(tmp2->hasComponent(COMPONENT_POSITION) && tmp2->hasComponent(COMPONENT_DIMENSIONS)){
						Position *pos2 = static_cast<Position*>(tmp2->getComponent(COMPONENT_POSITION));
						Dimensions *dim2 = static_cast<Dimensions*>(tmp2->getComponent(COMPONENT_DIMENSIONS));

						int boxx = pos2->getX();
						int w = dim2->getWidth();

						int h = dim2->getHeight();
						int boxy = pos2->getY();

						bool topLeft, topRight, bottomLeft, bottomRight;

						topLeft = inside(left, top, boxx, boxy, w, h);
						bottomLeft = inside(left, bottom, boxx, boxy, w, h);
						topRight = inside(right, top, boxx, boxy, w, h);
						bottomRight = inside(right, bottom, boxx, boxy, w, h);

						if(topLeft && topRight){
							tmp2->message(new HitMessage(DIRECTION_DOWN));
							tmp->message(new HitMessage(DIRECTION_UP));
						}else if(topLeft && bottomLeft){
							tmp2->message(new HitMessage(DIRECTION_RIGHT));
							tmp->message(new HitMessage(DIRECTION_LEFT));
						}else if(bottomLeft && bottomRight){
							tmp2->message(new HitMessage(DIRECTION_UP));
							tmp->message(new HitMessage(DIRECTION_DOWN));
						}else if(topRight && bottomRight){
							tmp2->message(new HitMessage(DIRECTION_LEFT));
							tmp->message(new HitMessage(DIRECTION_RIGHT));
						}

					}
				}
			}
		}
	}
}

GarbageCollectSystem::GarbageCollectSystem(){
	handler = new GarbageHandler();
	id = SYSTEM_GARBAGECOLLECT;
}

void GarbageCollectSystem::update(float delta){
	for(int x = 0; x < removeList.size(); x++){
		for(int y = 0; y < theEngine->numEntities(); y++){
			if(theEngine->getEntity(y) == removeList.at(x)){
				theEngine->removeEntity(y);
			}
		}
	}
	removeList.clear();
}