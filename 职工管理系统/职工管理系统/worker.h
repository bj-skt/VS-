#pragma once
#include<iostream>//�������������ͷ�ļ�
#include<string>
using namespace std;//ʹ�ñ�׼�����ռ�

class worker {
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptNmae() = 0;
	//ְ�����
	int m_id;
	//ְ������
	string m_name;
	//ְ�����ڲ������Ʊ��
	int m_DeptId;
};