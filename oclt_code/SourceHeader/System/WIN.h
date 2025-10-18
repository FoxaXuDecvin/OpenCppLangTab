#pragma once
#include<Windows.h> 
#include<direct.h>
#include <fstream>
#include <io.h>
#include <string>
#include <vector>
#include<ShlObj.h>

const std::string Win32_kernel = "Win32";
const std::string Linux_kernel = "Linux";
std::string _windows_userprofile = getenv("userprofile");
const std::string _Build_Path = _windows_userprofile + "/.OpenCppLangTab";

char* stringtochar;
char* stringToCharX(std::string tomessage) {

	const int len = tomessage.length();

	stringtochar = new char[len + 1];

	strcpy(stringtochar, tomessage.c_str());

	return stringtochar;
}

//Design For Windows
const std::string pathsign = "\\";
std::string RunPlatfom = "Windows (MSVC 64Bit)";//Must Include Windows/Linux one
std::string _Run_SysKernel = Win32_kernel;
//Linux s   Windows  ms
//Default Use s
void sleepapi(int num) {
	int cutth = num * 1000;
	Sleep(cutth);
	return;
}

void cleanConsole() {
	system("cls");
}

void foldercreateapi(std::string dir) {
	_mkdir(dir.c_str());
}

bool check_file_existenceA(const std::string& filename) {
	std::ifstream file(filename);
	if (file.is_open()) {
		return true;
	}
	else {
		return false;
	}
}
//NET CORE

//Use Windows API  <URLMON.DLL>
#include<urlmon.h>
#pragma comment(lib,"URlmon.lib")

LPCWSTR stringToLPCWSTR(std::string orig)
{
	using namespace std;
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (orig.length() - 1)];
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	return wcstring;
}

//0-FAILED
//1-TRUE
bool URLDown(std::string URL, std::string Save) {
	using namespace std;
	remove(Save.c_str());

	LPCWSTR LcDsp = stringToLPCWSTR(Save);
	LPCWSTR LcURL = stringToLPCWSTR(URL);
	HRESULT applydownload = URLDownloadToFileW(
		nullptr,
		LcURL,
		LcDsp,
		0,
		nullptr
	);
	if (check_file_existenceA(Save)) {
		return true;
	}
	else {
		return false;
	}
	
}

//GetFilePath
// Resource File
std::string GetFilePath(void) {
	using namespace std;
	char szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
	/*
	strrchr:�������ܣ�����һ���ַ�c����һ���ַ���str��ĩ�γ��ֵ�λ�ã�Ҳ���Ǵ�str���Ҳ࿪ʼ�����ַ�c�״γ��ֵ�λ�ã���
	���������λ�õĵ�ַ�����δ���ҵ�ָ���ַ�����ô����������NULL��
	ʹ�������ַ���ش����һ���ַ�c��strĩβ���ַ�����
	*/
	(strrchr(szFilePath, '\\'))[0] = 0; // ɾ���ļ�����ֻ���·���ִ�//
	std::string path = szFilePath;
	return path;
}

std::string GetFileName(void) {
	using namespace std;
	char szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
	/*
	strrchr:�������ܣ�����һ���ַ�c����һ���ַ���str��ĩ�γ��ֵ�λ�ã�Ҳ���Ǵ�str���Ҳ࿪ʼ�����ַ�c�״γ��ֵ�λ�ã���
	���������λ�õĵ�ַ�����δ���ҵ�ָ���ַ�����ô����������NULL��
	ʹ�������ַ���ش����һ���ַ�c��strĩβ���ַ�����
	*/
	std::string path = szFilePath;
	return path;
}

int removeDirectoryAPIX(std::string dir) {
	using namespace std;
	//��Ŀ¼�������"\\*.*"���е�һ������
	std::string newDir = dir + "\\*.*";
	//���ڲ��ҵľ��
	intptr_t handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(newDir.c_str(), &fileinfo);

	if (handle == -1) {
		//cout << "���ļ�" << endl;
		return 1;
	}

	do
	{
		if (fileinfo.attrib & _A_SUBDIR) {//���Ϊ�ļ��У������ļ���·�����ٴα���
			if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
				continue;

			// ��Ŀ¼�������"\\"����������Ŀ¼��������һ������
			newDir = dir + "\\" + fileinfo.name;
			removeDirectoryAPIX(newDir.c_str());//�ȱ���ɾ���ļ����µ��ļ�����ɾ���յ��ļ���
			//cout << newDir.c_str() << endl;
			if (_rmdir(newDir.c_str()) == 0) {//ɾ�����ļ���
				//cout << "delete empty dir success" << endl;
			}
			else {
				//cout << "delete empty dir error" << endl;
			}
		}
		else {
			std::string file_path = dir + "\\" + fileinfo.name;
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

	_rmdir(dir.c_str());
	return 1;
}

std::string Process_cache;
void _fileapi_write(std::string _fa_file, std::string _fa_info);
std::string p1_filepath = GetFilePath();
void CreateFileMap_txt(std::string savefile,std::string dir) {
	using namespace std;
	//��Ŀ¼�������"\\*.*"���е�һ������
	std::string newDir = dir + "\\*.*";
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
			CreateFileMap_txt(savefile,newDir);//�ȱ���ɾ���ļ����µ��ļ�����ɾ���յ��ļ���
		}
		else {
			std::string file_path = dir + "\\" + fileinfo.name;
			Process_cache = file_path;
			Process_cache = ReplaceChar(Process_cache, p1_filepath, "");
			//cout << file_path.c_str() << endl;
			_fileapi_write(savefile, ReplaceChar(Process_cache, "\\", "/"));
		}
	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	return;
}
void CreateDirMap_txt(std::string savefile, std::string dir) {
	using namespace std;
	//��Ŀ¼�������"\\*.*"���е�һ������
	std::string newDir = dir + "\\*.*";
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
			//CreateFileMap_txt(savefile, newDir);//�ȱ���ɾ���ļ����µ��ļ�����ɾ���յ��ļ���
			_fileapi_write(savefile, ReplaceChar(newDir, "\\", "/") + "/");
		}
		else {
			std::string file_path = dir + "\\" + fileinfo.name;
			Process_cache = file_path;
			Process_cache = ReplaceChar(Process_cache, p1_filepath, "");
			//cout << file_path.c_str() << endl;
			_fileapi_write(savefile, ReplaceChar(Process_cache, "\\", "/"));
		}
	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	return;
}


char *envbuffer;
std::string _SystemAPI_getenv(std::string Environment) {
	using namespace std;
	envbuffer = getenv(Environment.c_str());
	if (envbuffer == NULL) {
		return "Null.SystemAPI.getenv --> NullEnv";
	}
	return envbuffer;
}

bool _Execute_Admin(std::string File, std::string Args) {
	using namespace std;
	return ShellExecute(0, "runas", File.c_str(), Args.c_str(), 0, SW_SHOW);
}

void sleepapi_ms(int secondsNum) {
	using namespace std;
	Sleep(secondsNum);
	return;
}