#include"head.h"
//ÐÕÃûÅÅÐò
void NameMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex,int &idx)//ÐÕÃû
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Name > sourceArr[j].Name)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
		
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}
//ÄÚ²¿Ê¹ÓÃµÝ¹é
void NameMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		NameMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		NameMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		NameMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}

}


//Ñ§ºÅÅÅÐò
void NumMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		NumMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		NumMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		NumMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void NumMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Num > sourceArr[j].Num)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];

	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}


//¿Î³Ì
void CourseNumberMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		CourseNumberMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		CourseNumberMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		CourseNumbernameMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void CourseNumbernameMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].CourseNumber > sourceArr[j].CourseNumber)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];

	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}



//³É¼¨ÅÅÐò
void ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		ResultsMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		ResultsMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		ResultsMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Results < sourceArr[j].Results)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];

	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}



//ÐÕÃû+³É¼¨
void Name_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		Name_ResultsMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		Name_ResultsMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		Name_ResultsMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void Name_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Results == sourceArr[j].Results) {
			if (sourceArr[i].Name > sourceArr[j].Name) {
				tempArr[k++] = sourceArr[j++];
			}
			else {
				tempArr[k++] = sourceArr[i++];
			}
		}
		else
		{
			if (sourceArr[i].Results < sourceArr[j].Results)
				tempArr[k++] = sourceArr[j++];
			else
				tempArr[k++] = sourceArr[i++];
		}
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//³É¼¨+Ñ§ºÅ
void Num_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		Num_ResultsMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		Num_ResultsMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		Num_ResultsMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void Num_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Results == sourceArr[j].Results) {
			if (sourceArr[i].Num > sourceArr[j].Num) {
				tempArr[k++] = sourceArr[j++];
			}
			else {
				tempArr[k++] = sourceArr[i++];
			}
		}
		else
		{
			if (sourceArr[i].Results < sourceArr[j].Results)
				tempArr[k++] = sourceArr[j++];
			else
				tempArr[k++] = sourceArr[i++];
		}
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}




//ÐÕÃû+Ñ§ºÅ+³É¼¨
void Name_Num_ResultsMergeSort(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int endIndex, int& idx) {
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//±ÜÃâÒç³öint
		Name_Num_ResultsMergeSort(sourceArr, tempArr, startIndex, midIndex, idx);
		Name_Num_ResultsMergeSort(sourceArr, tempArr, midIndex + 1, endIndex, idx);
		Name_Num_ResultsMerge(sourceArr, tempArr, startIndex, midIndex, endIndex, idx);
	}
}
void Name_Num_ResultsMerge(MyStruct sourceArr[], MyStruct tempArr[], int startIndex, int midIndex, int endIndex, int& idx) {
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		idx++;
		if (sourceArr[i].Results == sourceArr[j].Results) {
			if (sourceArr[i].Name == sourceArr[j].Name) {
				if (sourceArr[i].Num > sourceArr[j].Num) {
					tempArr[k++] = sourceArr[j++];
				}
				else {
					tempArr[k++] = sourceArr[i++];
				}
			}
			else if (sourceArr[i].Name > sourceArr[j].Name) {
				tempArr[k++] = sourceArr[j++];
			}
			else {
				tempArr[k++] = sourceArr[i++];
			}
		}
		else if (sourceArr[i].Results < sourceArr[j].Results)
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
		
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

