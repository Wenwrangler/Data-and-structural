#include"head.h"
IMAGE t1, t2;
queue<MyStruct> q;
MyStruct temp;
int x = 100, y = 25;
void GUImain() {
	initgraph(1024 + 300, 750);//初始化窗口
	loadimage(&t1, _T("timg.png"));//读取图片
	setlinecolor(LIGHTGRAY);
	ifstream open("excel.txt");
	if (open.fail()) {
		cout << "文件打开失败！";
		return;
	}
	for (int i = 0; i < 20; i++) {
		open >> temp.name >> temp.num >> temp.CourseNumber >> temp.results;
		q.push(temp);
	}
	GUIcycle();
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (m.x >= 1024 && m.x <= 1324 && m.y >= 500 && m.y <= 750) {
				cleardevice();
				GUIcycle();
			}
			else if (m.x >= 1024 && m.x <= 1324 && m.y >= 0 && m.y <= 220) {

			}
		default:
			break;
		}
	}
	_getch();
	return;
}
void GUIcycle() {
	setfillstyle(BS_DIBPATTERN, NULL, &t1);//填充图片 **这里有问题
	setbkcolor(WHITE);
	fillrectangle(1024, 0, 1324, 750);
	for (int j = 1; j <= 15; j++) {
		if (q.empty()) {
			strcmp(temp.CourseNumber, " ");
			strcmp(temp.name, " ");
			strcmp(temp.num, " ");
			strcmp(temp.results, " ");
		}
		else {
			temp = q.front();
			q.pop();
		}
		for (int i = 1; i < 5; i++) {
			fillrectangle(256 * i - 256, j * 50 - 50, 256 * i, 50 * j);
			setfillcolor(WHITE);
			setlinecolor(LIGHTGRAY);
			settextcolor(BLACK);
			if (j == 1) {
				switch (i) {
				case 1:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), "姓名");
					break;
				case 2:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), "学号");
					break;
				case 3:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), "课程编号");
					break;
				case 4:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), "成绩");
					break;
				}
			}
			else {
				switch (i) {
				case 1:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), temp.name);
					break;
				case 2:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), temp.num);
					break;
				case 3:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), temp.CourseNumber);
					break;
				case 4:
					outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), temp.results);
					break;
				}
			}

		}
	}
}