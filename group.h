#include"player.h"
#pragma once//��ֹͷ�ļ�����α���
using namespace std;
class CGroup
{
friend class CMatch;//CMatch�ɷ������˽�г�Ա����
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
	{ }//����CPlayer��Ķ�����CGroup�ڵ����ݳ�Ա
	void personprint()
	{
		cout << "����:" << person1.getname() << endl;
		cout << "���:" << person1.getnumber() << endl;
		cout << "����:" << person2.getname() << endl;
		cout << "���:" << person2.getnumber() << endl;
		cout << "����:" << person3.getname() << endl;
		cout << "���:" << person3.getnumber() << endl;
		cout << "����:" << person4.getname() << endl;
		cout << "���:" << person4.getnumber() << endl;
		cout << "����:" << person5.getname() << endl;
		cout << "���:" << person5.getnumber() << endl;
		cout << "����:" << person6.getname() << endl;
		cout << "���:" << person6.getnumber() << endl;
		cout << "����:" << person7.getname() << endl;
		cout << "���:" << person7.getnumber() << endl;
		cout << "����:" << person8.getname() << endl;
		cout << "���:" << person8.getnumber() << endl;
	    cout<<"              |--------------------------------------------------|"<<endl<<endl;
	}
};