#include<iostream>
#include"group.h"
#include<cmath>
#include<windows.h>  //		Sleep()函数头文件;
class CMatch
{
public:
	void goalsgame(CPlayer &p1, CPlayer &p2)
	{

			int n,m;
			

			cout<<"              |--------------------------------------------------|"<<endl;
			cout<<"                               *** 比赛开始 ***"<<endl;
			cout<<"              |--------------------------------------------------|"<<endl;
			for (p1.goalsgamestart(), p2.goalsgamestart();;)//第几球胜利
			{
				m = (rand() % 2);//1,2里随机一个数
				if (m == 1)
				{
					cout << p1.name << "选手发球" <<endl;
				}
				else
				{
					cout << p2.name << "选手发球" << endl;//决定发球权
				}
				n = (rand() % 2);//获取随机数
				if (n == 1)
				{   
					p1.goalswin();
					cout<<"**************************"<<p1.name<<"赢得本球**********************************"<<endl;
				}
				else
				{
					p2.goalswin();
					cout<<"**************************"<<p2.name<<"赢得本球**********************************"<<endl;
				}
				if (p1.goals==4&&p2.goals<4)
				{
					p1.inningswin();
					cout<<" *** 当前比分 ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p1.name<<"选手获得本局胜利 ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p1.goals>4&&p1.goals-p2.goals==2)
				{
					p1.inningswin();
					cout<<" *** 当前比分 ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p1.name<<"选手获得本局胜利 ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p2.goals==4&&p1.goals<4)
				{
					p2.inningswin();
					cout<<" *** 当前比分 ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p2.name<<"选手获得本局胜利 ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
				else if (p2.goals>4&&p2.goals-p1.goals==2)
				{
					p2.inningswin();
					cout<<" *** 当前比分 ***"<<p1.goals<< ":" << p2.goals <<endl;
					cout<<"                      ***"<<p2.name<<"选手获得本局胜利 ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					return;
				}
			}//每局的胜利判断
		}
	void inningsgame(CPlayer &p1, CPlayer &p2)//每盘比赛的胜利判断
	{
		p1.inningsgamestart();
		p2.inningsgamestart();
		for (;;)
		{ 
			Sleep(1500);
			goalsgame(p1, p2);//调用每球的胜利判断
			cout << "该盘比分为" << p1.innings << ":" << p2.innings << endl;
			if (p1.innings==6&&p2.innings<5)
			{
				cout<<"                      *** "<<p1.name<<"选手获得本盘胜利 ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p1.scorewin();
				
				return;
			}else if(p1.innings==7&&p2.innings==5)
				{
					cout<<"                      *** "<<p1.name<<"选手获得本盘胜利 ***"<<endl;
					cout<<"              |--------------------------------------------------|"<<endl;
					p1.scorewin();
					return;
				}
			else if (p1.innings==7&&p2.innings==6)
			{
				cout<<p1.name<<"抢七险胜"<<endl;
				cout<<"                      *** "<<p1.name<<"选手获得本盘胜利 ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p1.scorewin();
				return;
			}
			else if (p2.innings==6&&p1.innings<5)
			{
				cout<<"                      *** "<<p2.name<<"选手获得本盘胜利 ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			else if(p2.innings==7&&p1.innings==5)
			{
				cout<<"                      *** "<<p2.name<<"选手获得本盘胜利 ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			else if (p2.innings==7&&p1.innings==6)
			{
				cout<<p2.name<<"抢七险胜"<<endl;
				cout<<"                      *** "<<p2.name<<"选手获得本盘胜利 ***"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				p2.scorewin();
				return;
			}
			}
	}
	CPlayer gamewinner(CPlayer &p1, CPlayer &p2)//每场比赛的胜利判断
	{
		cout << p1.name << "  " << "VS" << "  " << p2.name << endl;
		p1.scoregamestart();
		p2.scoregamestart();
		srand(unsigned(time(NULL)));
		for (;;)
		{	
			Sleep(1500);
			inningsgame(p1, p2);//调用每盘的胜利判断
			cout<<"              |--------------------------------------------------|"<<endl;
			cout<<" *** 当前比分 ***"<<p1.goals<< ":" << p2.goals <<endl;
			cout<<"              |--------------------------------------------------|"<<endl;
			if (p1.score == 2)
			{
				cout<<"     ++++++++++++++++++++++++++++比赛结束++++++++++++++++++++++++++"<<endl;
				cout<<"     ++++++++++++++++++++++++++++"<<p1.name<<"获得了本场比赛的胜利++++++++++++++++++++++++++"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				return p1;
			}
			if (p2.score == 2)
			{
				cout<<"     ++++++++++++++++++++++++++++比赛结束++++++++++++++++++++++++++"<<endl;
				cout<<"     ++++++++++++++++++++++++++++"<<p2.name<<"获得了本场比赛的胜利++++++++++++++++++++++++++"<<endl;
				cout<<"              |--------------------------------------------------|"<<endl;
				return p2;
			}
			
		}
	}
	CPlayer groupgame(CGroup &p)//得出小组赛的出线者
	{
		cout<<"              |--------------------------------------------------|"<<endl;
		cout << (gamewinner(gamewinner(gamewinner(p.person1, p.person2), gamewinner(p.person3, p.person4)),
			gamewinner(gamewinner(p.person5, p.person6), gamewinner(p.person7, p.person8)))).name << "出线" << endl;
		cout<<"              |--------------------------------------------------|"<<endl;
		return gamewinner(gamewinner(gamewinner(p.person5, p.person6), gamewinner(p.person7, p.person8)),
			gamewinner(gamewinner(p.person1, p.person2), gamewinner(p.person3, p.person4)));
	}
	CPlayer halfgame(CGroup &p1, CGroup &p2,CGroup &p3,CGroup &p4)
	{
		cout<<"                               *** 赛前抽签 ***"<<endl;
		groupteam(p1, p2, p3, p4);
		CPlayer winner;	
		CPlayer teamline1, teamline2, teamline3, teamline4;
		teamline1 = groupgame(p1);
		teamline2 = groupgame(p2);
		teamline3 = groupgame(p3);
		teamline4 = groupgame(p4);
		cout<<"              |--------------------------------------------------|"<<endl;;
		cout << "出线者为:" << endl;
		cout << teamline1.name << " " << teamline2.name << " ";
		cout << teamline3.name << " " << teamline4.name << endl;
		cout<<"     ++++++++++++++++++++++++++++半决赛++++++++++++++++++++++++++"<<endl;
		Sleep(1500);
		CPlayer halfplay1, halfplay2;
		halfplay1 = gamewinner(teamline1, teamline2);
		cout << halfplay1.name << "获得胜利进入决赛" << endl;
		halfplay2 = gamewinner(teamline3, teamline4);
		cout << halfplay2.name << "获得胜利进入决赛" << endl;
		cout<<"              |--------------------------------------------------|"<<endl;
		cout<<"     ++++++++++++++++++++++++++++总决赛++++++++++++++++++++++++++"<<endl;
		Sleep(1500);
		winner = gamewinner(halfplay1, halfplay2);
		cout << endl;
		cout<<endl<<endl<<endl<<endl;
		cout<<"			                     *** 获得冠军 ***"<<endl;
		cout<<"			                        "<<winner.name<<"选手"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		return winner;
	}
	void groupteam(CGroup &p1, CGroup &p2, CGroup &p3, CGroup &p4)
	{
		cout << "第一组:" << endl;
		p1.personprint();
		cout << "第二组:" << endl;
		p2.personprint();
		cout << "第三组:" << endl;
		p3.personprint();
		cout << "第四组:" << endl;
		p4.personprint();

	}


};
