#pragma once
#include<iostream>//包含输入输出流头文件
#include"worker.h"
using namespace std;//使用标准命名空间
class Manger :public worker
{
public:

	Manger(int id, string name, int dId);
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptNmae();




};