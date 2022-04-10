#include"speechManager.h"

SpeechManager::SpeechManager() {
	this->initSpeech();
}

void SpeechManager::showMenu() {
	cout << "******************************" << endl;
	cout << "*******��ӭ�μ��ݽ�����*******" << endl;
	cout << "*******1. ��ʼ�ݽ����� *******" << endl;
	cout << "*******2. �鿴�����¼ *******" << endl;
	cout << "*******3. ��ձ�����¼ *******" << endl;
	cout << "*******0. �˳��������� *******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;
}

SpeechManager::~SpeechManager() {

}
