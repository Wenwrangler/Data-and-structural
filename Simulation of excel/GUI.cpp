#include"head.h"
IMAGE t1;
vector<MyStruct> Data;
vector<MyStruct>::iterator it;
MyStruct Temp_Struct;
int x = 100, y = 25;
void GUI_Main() {
	initgraph(1024 + 300, 750, SHOWCONSOLE);//初始化窗口
	loadimage(&t1, _T("timg.png"));//读取图片
	setlinecolor(LIGHTGRAY);
	ifstream input("excel.txt");
	if (input.fail()) {
		cout << "文件打开失败！";
		return;
	}
	while (!input.eof()) {
		input >> Temp_Struct.Name >> Temp_Struct.Num >> Temp_Struct.CourseNumber >> Temp_Struct.Results;
		Data.push_back(Temp_Struct);
	}
	it = Data.begin();
	GUI_Show_Information();
	while (1) {
		MOUSEMSG Mouse_Event;
		Mouse_Event = GetMouseMsg();
		switch (Mouse_Event.uMsg){
			case WM_LBUTTONDOWN:
				if (Mouse_Event.x >= 1160 && Mouse_Event.x <= 1324 && Mouse_Event.y >= 585 && Mouse_Event.y <= 750) {//向下翻页 √
					cleardevice();
					GUI_Show_Information();
				}
				else if (Mouse_Event.x >= 1160 && Mouse_Event.x <= 1324 && Mouse_Event.y >= 388 && Mouse_Event.y <= 553) {//退出 √
					closegraph();
					return;
				}
				else if (Mouse_Event.x >= 1160 && Mouse_Event.x <= 1324 && Mouse_Event.y >= 192 && Mouse_Event.y <= 357) {//排序，点击排序后再点击各类排序
					MySort();
				}
				else if (Mouse_Event.x >= 1160 && Mouse_Event.x <= 1324 && Mouse_Event.y >= 0 && Mouse_Event.y <= 164) {//向上翻页 √
					for (int i = 0; i < 28 && it != Data.begin(); i++) {
						it--;
					}
					cleardevice();
					GUI_Show_Information();
				}
				break;
		}
		//FlushMouseMsgBuffer();
	}
	return;
}
void GUI_Show_Information() {  //展示信息
	setfillstyle(BS_DIBPATTERN, NULL, &t1);
	setbkcolor(WHITE);
	fillrectangle(1024, 0, 1324, 750);
	for (int i = 1; i < 5; i++) {
		fillrectangle(256 * i - 256, 0, 256 * i, 50 );
		settextcolor(BLACK);
		switch (i) {
		case 1:
			outtextxy(x + (i * 256 - 256), y , "姓名");
			break;
		case 2:
			outtextxy(x + (i * 256 - 256), y , "学号");
			break;
		case 3:
			outtextxy(x + (i * 256 - 256), y , "课程编号");
			break;
		case 4:
			outtextxy(x + (i * 256 - 256), y , "成绩");
			break;
		}
	}
	for (int j = 2; j <= 15; j++) {
		if (it != Data.end()) {
			Temp_Struct = *it;
			it++;
		}
		else {
			Temp_Struct.CourseNumber = " ";
			Temp_Struct.Name = " ";
			Temp_Struct.Num = " ";
			Temp_Struct.Results = " ";
		}
		for (int i = 1; i < 5; i++) {
			fillrectangle(256 * i - 256, j * 50 - 50, 256 * i, 50 * j);
			setfillcolor(WHITE);
			//setlinecolor(LIGHTGRAY);
			//settextcolor(BLACK);
			switch (i) {
			case 1:
				outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), Temp_Struct.Name.c_str());
				break;
			case 2:
				outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), Temp_Struct.Num.c_str());
				break;
			case 3:
				outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), Temp_Struct.CourseNumber.c_str());
				break;
			case 4:
				outtextxy(x + (i * 256 - 256), y + (j * 50 - 50), Temp_Struct.Results.c_str());
				break;
			}
		}
	}
}
MyStruct M[10000], MS[10000];
void MySort() {
	int Clock_Number;
	MOUSEMSG Mouse_Temp;
	int i = 0;
	for (it = Data.begin(); it != Data.end(); it++) {
		M[i] = *it;
		i++;
	}
	DWORD StartTime, EndTime;
	int idx = 0;
	while (1) {
		Mouse_Temp = GetMouseMsg();
		switch (Mouse_Temp.uMsg){
			case WM_LBUTTONDOWN:
				if (Mouse_Temp.x >= 1032 && Mouse_Temp.x <= 1140) {
					if (Mouse_Temp.y >= 206 && Mouse_Temp.y <= 257) {//姓名优先
						StartTime = GetTickCount();//计时开始
						NameMergeSort(M, MS, 0, i - 1, idx);                
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 283 && Mouse_Temp.y <= 335) {//学号优先
						StartTime = GetTickCount();//计时开始
						NumMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 358 && Mouse_Temp.y <= 412) {//课程编号优先
						StartTime = GetTickCount();//计时开始
						CourseNumberMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 435 && Mouse_Temp.y <= 490) {//成绩优先
						StartTime = GetTickCount();//计时开始
						ResultsMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 510 && Mouse_Temp.y <= 566) {//学号+成绩优先
						StartTime = GetTickCount();//计时开始
						Num_ResultsMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 587 && Mouse_Temp.y <= 642) {//姓名+成绩优先
						StartTime = GetTickCount();//计时开始
						Name_ResultsMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
					else if (Mouse_Temp.y >= 649 && Mouse_Temp.y <= 730) {//姓名+学号+成绩优先
						StartTime = GetTickCount();//计时开始
						Name_Num_ResultsMergeSort(M, MS, 0, i - 1, idx);
						EndTime = GetTickCount();//计时结束
						goto out;
					}
				}
				break;
		}

	}
out:
	Clock_Number = EndTime - StartTime;
	Data.clear();
	for (int j = 0; j < i; j++) {
		Data.push_back(M[j]);
	}
	it = Data.begin();
	GUI_Show_Information();
	solidrectangle(1050, 1, 1130, 100);
	settextcolor(BLACK);
	string Clock = "上次花费时间：";
	char T_clock[100];
	sprintf_s(T_clock, "%d", Clock_Number);
	Clock += T_clock;
	Clock += "ms";
	outtextxy(1025, 50, Clock.c_str());
	char Compare_Number[10];
	string CNumber="比较次数：";
	sprintf_s(Compare_Number, "%d", idx);
	CNumber += Compare_Number;
	CNumber += "次";
	outtextxy(1025, 70, CNumber.c_str());
	Beep(494, 500);
	
}
void Save_information() {
	ofstream output("excel.txt");
	for (it = Data.begin(); it != Data.end(); it++) {
		if ((it + 1) == Data.end()) {
			output << (*it).Name << "	" << (*it).Num << "	" << (*it).CourseNumber << "	" << (*it).Results;
			break;
		}
		output << (*it).Name << "	" << (*it).Num << "	" << (*it).CourseNumber << "	" << (*it).Results << endl;
	}
	output.close();
}