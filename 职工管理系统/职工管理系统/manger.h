#pragma once
#include<iostream>//�������������ͷ�ļ�
#include"worker.h"
using namespace std;//ʹ�ñ�׼�����ռ�
class Manger :public worker
{
public:

	Manger(int id, string name, int dId);
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptNmae();




};