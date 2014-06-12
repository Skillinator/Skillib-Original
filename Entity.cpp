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

Entity::Entity(){

}

bool Entity::addComponent(Component *comp){
	for(int x = 0; x < components.size(); x++){
		if(components.at(x)->getID() == comp->getID()){
			return false;
		}
	}

	components.push_back(comp);
	return true;
}


bool Entity::removeComponent(int compID){
	for(int x = 0; x < components.size(); x++){
		if(components.at(x)->getID() == compID){
			components.erase(components.begin()+x);
			return true;
		}
	}
	return false;
}

Component *Entity::getComponent(int compID){
	for(int x = 0; x < components.size(); x++){
		if(components.at(x)->getID() == compID){
			return components.at(x);
		}
	}
}

void Entity::update(int delta){
	for(int x = 0; x < components.size(); x++){
		components.at(x)->update(delta);
	}
}