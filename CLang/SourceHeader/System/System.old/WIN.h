//SystemAPI
//Windows

//Default
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<random>

//System
#include<Windows.h>

//DIRECTORY_API
#include <vector>
#include<ShlObj.h>
#include <io.h>
#include<direct.h>

void _DirRemove(string dir) {
	//��Ŀ¼�������"\\*.*"���е�һ������
	string newDir = dir + "\\*.*";
	//���ڲ��ҵľ��
	intptr_t handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(newDir.c_str(), &fileinfo);

	if (handle == -1) {
		//cout << "���ļ�" << endl;
		return;
	}

	do
	{
		if (fileinfo.attrib & _A_SUBDIR) {//���Ϊ�ļ��У������ļ���·�����ٴα���
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
				continue;

			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			newDir = dir + "\\" + fileinfo.name;
			_DirRemove(newDir.c_str());//�ȱ���ɾ���ļ����µ��ļ�����ɾ���յ��ļ���
			//cout << newDir.c_str() << endl;
			if (_rmdir(newDir.c_str()) == 0) {//ɾ�����ļ���
				//cout << "delete empty dir success" << endl;
			}
			else {
				//cout << "delete empty dir error" << endl;
			}
		}
		else {
			string file_path = dir + "\\" + fileinfo.name;
			//cout << file_path.c_str() << endl;
			if (remove(file_path.c_str()) == 0) {//ɾ���ļ�
				//cout << "delete file success" << endl;
			}
			else {
				//cout << "delete file error" << endl;
			}
		}
	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	rmdir(dir.c_str());
	return;
}

