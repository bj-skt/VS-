#pragma once
#include<iostream>//�������������ͷ�ļ�
#include"worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�
class boss :public worker
{
public:

	boss(int id, string name, int dId);
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptNmae();
};