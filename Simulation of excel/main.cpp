#include"head.h"
using namespace std;
int main() {
	GUI_Main();
	cout << "ÊÇ·ñ±£´æ£¿Y/N£º" << endl;
	char prompt;
	cin >> prompt;
	if (prompt == 'Y'|| prompt == 'y') {
		Save_information();
	}
	return 0;
}