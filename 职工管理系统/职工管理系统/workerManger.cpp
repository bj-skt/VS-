#include "workerManger.h"

WorkManger::WorkManger() {

	//初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;

	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在"<<endl;//测试输出
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;	
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;	
	}
	//文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;//更新成员属性

	//开辟空间
	this->m_EmpArray = new worker*[this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "职工编号：" << this->m_EmpArray[i]->m_id
			<< "\t姓名：" << this->m_EmpArray[i]->m_name
			<< "\t部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	
	}*/
}
WorkManger::~WorkManger() {
	if (this->m_EmpArray != NULL) {
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	
	}

}
void WorkManger::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0;i < m_EmpNum; i++)
		{//利用多态显示
			this->m_EmpArray[i]->showInfo();
		}
			}
	system("pause");
	system("cls");
}
void WorkManger::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		worker *worker = NULL;
		//根据不同部门Id创建不同对象
		if (dId == 1)//普通员工
		{
			worker = new Employee(id, name, dId);
		}//经理
		if (dId == 2)
		{
			worker = new Manger(id, name,dId);
		}
		else//boss
		{
			worker = new boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;	
	}

}
int WorkManger::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//记录人数
	}
	ifs.close();
	return num;

}
void WorkManger::exitSystem() {

	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);


}
void WorkManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件  -写文件

	for (int i = 0; i <this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "\t"
			<< this->m_EmpArray[i]->m_name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;	
	}
	ofs.close();

}
void WorkManger::Add_Emp() {
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
	//添加
	//计算新空间大小
	int newSize = this->m_EmpNum + addNum;//新空间人数		
											  
	//开辟新空间
	worker ** newSpace = new worker*[newSize];
	//将原来空间下数据，拷贝到新空间下
	if (this->m_EmpNum != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			newSpace[i] = this->m_EmpArray[i];

		}
	}
	//批量添加数据
	for (int i = 0; i < addNum; i++)
	{
		int id;
		string name;
		int dslect;
		cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
		cin >> id;
		cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
		cin >> name;
		cout << "请选择该职工岗位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> dslect;
		worker *worker = NULL;
		switch (dslect) {
		case 1:
			worker = new Employee(id,name,1);
			break;
		case 2:
			worker = new Manger(id, name, 2);
			break;
		case 3:
			worker = new boss(id, name, 3);
			break;
		default:
			break;
		
		}
		//将创建职工保存到数组中
		newSpace[this->m_EmpNum + i] = worker;

	
	}
	//释放原有空间
	delete[] this->m_EmpArray;
	//更改新空间指向
	this->m_EmpArray = newSpace;
	//更新新职工人数
	this->m_EmpNum = newSize;
	//提示添加成功
	cout << "成功添加" << addNum << "名新职工" << endl;
	//更新职工不为空
	this->m_FileIsEmpty = false;
	//保存数据文件
	this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");

}
void WorkManger::Show_Menu()
{
	cout << "***************************"<<endl;
	cout << "***欢迎使用职工管理系统****"<<endl;
	cout << "******0.退出管理程序*******" << endl;
	cout << "******1.增加职工信息*******" << endl;
	cout << "******2.显示职工信息*******" << endl; 
	cout << "******3.删除离职职工*******" << endl;
	cout << "******4.修改职工信息*******" << endl;
	cout << "******5.查找职工信息*******" << endl;
	cout << "******6.按照编号排序*******" << endl;
	cout << "******7.清空所有文档*******" << endl;
	cout << "***************************" << endl;
	cout << endl;
}
int WorkManger::IsExit(int id)//按照职工编号判断是否存在，若存在则返回职工在数组中的位置，不存在则返回-1

{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (id == this->m_EmpArray[i]->m_id) {
			index = i;
			break;
		}
	
	}
	return index;

}
void WorkManger::Del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空！" << endl;
	}
	else
	{
		cout << "请输入要查找的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//说明职工存在，并且要删除index位置上的职工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//数据前移
			}
			this->m_EmpNum--;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，为找到该职工"<<endl;
		}
		system("pause");
		system("cls");
	
	}

}
void WorkManger::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！"<<endl;
	}

	else {
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[id];

			int newid = 0;
			string newname = "";
			int dslect = 0;

			cout << "查到：" << id << "号员工，请输入新职工编号：" << endl;
			cin >> newid;

			cout << "请输入姓名：" << endl;
			cin >> newname;

			cout << "请输入岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dslect;

			worker *worker = NULL;
			switch (dslect) {
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manger(newid, newname, 2);
				break;
			case 3:
				worker = new boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << this->m_EmpArray[ret]->m_DeptId << endl;

			//保存到文件中
			this->save();
		
		}
		else
		{
			cout << "修改失败，查无此人！"<<endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManger::Find_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;

		if (select ==1)
		{
			int id = 0;
			cout << "请输入要查找的id：" << endl;
			cin >> id;

			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[id]->showInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}

		}
		if (select == 2)
		{
			string name = " ";
			cout << "请输入要查找的姓名：" << endl;
			cin >> name;

			bool flag = false;//查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功！职工编号为："
						<< m_EmpArray[i]->m_id
						<< "号的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();

				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;

			}
		
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManger::Sort_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum-1; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
			    else//降序
				{
					if (m_EmpArray[minOrMax]->m_id < m_EmpArray[j]->m_id)
					{
							minOrMax = j;
					}					
				}
				
			}			
			if (i != minOrMax)
			{
				worker *temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}                    
		cout << "排序成功！排序后结构为：" << endl;
		this->save();
		this->show_Emp();

	}


}
void WorkManger::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开ios::trunc 如果存在 删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 1; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		
		}
		cout << "清空成功！" << endl;

	
	}
	system("pause");
	system("cls");
}