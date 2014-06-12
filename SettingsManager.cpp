#include "skilLib.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>

KeybindManager::KeybindManager(){
	filename = "keybinds.txt";
	io = new IOManager();
	reloadSettings();
}

KeybindManager::KeybindManager(IOManager *getio){
	filename = "keybinds.txt";
	io = getio;
	reloadSettings();
}

KeybindManager::KeybindManager(IOManager *getio, std::string settingFile){
	filename = settingFile;
	io = getio;
	reloadSettings();
}

bool KeybindManager::isDown(std::string name){
	return io->keyDown(getSetting(name));
}

SettingsManager::SettingsManager(){
	filename = "settings.txt";
	io = new IOManager();
	reloadSettings();
}

SettingsManager::SettingsManager(IOManager *getio){
	filename = "settings.txt";
	io = getio;
	reloadSettings();
}

SettingsManager::SettingsManager(IOManager *getio, std::string settingFile){
	filename = settingFile;
	io = getio;
	reloadSettings();
}

double SettingsManager::getSetting(std::string name){
	for(int x = 0; x < settings.size(); x++){
		Setting tmp = settings.at(x);
		if(tmp.getName() == name){
			return tmp.getValue();
		}
	}
	return 0.0;
}

void SettingsManager::setSetting(std::string name, double value){
	for(int x = 0; x < settings.size(); x++){
		Setting tmp = settings.at(x);
		if(tmp.getName() == name){
			settings.at(x).setValue(value);
			break;
		}
	}
}

void SettingsManager::reloadSettings(){
	std::string file = io->getFile(filename);

	bool isfirst = true;
	std::string first = "";
	std::string second = "";

	for(int x = 0; x < file.size(); x++){
		if(file.substr(x, 1) == ":"){
			isfirst = false;
		}else if(file.substr(x, 1) == ";"){
			isfirst = true;
			settings.push_back(Setting(first, atof(second.c_str())));
			first = "";
			second = "";
		}else if(isfirst){
			first += file[x];
		}else{
			second += file[x];
		}
	}
	
}

void SettingsManager::displaySettings(){
	std::cout<<"displaying settings";
	for(int x = 0; x < settings.size(); x++){
		Setting tmp = settings.at(x);
		std::cout<<"("<<tmp.getName()<<", "<<tmp.getValue()<<")\n";
	}
}

void SettingsManager::saveSettings(){
	std::vector<std::string> strings;
	for(int x = 0; x < settings.size(); x++){
		strings.push_back(settings.at(x).saveValue());
	}
	io->writeFile(filename, strings);
}