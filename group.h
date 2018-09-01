#include"player.h"
#pragma once//防止头文件被多次编译
using namespace std;
class CGroup
{
friend class CMatch;//CMatch可访问其的私有成员函数
private:
	CPlayer person1;
	CPlayer person2;
	CPlayer person3;
	CPlayer person4;
	CPlayer person5;
	CPlayer person6;
	CPlayer person7;
	CPlayer person8;
public:
	CGroup(CPlayer p1, CPlayer p2, CPlayer p3, CPlayer p4, CPlayer p5, CPlayer p6, CPlayer p7, CPlayer p8) :person1(p1), person2(p2), person3(p3),
			person4(p4), person5(p5), person6(p6), person7(p7), person8(p8)
	{ }//利用CPlayer类的对象构造CGroup内的数据成员
	void personprint()
	{
		cout << "姓名:" << person1.getname() << endl;
		cout << "编号:" << person1.getnumber() << endl;
		cout << "姓名:" << person2.getname() << endl;
		cout << "编号:" << person2.getnumber() << endl;
		cout << "姓名:" << person3.getname() << endl;
		cout << "编号:" << person3.getnumber() << endl;
		cout << "姓名:" << person4.getname() << endl;
		cout << "编号:" << person4.getnumber() << endl;
		cout << "姓名:" << person5.getname() << endl;
		cout << "编号:" << person5.getnumber() << endl;
		cout << "姓名:" << person6.getname() << endl;
		cout << "编号:" << person6.getnumber() << endl;
		cout << "姓名:" << person7.getname() << endl;
		cout << "编号:" << person7.getnumber() << endl;
		cout << "姓名:" << person8.getname() << endl;
		cout << "编号:" << person8.getnumber() << endl;
	    cout<<"              |--------------------------------------------------|"<<endl<<endl;
	}
};