#pragma once
#include "stdafx.h"

//����� "�������
class Level{
private:
	char *infoMessage;	//���������, ������� �������� ������� ������ ���������� �� ������ ������
	int number;				//����� ������

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