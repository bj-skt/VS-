#include"boss.h"
boss::boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_name = name;
	this->m_DeptId = dId;

}
void boss::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getDeptNmae()
		<< "\t岗位职责：管理公司所有事物" << endl;


}
//获取岗位名称
string boss::getDeptNmae() {

	return string("总裁");


}