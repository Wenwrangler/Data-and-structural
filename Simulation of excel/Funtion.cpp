#include"head.h"
void GUI_Sort(vector<MyStruct> &Data) {
	stable_sort(Data.begin(), Data.end(), MyComp);
	return;
}
bool MyComp(const MyStruct &a,const MyStruct &b) {
	return a.name < b.name;
}