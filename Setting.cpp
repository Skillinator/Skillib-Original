#include "skilLib.h"
#include <string>
#include <iostream>
#include <sstream>

Setting::Setting(){
	name = "UnnamedSetting";
	value = 0.0;
}

Setting::Setting(std::string getName){
	name = getName;
}

Setting::Setting(std::string getName, double getValue){
	name = getName;
	value = getValue;
}

double Setting::getValue(){
	return value;
}

void Setting::setValue(double newVal){
	value = newVal;
}

std::string Setting::getName(){
	return name;
}

std::string Setting::saveValue(){

	std::ostringstream strs;
	strs << value;
	
	return name + ":" + strs.str() + ";";
}