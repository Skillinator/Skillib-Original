#ifndef _skilLib
#define _skilLib

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <string>

const float SKILLIB_VERSION = 0.1;

class Setting;
class IOManager;
class SettingsManager;
class Engine;

void shutDownEverything();

class Setting{
public:
	Setting();
	Setting(std::string getName);
	Setting(std::string getName, double getValue);
	std::string getName();
	double getValue();
	void setValue(double newVal);
	std::string saveValue();
private:
	std::string name;
	double value;
};


class IOManager{
public:
	IOManager();
	IOManager(GLFWwindow* getwindow);
	GLFWwindow* window;
	bool keyDown(int key);
	std::string getFile(std::string filename);
	void saveFile(std::string filename, std::string contents);
	void writeFile(std::string filename, std::vector<std::string> lines);
};

class SettingsManager{
public:
	SettingsManager();
	SettingsManager(IOManager *getio);
	SettingsManager(IOManager *io, std::string settingFile);
	double getSetting(std::string name);
	void setSetting(std::string, double value);
	void displaySettings();
	void reloadSettings();
	void saveSettings();
protected:
	IOManager* io;
	std::vector<Setting> settings;
	std::string filename;
};

class KeybindManager: SettingsManager{
public:
	KeybindManager();
	KeybindManager(IOManager *getio);
	KeybindManager(IOManager *getio, std::string settingFile);
	bool isDown(std::string name);
	//Scan 1-350 for keybinds
};

class Message{
public:
	Message();
	int fromType;
	int messageType;
};

class Component{
public:
	Component();
	virtual void update(int delta) = 0;
	int getID();
	int id;

};

class Entity{
public:
	Entity();
	bool addComponent(Component* comp);
	bool removeComponent(int compID);
	Component *getComponent(int compID);
	void update(int delta);
protected:
	std::vector<Component*> components;
};

class System{
public:
	System();
	virtual void update(float delta) = 0;
	void setIndex(int ind);
	void engineMessage(Message *m);
	void recieveMessage(Message *m);
	int getID();
	int id;
	int index;
};

class Engine{
public:
	Engine();
	void addEntity(Entity *ent);
	void removeEntity(int entIndex);
	bool addSystem(System *sys);
	bool removeSystem(int sysID);
	void recieveMessage(Message *m);
	void start();
	void update();
	void shutDown();
protected:
	bool running;
	float delta;
	std::vector<Entity*> entities;
	std::vector<System*> systems;
};


#endif
