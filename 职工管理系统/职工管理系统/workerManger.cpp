#include "workerManger.h"

WorkManger::WorkManger() {

	//��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;

	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������"<<endl;//�������
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
		cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;	
	}
	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;//���³�Ա����

	//���ٿռ�
	this->m_EmpArray = new worker*[this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_id
			<< "\t������" << this->m_EmpArray[i]->m_name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0;i < m_EmpNum; i++)
		{//���ö�̬��ʾ
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
		//���ݲ�ͬ����Id������ͬ����
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}//����
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
		num++;//��¼����
	}
	ifs.close();
	return num;

}
void WorkManger::exitSystem() {

	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);


}
void WorkManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�  -д�ļ�

	for (int i = 0; i <this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "\t"
			<< this->m_EmpArray[i]->m_name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;	
	}
	ofs.close();

}
void WorkManger::Add_Emp() {
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
	//���
	//�����¿ռ��С
	int newSize = this->m_EmpNum + addNum;//�¿ռ�����		
											  
	//�����¿ռ�
	worker ** newSpace = new worker*[newSize];
	//��ԭ���ռ������ݣ��������¿ռ���
	if (this->m_EmpNum != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			newSpace[i] = this->m_EmpArray[i];

		}
	}
	//�����������
	for (int i = 0; i < addNum; i++)
	{
		int id;
		string name;
		int dslect;
		cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
		cin >> id;
		cout << "�������" << i + 1 << "����ְ��������" << endl;
		cin >> name;
		cout << "��ѡ���ְ����λ��" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
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
		//������ְ�����浽������
		newSpace[this->m_EmpNum + i] = worker;

	
	}
	//�ͷ�ԭ�пռ�
	delete[] this->m_EmpArray;
	//�����¿ռ�ָ��
	this->m_EmpArray = newSpace;
	//������ְ������
	this->m_EmpNum = newSize;
	//��ʾ��ӳɹ�
	cout << "�ɹ����" << addNum << "����ְ��" << endl;
	//����ְ����Ϊ��
	this->m_FileIsEmpty = false;
	//���������ļ�
	this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}
void WorkManger::Show_Menu()
{
	cout << "***************************"<<endl;
	cout << "***��ӭʹ��ְ������ϵͳ****"<<endl;
	cout << "******0.�˳��������*******" << endl;
	cout << "******1.����ְ����Ϣ*******" << endl;
	cout << "******2.��ʾְ����Ϣ*******" << endl; 
	cout << "******3.ɾ����ְְ��*******" << endl;
	cout << "******4.�޸�ְ����Ϣ*******" << endl;
	cout << "******5.����ְ����Ϣ*******" << endl;
	cout << "******6.���ձ������*******" << endl;
	cout << "******7.��������ĵ�*******" << endl;
	cout << "***************************" << endl;
	cout << endl;
}
int WorkManger::IsExit(int id)//����ְ������ж��Ƿ���ڣ��������򷵻�ְ���������е�λ�ã��������򷵻�-1

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
		cout << "�ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//����ǰ��
			}
			this->m_EmpNum--;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�Ϊ�ҵ���ְ��"<<endl;
		}
		system("pause");
		system("cls");
	
	}

}
void WorkManger::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}

	else {
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = IsExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[id];

			int newid = 0;
			string newname = "";
			int dslect = 0;

			cout << "�鵽��" << id << "��Ա������������ְ����ţ�" << endl;
			cin >> newid;

			cout << "������������" << endl;
			cin >> newname;

			cout << "�������λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptId << endl;

			//���浽�ļ���
			this->save();
		
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�"<<endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManger::Find_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;

		if (select ==1)
		{
			int id = 0;
			cout << "������Ҫ���ҵ�id��" << endl;
			cin >> id;

			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[id]->showInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}

		}
		if (select == 2)
		{
			string name = " ";
			cout << "������Ҫ���ҵ�������" << endl;
			cin >> name;

			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< m_EmpArray[i]->m_id
						<< "�ŵ���Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();

				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�" << endl;

			}
		
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManger::Sort_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum-1; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
			    else//����
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
		cout << "����ɹ��������ṹΪ��" << endl;
		this->save();
		this->show_Emp();

	}


}
void WorkManger::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ios::trunc ������� ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;

	
	}
	system("pause");
	system("cls");
}