#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�
#include<string>
#include"worker.h"
#include"manger.h"
#include"boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "emFile.txt"
using namespace std;//ʹ�ñ�׼�����ռ�



class WorkManger {
public:
	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	int get_EmpNum();
	//���캯��
	WorkManger();
	//չʾ�˵�
	void Show_Menu();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void show_Emp();

	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ����
	int IsExit(int id);

	void exitSystem();
	//��������
	~WorkManger();
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	worker **m_EmpArray;
	//���ְ��
	void Add_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	//���溯��
	void save();
};