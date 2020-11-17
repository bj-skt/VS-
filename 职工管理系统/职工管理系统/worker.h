#pragma once
#include<iostream>//包含输入输出流头文件
#include<string>
using namespace std;//使用标准命名空间

class worker {
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptNmae() = 0;
	//职工编号
	int m_id;
	//职工姓名
	string m_name;
	//职工所在部门名称编号
	int m_DeptId;
};