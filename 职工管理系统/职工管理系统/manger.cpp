#include"manger.h"

Manger::Manger(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;

}
void Manger::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;


}
//��ȡ��λ����
string Manger::getDeptNmae() {

	return string("����");


}