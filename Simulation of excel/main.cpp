#include<iostream>
#include"head.h"
using namespace std;
int main() {
	initgraph(1024, 768);
	setbkcolor(YELLOW);
	setfillcolor(YELLOW);
	setlinecolor(BLACK);
	int x = 100, y = 25;
	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j < 1000; j++) {
			fillrectangle(256*i-256, j*50-50, 256 * i, 50*j);
			setfillcolor(YELLOW);
			setlinecolor(BLACK);
			settextcolor(RED);
			char s[] = "Hello World";
			outtextxy(x+(i*256-256), y+(j*50-50), s);
			
		}
		
	}
	
	_getch();
	cout << "1";
	return 0;
}