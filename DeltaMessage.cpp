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


GarbageMessage::GarbageMessage(){
	entity = new Entity();
	fromType = 0.0;
	messageType = MESSAGE_GARBAGE;
}

GarbageMessage::GarbageMessage(Entity *ent){
	entity = ent;
	fromType = 0.0;
	messageType = MESSAGE_GARBAGE;
}

DeltaMessage::DeltaMessage(){
	delta = 0.0;
	fromType = SYSTEM_TIMEKEEPER;
	messageType = MESSAGE_DELTA;
}

DeltaMessage::DeltaMessage(float d){
	delta = d;
	fromType = SYSTEM_TIMEKEEPER;
	messageType = MESSAGE_DELTA;
}

HitMessage::HitMessage(){
	fromType = SYSTEM_COLLISION;
	messageType = MESSAGE_HIT;
	side = 0;
}

HitMessage::HitMessage(int direction){
	fromType = SYSTEM_COLLISION;
	messageType = MESSAGE_HIT;
	side = direction;
}

Message::Message(){
	fromType = 0;
	messageType = MESSAGE_UNDEFINED;
}