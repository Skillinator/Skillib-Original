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
#include "messages.h"

extern Engine *theEngine;

Component::Component(){

}
Component::~Component(){

}
int Component::getID(){
	return id;
}

System::System(){
	handler = new MessageHandler();
}

void System::engineMessage(Message *m){
	theEngine->recieveMessage(m);
}

Entity *System::entityAt(int index){
	return theEngine->getEntity(index);
}

int System::numEntities(){
	return theEngine->numEntities();
}

void System::recieveMessage(Message *m){ /* default shouldn't need to do much I think */ }

void System::setIndex(int ind){
	index = ind;
}

int System::getID(){
	return id;
}

void System::message(Message* msg){
	handler->handle(msg, this);
}

Engine::Engine(){
	delta = 0.0;
}

Entity *Engine::getEntity(int index){
	return entities.at(index);
}

int Engine::numEntities(){
	return entities.size();
}

void Engine::addEntity(Entity *ent){
	entities.push_back(ent);
}

void Engine::removeEntity(int entIndex){
	if(entIndex < entities.size()){
		entities.erase(entities.begin()+entIndex);
	}
}

bool Engine::addSystem(System *sys){
	for(int x = 0; x < systems.size(); x++){
		if(systems.at(x)->getID() == sys->getID()){
			return false;
		}
	}

	systems.push_back(sys);
	return true;
}

bool Engine::removeSystem(int sysID){
	for(int x = 0; x < systems.size(); x++){
		if(systems.at(x)->getID() == sysID){
			systems.erase(systems.begin()+x);
			return true;
		}
	}
	return false;
}

void Engine::update(){
	for(int x = 0; x < systems.size(); x++){
		systems.at(x)->update(delta);
	}

	//Position *pos = dynamic_cast<Position*>(entities.at(90)->getComponent(COMPONENT_POSITION));
	//std::cout<<pos->getY()<<"\n";
}

void Engine::start(){
	running = true;
	while(running){
		update();
	}
}

void Engine::shutDown(){
	running = false;
}

void Engine::recieveMessage(Message *m){
	bool found = false;
	switch(m->messageType){
	case MESSAGE_DELTA:	DeltaMessage *deltaMSG = static_cast<DeltaMessage*>(m);
				delta = deltaMSG->delta;
				found = true;
				break;
	}

	if(!found){
		for(int x = 0; x < systems.size(); x++){
			systems.at(x)->message(m);
		}
	}
}

void messageSystems(Message *m){
	theEngine->recieveMessage(m);
}

void shutDownEverything(){
	theEngine->shutDown();
}
