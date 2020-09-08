#include "stdafx.h"

//����� ������
class Match{
private:
	//������ ���������� � ������ � ������
	int x;
	int y;
	int width;
	int height;
	bool full;
public:
	Match(){}	//����������� �� ���������
	Match(int X, int Y, int W, int H);	//����������� � �����������
	void setCoord(int X, int Y);		//������ ����������
	void setRect(int W, int H);		//������ �������
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