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

const float PI = 3.14149;

TileHandler::TileHandler(){}

void TileHandler::handle(Message *m, Entity *ent){
	if(m->messageType == MESSAGE_HIT){
		GarbageMessage *gm = new GarbageMessage(ent);
		messageSystems(gm);
	}
}

GarbageHandler::GarbageHandler(){}

void GarbageHandler::handle(Message *m, System *sys){
	if(sys->getID() == SYSTEM_GARBAGECOLLECT && m->messageType == MESSAGE_GARBAGE){
		GarbageCollectSystem *gc = static_cast<GarbageCollectSystem*>(sys);
		GarbageMessage *gm = static_cast<GarbageMessage*>(m);

		gc->removeList.push_back(gm->entity);
	}
}

BallHandler::BallHandler(){}

PaddleHandler::PaddleHandler(){}
void PaddleHandler::handle(Message *m, Entity *ent){
	if(m->messageType == MESSAGE_KEY){
		ControlMessage *ctl = static_cast<ControlMessage*>(m);
		Velocity *vel = static_cast<Velocity*>(ent->getComponent(COMPONENT_VELOCITY));
		if(ctl->key == KEY_Z){
			if(ctl->val){
				vel->setSpeed(150.0);
				vel->setDir(3.14159);
			}else if(vel->getDir() > 0){
				vel->setSpeed(0.0);
			}
		}
		if(ctl->key == KEY_X){
			if(ctl->val){
				vel->setSpeed(150.0);
				vel->setDir(0.0);
			}else if(vel->getDir() < 1){
				vel->setSpeed(0.0);
			}
		}

	}else if(m->messageType == MESSAGE_HIT){
		HitMessage *hit = static_cast<HitMessage*>(m);
		Velocity *vel = static_cast<Velocity*>(ent->getComponent(COMPONENT_VELOCITY));
		if(hit->side == DIRECTION_LEFT && vel->getDir() > 1){
			vel->setSpeed(0.0);
		}
		if(hit->side == DIRECTION_RIGHT && vel->getDir() < 1){
			vel->setSpeed(0.0);
		}
	}
}

void BallHandler::handle(Message *m, Entity *ent){
	if(m->messageType == MESSAGE_HIT){
		HitMessage *hit = static_cast<HitMessage*>(m);
		Velocity *vel = static_cast<Velocity*>(ent->getComponent(COMPONENT_VELOCITY));
		float dir;
		dir = vel->getDir();
		if(hit->side == DIRECTION_UP){
			if(dir > PI/2){
				dir = 5*PI/4;
			}else{
				dir = 7*PI/4;
			}
		}

		if(hit->side == DIRECTION_DOWN){
			if(dir > 3*PI/2){
				dir = PI/4;
			}else{
				dir = 3* PI/4;
			}
		}

		if(hit->side == DIRECTION_LEFT){
			if(dir > PI){
				dir = 7*PI/4;
			}else{
				dir = PI/4;
			}
		}

		if(hit->side == DIRECTION_RIGHT){
			if(dir > PI){
				dir = 5*PI/4;
			}else{
				dir = 3* PI/4;
			}
		}

		vel->setDir(dir);

	}

	if(m->messageType == MESSAGE_KEY){
		ControlMessage *ctl = static_cast<ControlMessage*>(m);
		Velocity *vel = static_cast<Velocity*>(ent->getComponent(COMPONENT_VELOCITY));
		BoundTo *bound = static_cast<BoundTo*>(ent->getComponent(COMPONENT_BOUNDTO));
		if(ctl->key == KEY_SPACE && ctl->val){
			if(bound->isBound()){
				bound->setBound(false);
				vel->setDir(3.14159/4);
				vel->setSpeed(175);
			}
		}
	}
}

MessageHandler::MessageHandler(){}

void MessageHandler::handle(Message *m, Entity *ent){
	//Nothing doing
}

void MessageHandler::handle(Message *m, System *sys){
	//Nothing doing
}

Entity::Entity(){
	mh = new MessageHandler();
}

Entity::Entity(MessageHandler *gmh){
	mh = gmh;
}

void Entity::message(Message *msg){
	mh->handle(msg, this);
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

bool Entity::hasComponent(int compID){
	for(int x = 0; x < components.size(); x++){
		if(components.at(x)->getID() == compID){
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
		//components.at(x)->update(delta);
	}
}