#pragma once//防止头文件被多次编译
#include"stdlib.h"//rand()函数的头文件
#include"player.h"
#include"group.h"
#include"match.h"

int main()
{
	cout<<"----------网球公开比赛----------"<<endl;
	system ("color F4");//设置背景颜色为白色
	CMatch z;


	CPlayer m[32]=
	{
		CPlayer("陈璐",1),
		CPlayer("崔梦泽",2),
		CPlayer("崔槿萱",3),
		CPlayer("单鑫",4),
		CPlayer("范佳伟",5),
		CPlayer("付亚蒙",6),
		CPlayer("郭天琪",7),
		CPlayer("黄锦堂",8),
		CPlayer("黄天溢",9),
		CPlayer("黄志杰",10),
		CPlayer("姬星宇",11),
		CPlayer("蒋问",12),
		CPlayer("蒋一帆",13),
		CPlayer("焦志友",14),
		CPlayer("李晶",15),
		CPlayer("林福",16),
		CPlayer("林家宏",17),
		CPlayer("刘世涛",18),
		CPlayer("刘娴",19),
		CPlayer("刘哲驿",20),
		CPlayer("马印驹",21),
		CPlayer("毛兵",22),
		CPlayer("庞珊",23),
		CPlayer("秦雨荷",24),
		CPlayer("苏润之",25),
		CPlayer("孙霍天昊",26),
		CPlayer("孙龙",27),
		CPlayer("王金鹏",28),
		CPlayer("王津",29),
		CPlayer("夏威",30),
		CPlayer("徐子豪",31),
		CPlayer("闫德华",32),
	};
	int a[32],b[32];
	int random;
	int i;
	for (i=0;i<32;i++)		//随机分组
	{
		a[i]=i+1;
	}
	srand((unsigned)time(NULL));//拿系统时间为种子,不同时间产生不同的随机数。
	int j;
	for(j=0;j<32;)			//利用一个数组随机给另外一个数组赋值
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
		ss[j][i]=m[b[f]];		//将一为指针数组转化为二为4*8的数组
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
