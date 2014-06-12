all:
	g++ main.cpp Engine.cpp WindowSystem.cpp TimekeeperSystem.cpp Entity.cpp IOManager.cpp SettingsManager.cpp Setting.cpp libSOIL.a -lGLEW -lglfw -lGL -lGLU -lgdiplus -o skilLib

