#include<iostream>
#include"group.h"
#include<cmath>
#include<windows.h>  //		Sleep()����ͷ�ļ�;
class CMatch
{
public:
	void goalsgame(CPlayer &p1, CPlayer &p2)
	{

			int n,m;
			

			cout<<"              |--------------------------------------------------|"<<endl;
			cout<<"                               *** ������ʼ ***"<<endl;
			cout<<"              |--------------------------------------------------|"<<endl;
			for (p1.goalsgamestart(), p2.goalsgamestart();;)//�ڼ���ʤ��
			{
				m = (rand() % 2);//1,2�����һ����
				if (m == 1)
				{
					cout << p1.name << "ѡ�ַ���" <<endl;
				}
				else
				{
					cout << p2.name << "ѡ�ַ���" << endl;//��������Ȩ
				}
				n = (rand() % 2);//��ȡ�����
				if (n == 1)
				{   
					p1.goalswin();
					cout<<"**************************"<<p1.name<<"Ӯ�ñ���**********************************"<<endl;
				}
				else
				{
					p2.goalswin();
					cout<<"**************************"<<p2.name<<"Ӯ�ñ���**********************************"<<endl;
				}
				if (p1.goals==4&&p2.goals<4)
				{
					p1.inningswin();
					cout<<" *** ��ǰ�ȷ� ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p1.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p1.goals>4&&p1.goals-p2.goals==2)
				{
					p1.inningswin();
					cout<<" *** ��ǰ�ȷ� ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p1.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p2.goals==4&&p1.goals<4)
				{
					p2.inningswin();
					cout<<" *** ��ǰ�ȷ� ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p2.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p2.goals>4&&p2.goals-p1.goals==2)
				{
					p2.inningswin();
					cout<<" *** ��ǰ�ȷ� ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p2.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
			}//ÿ�ֵ�ʤ���ж�
		}
	void inningsgame(CPlayer &p1, CPlayer &p2)//ÿ�̱�����ʤ���ж�
	{
		p1.inningsgamestart();
		p2.inningsgamestart();
		for (;;)
		{ 
			Sleep(1500);
			goalsgame(p1, p2);//����ÿ���ʤ���ж�
			cout << "���̱ȷ�Ϊ" << p1.innings << ":" << p2.innings << endl;
			if (p1.innings==6&&p2.innings<5)
			{
				cout<<"                      *** "<<p1.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p1.scorewin();
				
				return;
			}else if(p1.innings==7&&p2.innings==5)
				{
					cout<<"                      *** "<<p1.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					p1.scorewin();
					return;
				}
			else if (p1.innings==7&&p2.innings==6)
			{
				cout<<p1.name<<"������ʤ"<<endl;
				cout<<"                      *** "<<p1.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p1.scorewin();
				return;
			}
			else if (p2.innings==6&&p1.innings<5)
			{
				cout<<"                      *** "<<p2.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			else if(p2.innings==7&&p1.innings==5)
			{
				cout<<"                      *** "<<p2.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			else if (p2.innings==7&&p1.innings==6)
			{
				cout<<p2.name<<"������ʤ"<<endl;
				cout<<"                      *** "<<p2.name<<"ѡ�ֻ�ñ���ʤ�� ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			}
	}
	CPlayer gamewinner(CPlayer &p1, CPlayer &p2)//ÿ��������ʤ���ж�
	{
		cout << p1.name << "  " << "VS" << "  " << p2.name << endl;
		p1.scoregamestart();
		p2.scoregamestart();
		srand(unsigned(time(NULL)));
		for (;;)
		{	
			Sleep(1500);
			inningsgame(p1, p2);//����ÿ�̵�ʤ���ж�
			cout<<"              |--------------------------------------------------|"<<endl;
			cout<<" *** ��ǰ�ȷ� ***"<<p1.goals<< ":" << p2.goals <<endl;
			cout<<"              |--------------------------------------------------|"<<endl;
			if (p1.score == 2)
			{
				cout<<"     ++++++++++++++++++++++++++++��������++++++++++++++++++++++++++"<<endl;
				cout<<"     ++++++++++++++++++++++++++++"<<p1.name<<"����˱���������ʤ��++++++++++++++++++++++++++"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				return p1;
			}
			if (p2.score == 2)
			{
				cout<<"     ++++++++++++++++++++++++++++��������++++++++++++++++++++++++++"<<endl;
				cout<<"     ++++++++++++++++++++++++++++"<<p2.name<<"����˱���������ʤ��++++++++++++++++++++++++++"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				return p2;
			}
			
		}
	}
	CPlayer groupgame(CGroup &p)//�ó�С�����ĳ�����
	{
		cout<<"              |--------------------------------------------------|"<<endl;
		cout << (gamewinner(gamewinner(gamewinner(p.person1, p.person2), gamewinner(p.person3, p.person4)),
			gamewinner(gamewinner(p.person5, p.person6), gamewinner(p.person7, p.person8)))).name << "����" << endl;
		cout<<"              |--------------------------------------------------|"<<endl;
		return gamewinner(gamewinner(gamewinner(p.person5, p.person6), gamewinner(p.person7, p.person8)),
			gamewinner(gamewinner(p.person1, p.person2), gamewinner(p.person3, p.person4)));
	}
	CPlayer halfgame(CGroup &p1, CGroup &p2,CGroup &p3,CGroup &p4)
	{
		cout<<"                               *** ��ǰ��ǩ ***"<<endl;
		groupteam(p1, p2, p3, p4);
		CPlayer winner;	
		CPlayer teamline1, teamline2, teamline3, teamline4;
		teamline1 = groupgame(p1);
		teamline2 = groupgame(p2);
		teamline3 = groupgame(p3);
		teamline4 = groupgame(p4);
		cout<<"              |--------------------------------------------------|"<<endl;;
		cout << "������Ϊ:" << endl;
		cout << teamline1.name << " " << teamline2.name << " ";
		cout << teamline3.name << " " << teamline4.name << endl;
		cout<<"     ++++++++++++++++++++++++++++�����++++++++++++++++++++++++++"<<endl;
		Sleep(1500);
		CPlayer halfplay1, halfplay2;
		halfplay1 = gamewinner(teamline1, teamline2);
		cout << halfplay1.name << "���ʤ���������" << endl;
		halfplay2 = gamewinner(teamline3, teamline4);
		cout << halfplay2.name << "���ʤ���������" << endl;
		cout<<"              |--------------------------------------------------|"<<endl;
		cout<<"     ++++++++++++++++++++++++++++�ܾ���++++++++++++++++++++++++++"<<endl;
		Sleep(1500);
		winner = gamewinner(halfplay1, halfplay2);
		cout << endl;
		cout<<endl<<endl<<endl<<endl;
		cout<<"			                     *** ��ùھ� ***"<<endl;
		cout<<"			                        "<<winner.name<<"ѡ��"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		return winner;
	}
	void groupteam(CGroup &p1, CGroup &p2, CGroup &p3, CGroup &p4)
	{
		cout << "��һ��:" << endl;
		p1.personprint();
		cout << "�ڶ���:" << endl;
		p2.personprint();
		cout << "������:" << endl;
		p3.personprint();
		cout << "������:" << endl;
		p4.personprint();

	}


};
