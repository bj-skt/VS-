#include"boss.h"
boss::boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;

}
void boss::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\t��λְ�𣺹���˾��������" << endl;


}
//��ȡ��λ����
string boss::getDeptNmae() {

	return string("�ܲ�");


}