#pragma once//��ֹͷ�ļ�����α���
#include"stdlib.h"//rand()������ͷ�ļ�
#include"player.h"
#include"group.h"
#include"match.h"

int main()
{
	cout<<"----------���򹫿�����----------"<<endl;
	system ("color F4");//���ñ�����ɫΪ��ɫ
	CMatch z;


	CPlayer m[32]=
	{
		CPlayer("���",1),
		CPlayer("������",2),
		CPlayer("������",3),
		CPlayer("����",4),
		CPlayer("����ΰ",5),
		CPlayer("������",6),
		CPlayer("������",7),
		CPlayer("�ƽ���",8),
		CPlayer("������",9),
		CPlayer("��־��",10),
		CPlayer("������",11),
		CPlayer("����",12),
		CPlayer("��һ��",13),
		CPlayer("��־��",14),
		CPlayer("�",15),
		CPlayer("�ָ�",16),
		CPlayer("�ּҺ�",17),
		CPlayer("������",18),
		CPlayer("���",19),
		CPlayer("������",20),
		CPlayer("��ӡ��",21),
		CPlayer("ë��",22),
		CPlayer("��ɺ",23),
		CPlayer("�����",24),
		CPlayer("����֮",25),
		CPlayer("������",26),
		CPlayer("����",27),
		CPlayer("������",28),
		CPlayer("����",29),
		CPlayer("����",30),
		CPlayer("���Ӻ�",31),
		CPlayer("�Ƶ»�",32),
	};
	int a[32],b[32];
	int random;
	int i;
	for (i=0;i<32;i++)		//�������
	{
		a[i]=i+1;
	}
	srand((unsigned)time(NULL));//��ϵͳʱ��Ϊ����,��ͬʱ�������ͬ���������
	int j;
	for(j=0;j<32;)			//����һ���������������һ�����鸳ֵ
	{
		random=rand()%32;
		if (a[random]!=0)
		{
			b[j]=a[random]-1;
			a[random]=0;
			j++;
		}
	}
int f=0;
CPlayer ss[4][8];
for (j=0;j<=3;j++)
{
	for(i=0;i<=7;i++,f++)
	{
		ss[j][i]=m[b[f]];		//��һΪָ������ת��Ϊ��Ϊ4*8������
	}
}

CGroup ll[4] = {
		CGroup(ss[0][0],ss[0][1],ss[0][2],ss[0][3],ss[0][4],ss[0][5],ss[0][6],ss[0][7]),
		CGroup(ss[1][0],ss[1][1],ss[1][2],ss[1][3],ss[1][4],ss[1][5],ss[1][6],ss[1][7]),
		CGroup(ss[2][0],ss[2][1],ss[2][2],ss[2][3],ss[2][4],ss[2][5],ss[2][6],ss[2][7]),
		CGroup(ss[3][0],ss[3][1],ss[3][2],ss[3][3],ss[3][4],ss[3][5],ss[3][6],ss[3][7])
		};
		z.halfgame(ll[0],ll[1],ll[2],ll[3]);
system("pause");

	return 0;
}
