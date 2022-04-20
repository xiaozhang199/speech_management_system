#include"speechManager.h"
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}

void SpeechManager::showMenu() {
	cout << "******************************" << endl;
	cout << "*******欢迎参加演讲比赛*******" << endl;
	cout << "*******1. 开始演讲比赛 *******" << endl;
	cout << "*******2. 查看往届记录 *******" << endl;
	cout << "*******3. 清空比赛记录 *******" << endl;
	cout << "*******0. 退出比赛程序 *******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech() {
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;

	//将记录的容器也清空
	this->m_Record.clear();
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;

		//将12名选手编号，并且放入v1容器中
		this->v1.push_back(i + 10001);

		//选手编号及其姓名存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::speechDraw() {
	cout << "第" << this->m_Index << "比赛选手正在抽签" << endl;
	cout << "************************" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_Index == 1) {
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	else {
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	cout << "***********************" << endl;
	cout << "第" << this->m_Index << "论比赛选手抽签完毕" << endl;
	system("pause");
}

void SpeechManager::speechContest() {
	cout << "—-----第" << this->m_Index << "论比赛正式开始-----" << endl;
		
	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0;

	vector<int>v_Src;//比赛人员容器
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
		//	cout << score << '\t';
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//排序

		d.pop_front();//去掉最高分
		d.pop_back();//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();//平均分

		//打印平均分
	//	cout << "编号：  " << *it << "姓名：  " << this->m_Speaker[*it].m_Name << "获取平均分："
	//		<< avg << endl;

		//将平均分放到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据放入小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，*it是人员编号

		//每6人取出前3名
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "编号：" << it->second << "  姓名：" << this->m_Speaker[it->second].m_Name
					<< "  成绩:" << this->m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}

			//取走前三名：
			int cnt = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cnt++;
				if (cnt <= 3) {
					if (this->m_Index == 1) {
						v2.push_back((*it).second);
					}
					else {
						vVictory.push_back(it->second);
					}
				}
				else {
					break;
				}
			}

			groupScore.clear();
		}
	}

	cout << "--------------第" << this->m_Index << "轮比赛完毕！---------" << endl;
	system("pause");
}

//显示得分
void SpeechManager::showScore() {
	cout << "--------------第" << this->m_Index << "轮晋级选手信息如下-----" << endl;
	 
	vector<int>v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号" << *it << "姓名：" << this->m_Speaker[*it].m_Name << "得分" <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::startSpeech() {
	//第一轮开始比赛

	//抽签
	this->speechDraw();
	
	//比赛
	this->speechContest();

	//显示晋级结果
	this->showScore();
	
	//第二轮开始比赛
	this->m_Index++;

	//抽签
	this->speechDraw();
	
	//比赛
	this->speechContest();
	
	//显示晋级结果
	this->showScore();
	
	//保存选手信息
	this->saveRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");

	//重置比赛，获取记录
	this->initSpeech();

	this->createSpeaker();
	
	this->loadRecord();
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	//将获胜选手信息写入文件
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录已被保存" << endl;

	//更改文件状态
	this->fileisEmpty = false;
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open()) {
		this->fileisEmpty = true;
	//	cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
	//	cout << "文件为空" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileisEmpty = false;

	ifs.putback(ch); // 将上面读取的字符，放回来

	string data;
	
	int index = 0;
	while (ifs >> data) {
		int pos = -1;//查到逗号位置的变量
		int start = 0;
		
		vector<string>v;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				//没有找到情况
				break;
			}

			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
	//	cout << it->first << "冠军编号" << it->second[0]
	//		<< "分数：" << it->second[1] << endl;
	//}
}

void SpeechManager::showRecord() {
	if (this->fileisEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		for (map<int, vector<string>> ::iterator it = this->m_Record.begin(); it != this->m_Record.end();it++) {
			cout << "第" << it->first + 1 << "届"
				<< "冠军编号：" << it->second[0] << "得分：" << it->second[1] << " "
				<< "亚军编号：" << it->second[2] << "得分：" << it->second[3] << " "
				<< "季军编号：" << it->second[4] << "得分：" << it->second[5] << " "
				<< endl;
		}
	}
	
}

void SpeechManager::clearRecord() {
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	
	system("pause");
	system("cls");
}

//没有堆区数据，析构与否都可以
SpeechManager::~SpeechManager() {

}
