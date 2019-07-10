#pragma once
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include <stdlib.h>
#include <cstdio>
using namespace std;
struct MyStruct
{
	string Name;                     //姓名
	string Num;                      //学号
	string CourseNumber;             //课程编号
	string Results;                  //成绩
};
void GUI_Main();//可视化主函数
void GUI_Show_Information();//展示文本信息
void MySort();

void NameMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex,int &idx);
void NameMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//姓名

void NumMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void NumMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//学号

void CourseNumberMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void CourseNumbernameMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//课程

void ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//成绩

void Name_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void Name_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//姓名+成绩


void Num_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void Num_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//学号+成绩

void Name_Num_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx);
void Name_Num_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx);//姓名+学号+成绩

void Save_information();