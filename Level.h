#pragma once
#include "stdafx.h"

//Класс "Уровень
class Level{
private:
	char *infoMessage;	//Сообщение, которое сообщает сколько спичек переложить на данном уровне
	int number;				//Номер уровня

public:
	Level();
	Level(int num, char *s);
	char* getInfoMessage();
	int getNumber();
};

Level::Level(int num, char *s){
	this->number = num;
	this->infoMessage = s;
}

char* Level::getInfoMessage(){
	return this->infoMessage;
}

int Level::getNumber(){
	return this->number;
}