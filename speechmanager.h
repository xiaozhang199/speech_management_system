#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class  SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//显示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//析构函数
	~SpeechManager();

	//初始化容器和属性
	void initSpeech();

	//成员属性
	//保存第一轮比赛选手编号
	vector<int>v1;

	//第一轮晋级选手编号
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, string>m_Speaker;

	//存放比赛轮数
	int m_Index;
};