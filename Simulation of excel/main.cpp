#include<iostream>
#include"head.h"
using namespace std;
int main() {
	MOUSEMSG M;
	initgraph(1024+300, 750);//初始化窗口


	fillcircle(1174, 110, 100);//窗口1
	fillcircle(1174, 350, 100);//窗口2
	fillcircle(1174, 600, 100);//窗口3
	IMAGE t1, t2;
	loadimage(&t1, _T("timg上.jpg"));//读取图片
	setfillstyle(BS_DIBPATTERN, NULL, &t1);//填充图片 **这里有问题


	setbkcolor(WHITE);
	setfillcolor(WHITE);
	setlinecolor(LIGHTGRAY);
	int x = 100, y = 25;
	char s[] = "Hello World";
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 100; j++) {
			fillrectangle(256*i-256, j*50-50, 256 * i, 50*j);
			setfillcolor(WHITE);
			setlinecolor(LIGHTGRAY);
			settextcolor(BLACK);
			outtextxy(x+(i*256-256), y+(j*50-50), s);
		}
	}
	_getch();
	
	cout << "1";
	return 0;
}