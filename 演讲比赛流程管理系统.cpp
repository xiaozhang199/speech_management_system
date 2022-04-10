#include<iostream>
#include"speechManager.h"
using namespace std;

int main() {
	SpeechManager sm;

	int choice = 0;

	while (true) {

		sm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}

	}
	return 0;
}