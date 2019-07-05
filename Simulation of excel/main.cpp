#include"head.h"
using namespace std;
int main() {
	GUI_Main();
	cout << "ÊÇ·ñ±£´æ£¿Y/N£º" << endl;
	char prompt;
	cin >> prompt;
	if (prompt == 'Y') {
		Save_information();
	}
	return 0;
}