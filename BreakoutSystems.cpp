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

RenderSystem::RenderSystem(){
	id = SYSTEM_RENDER;
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