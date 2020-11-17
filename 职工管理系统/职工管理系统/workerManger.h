#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
#include<string>
#include"worker.h"
#include"manger.h"
#include"boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "emFile.txt"
using namespace std;//使用标准命名空间



class WorkManger {
public:
	//标志文件是否为空
	bool m_FileIsEmpty;
	int get_EmpNum();
	//构造函数
	WorkManger();
	//展示菜单
	void Show_Menu();
	//初始化员工
	void init_Emp();
	//显示职工
	void show_Emp();

	//删除职工
	void Del_Emp();
	//判断职工是否存在
	int IsExit(int id);

	void exitSystem();
	//析构函数
	~WorkManger();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	worker **m_EmpArray;
	//添加职工
	void Add_Emp();
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序职工
	void Sort_Emp();
	//清空文件
	void Clean_File();
	//保存函数
	void save();
};