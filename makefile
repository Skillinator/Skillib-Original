all:
	g++ main.cpp Engine.cpp WindowSystem.cpp TimekeeperSystem.cpp DeltaMessage.cpp Entity.cpp libSOIL.a -lGLEW -lglfw -lGL -lGLU -lgdiplus -o skilLib

