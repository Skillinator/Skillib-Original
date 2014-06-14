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

Message::Message(){
	fromType = 0;
	messageType = MESSAGE_UNDEFINED;
}