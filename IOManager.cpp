#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <GLFW/glfw3.h>
#include "skilLib.h"

IOManager::IOManager(){

}

IOManager::IOManager(GLFWwindow* getwindow){
	window = getwindow;
}

bool IOManager::keyDown(int key){
	if(glfwGetKey(window, key)){
		return true;
	}
	return false;
}

std::string IOManager::getFile(std::string filename){
	std::string line;
	std::string total;
	char* filechar = new char[filename.size()+1];
	filechar[filename.size()]=0;
	memcpy(filechar, filename.c_str(), filename.size());
	std::ifstream file (filechar);

	if(file.is_open()){
		while(getline(file, line)){
			total += line;
		}
		file.close();
	}
	return total;
}

void IOManager::writeFile(std::string filename, std::vector<std::string> lines){
	std::string line;
	std::string total;
	char* filechar = new char[filename.size()+1];
	filechar[filename.size()]=0;
	memcpy(filechar, filename.c_str(), filename.size());
	std::ofstream file;
	file.open(filechar);
	for(int x = 0; x < lines.size(); x++){
		file<<lines.at(x);
		std::cout<<lines.at(x);
	}
	file.close();
}