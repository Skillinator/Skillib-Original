#ifndef _skilLibMessaging
#define _skilLibMessaging

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <string>
#include "skilLib.h"
#include "systems.h"

const int DIRECTION_UP = 1;
const int DIRECTION_DOWN = 2;
const int DIRECTION_LEFT = 3;
const int DIRECTION_RIGHT = 4;


const int MESSAGE_UNDEFINED = -1;
const int MESSAGE_DELTA = 1;
const int MESSAGE_HIT = 2;
const int MESSAGE_GARBAGE = 3;

class DefaultHandler:public MessageHandler{
public:
	DefaultHandler();
	void handle(Message *m, Entity *ent);
};

class TileHandler:public MessageHandler{
public:
	TileHandler();
	void handle(Message *m, Entity *ent);
};

class GarbageHandler:public MessageHandler{
public:
	GarbageHandler();
	void handle(Message *m, System *sys);
};

class BallHandler:public MessageHandler{
public:
	BallHandler();
	void handle(Message *m, Entity *ent);
};

class DeltaMessage : public Message{
public:
	DeltaMessage();
	DeltaMessage(float d);
	float delta;
};

class GarbageMessage : public Message{
public:
	GarbageMessage();
	GarbageMessage(Entity *ent);
	Entity *entity;
};

class HitMessage : public Message{
public:
	HitMessage();
	HitMessage(int direction);
	int side;
};

#endif
