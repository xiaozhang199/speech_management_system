#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
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
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;
	
	//����12��ѡ��
	void createSpeaker();

	//��ʼ����-�������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ����
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileisEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;
};