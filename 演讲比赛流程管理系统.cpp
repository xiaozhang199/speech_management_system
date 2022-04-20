#include<iostream>
#include"speechManager.h"
using namespace std;
#include<ctime>

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

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
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
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