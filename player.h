#include<iostream>
#pragma once//��ֹͷ�ļ�����α���
#include<string>
#include<cstdlib>//system()������ͷ�ļ�,���ÿ���̨����,����һЩ���ߺ��������ı�����������ɫ
#include<ctime>//ʱ�亯����ͷ�ļ�
using namespace std;
class CPlayer
{
private:
	int goals;
	int innings;
	int score;
	string name;//����
	int number;//���
	
public:
	friend class CMatch;//����match��CPlayer����Ԫ��
	CPlayer(string n="null", int num=0)//CPlayer��Ĭ�Ϲ��캯��
	{
		name=n;
		number = num;
		goals=0;//Ӯ�õ�����
		innings=0;//Ӯ�õľ���
		score=0;//����
	}
	CPlayer(CPlayer &p)//��������
	{
		name= p.name;
		number = p.number;
	}
	void goalsgamestart()//��ʼ��
	{
		goals = 0;
	}
	void inningsgamestart()//��ʼ��
	{
		innings = 0;
	}
	void scoregamestart()//��ʼ��
	{
		score = 0;
	}
	void goalswin()//����(Ӯ�õ�����)
	{
		goals++;
	}
	void inningswin()//����(Ӯ�õľ���)
	{
		innings++;
	}
	void scorewin()//����(��)
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