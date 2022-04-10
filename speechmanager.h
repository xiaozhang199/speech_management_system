#pragma once
#include<iostream>
#include<vector>
#include<map>
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

	//��ʼ������������
	void initSpeech();

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ��
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ��
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, string>m_Speaker;

	//��ű�������
	int m_Index;
};