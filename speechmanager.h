#pragma once
#include<iostream>
#include<vector>
using namespace std;

class  SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//��ʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//��������
	~SpeechManager();

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ��
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ��
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
};