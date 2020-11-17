#include<iostream>
#include"workerManger.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
using namespace std;

int main() {
	//代码测试
	/* worker * worker = NULL;
	worker = new Employee(1, "张三", 1);
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
	cout << "请输入你的选择：" << endl;
	cin >> choice;
	switch (choice) {
	case 0:wm.exitSystem();//退出管理系统
		break;
	case 1://增加职工
		wm.Add_Emp();
		break;
	case 2://显示职工
		wm.show_Emp();
		break;
	case 3://删除职工
		wm.Del_Emp();
		break;
	case 4://修改职工
		wm.Mod_Emp();
		break;
	case 5://查找职工
		wm.Find_Emp();
		break;
	case 6://排序职工
		wm.Sort_Emp();
		break;
	case 7://清空文件
		wm.Clean_File();
		break;

	default:
	{cout << "输入有误，请重新输入！" << endl;
	system("pause");
	system("cls");
	break; }
	}
	
	}
	

	system("pause");
	return 0;

}
