#include"employee.h"
#include<string>
Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;

}

//��ʾ������Ϣ
void Employee::showInfo(){
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\t��λְ����ɾ�����������" << endl;


}
//��ȡ��λ����
string Employee::getDeptNmae(){
	return string("Ա��");
}