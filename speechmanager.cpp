#include"speechManager.h"
SpeechManager::SpeechManager() {
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
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

	//����¼������Ҳ���
	this->m_Record.clear();
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		sp.m_Score[0] = 0;
		sp.m_Score[1] = 0;

		//��12��ѡ�ֱ�ţ����ҷ���v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ�ż���������ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

void SpeechManager::speechDraw() {
	cout << "��" << this->m_Index << "����ѡ�����ڳ�ǩ" << endl;
	cout << "************************" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_Index == 1) {
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	else {
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			cout << (*it) << "  ";
		}
		cout << endl;
	}
	cout << "***********************" << endl;
	cout << "��" << this->m_Index << "�۱���ѡ�ֳ�ǩ���" << endl;
	system("pause");
}

void SpeechManager::speechContest() {
	cout << "��-----��" << this->m_Index << "�۱�����ʽ��ʼ-----" << endl;
		
	//׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0;

	vector<int>v_Src;//������Ա����
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
		//	cout << score << '\t';
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//����

		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();//ƽ����

		//��ӡƽ����
	//	cout << "��ţ�  " << *it << "������  " << this->m_Speaker[*it].m_Name << "��ȡƽ���֣�"
	//		<< avg << endl;

		//��ƽ���ַŵ�map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������ݷ���С��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�*it����Ա���

		//ÿ6��ȡ��ǰ3��
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "��ţ�" << it->second << "  ������" << this->m_Speaker[it->second].m_Name
					<< "  �ɼ�:" << this->m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}

			//ȡ��ǰ������
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

	cout << "--------------��" << this->m_Index << "�ֱ�����ϣ�---------" << endl;
	system("pause");
}

//��ʾ�÷�
void SpeechManager::showScore() {
	cout << "--------------��" << this->m_Index << "�ֽ���ѡ����Ϣ����-----" << endl;
	 
	vector<int>v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ��" << *it << "������" << this->m_Speaker[*it].m_Name << "�÷�" <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::startSpeech() {
	//��һ�ֿ�ʼ����

	//��ǩ
	this->speechDraw();
	
	//����
	this->speechContest();

	//��ʾ�������
	this->showScore();
	
	//�ڶ��ֿ�ʼ����
	this->m_Index++;

	//��ǩ
	this->speechDraw();
	
	//����
	this->speechContest();
	
	//��ʾ�������
	this->showScore();
	
	//����ѡ����Ϣ
	this->saveRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");

	//���ñ�������ȡ��¼
	this->initSpeech();

	this->createSpeaker();
	
	this->loadRecord();
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	//����ʤѡ����Ϣд���ļ�
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "��¼�ѱ�����" << endl;

	//�����ļ�״̬
	this->fileisEmpty = false;
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open()) {
		this->fileisEmpty = true;
	//	cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
	//	cout << "�ļ�Ϊ��" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileisEmpty = false;

	ifs.putback(ch); // �������ȡ���ַ����Ż���

	string data;
	
	int index = 0;
	while (ifs >> data) {
		int pos = -1;//�鵽����λ�õı���
		int start = 0;
		
		vector<string>v;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				//û���ҵ����
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
	//	cout << it->first << "�ھ����" << it->second[0]
	//		<< "������" << it->second[1] << endl;
	//}
}

void SpeechManager::showRecord() {
	if (this->fileisEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		for (map<int, vector<string>> ::iterator it = this->m_Record.begin(); it != this->m_Record.end();it++) {
			cout << "��" << it->first + 1 << "��"
				<< "�ھ���ţ�" << it->second[0] << "�÷֣�" << it->second[1] << " "
				<< "�Ǿ���ţ�" << it->second[2] << "�÷֣�" << it->second[3] << " "
				<< "������ţ�" << it->second[4] << "�÷֣�" << it->second[5] << " "
				<< endl;
		}
	}
	
}

void SpeechManager::clearRecord() {
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}
	
	system("pause");
	system("cls");
}

//û�ж������ݣ�������񶼿���
SpeechManager::~SpeechManager() {

}
