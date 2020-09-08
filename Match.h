#include "stdafx.h"

// ласс спичка
class Match{
private:
	//’раним координаты и ширину и высоту
	int x;
	int y;
	int width;
	int height;
	bool full;
public:
	Match(){}	// онструктор по умолчанию
	Match(int X, int Y, int W, int H);	//конструктор с параметрами
	void setCoord(int X, int Y);		//задаем координаты
	void setRect(int W, int H);		//задаем размеры
	int getWidth() { return width;}
	int getHeight() { return height;}
	int getX() { return x;}
	int getY() { return y;}
	void setFull(bool flag){ full = flag;}
	bool isFull(){ return full;}
};



Match::Match(int X, int Y, int W, int H){
	x = X;
	y = Y;
	width = W;
	height = H;
}

void Match::setCoord(int X, int Y){
	x = X;
	y = Y;
}

void Match::setRect(int W, int H){
	width = W;
	height = H;
}