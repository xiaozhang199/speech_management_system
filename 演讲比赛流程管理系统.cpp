#include<iostream>
#include"speechManager.h"
using namespace std;

int main() {
	SpeechManager sm;

	//测试
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end();it++) {
	//	cout << it->first << "       " << it->second.m_Name << endl;
	//}
	
	int choice = 0;

	while (true) {

		sm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			sm.startSpeech();
			break;
		case 2://查看往届记录
			
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