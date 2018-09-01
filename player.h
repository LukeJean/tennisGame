#include<iostream>
#pragma once//防止头文件被多次编译
#include<string>
#include<cstdlib>//system()函数的头文件,设置控制台窗口,还有一些工具函数，更改背景，字体颜色
#include<ctime>//时间函数的头文件
using namespace std;
class CPlayer
{
private:
	int goals;
	int innings;
	int score;
	string name;//姓名
	int number;//编号
	
public:
	friend class CMatch;//声明match是CPlayer的友元类
	CPlayer(string n="null", int num=0)//CPlayer的默认构造函数
	{
		name=n;
		number = num;
		goals=0;//赢得的球数
		innings=0;//赢得的局数
		score=0;//分数
	}
	CPlayer(CPlayer &p)//拷贝构造
	{
		name= p.name;
		number = p.number;
	}
	void goalsgamestart()//初始化
	{
		goals = 0;
	}
	void inningsgamestart()//初始化
	{
		innings = 0;
	}
	void scoregamestart()//初始化
	{
		score = 0;
	}
	void goalswin()//计数(赢得的球数)
	{
		goals++;
	}
	void inningswin()//计数(赢得的局数)
	{
		innings++;
	}
	void scorewin()//计数(分)
	{
		score++;
	}
	string getname()
	{
		return name;
	}
	int getnumber()
	{
		return number;
	}
};