#include<iostream>
#include"workerManger.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
using namespace std;

int main() {
	//�������
	/* worker * worker = NULL;
	worker = new Employee(1, "����", 1);
	worker ->showInfo();
	delete worker;

	worker = new Manger(2, "lisi1", 2);
	worker->showInfo();
	delete worker;

	worker = new boss(3, "wangwu1", 4);
	worker->showInfo();
	delete worker;*/

	WorkManger wm;
	int choice;
	while (true) {
	wm.Show_Menu();
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice) {
	case 0:wm.exitSystem();//�˳�����ϵͳ
		break;
	case 1://����ְ��
		wm.Add_Emp();
		break;
	case 2://��ʾְ��
		wm.show_Emp();
		break;
	case 3://ɾ��ְ��
		wm.Del_Emp();
		break;
	case 4://�޸�ְ��
		wm.Mod_Emp();
		break;
	case 5://����ְ��
		wm.Find_Emp();
		break;
	case 6://����ְ��
		wm.Sort_Emp();
		break;
	case 7://����ļ�
		wm.Clean_File();
		break;

	default:
	{cout << "�����������������룡" << endl;
	system("pause");
	system("cls");
	break; }
	}
	
	}
	

	system("pause");
	return 0;

}
