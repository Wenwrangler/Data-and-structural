#pragma once
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include <cstdio>
using namespace std;
struct MyStruct
{
	string name;
	string num;
	string CourseNumber;
	string results;
};
void GUImain();
void GUIcycle();
void GUI_Sort(vector<MyStruct>& Data);
bool MyComp(const MyStruct& a, const MyStruct& b);