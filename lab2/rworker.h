#pragma once
#include <windows.h>
#include <vector>

class RWorker
{
	HANDLE hUpdateEvt; //событие "данные обновились"
	HANDLE hStopEvt;   //событие "конец работы"
	HANDLE hMutex;  //защита данных
	HANDLE hMutex1;

	int    DATA;    //очень важные данные

	std::vector<int> log1;
	std::vector<int> log2;

	HANDLE hThread1;
	HANDLE hThread2;
public:
	RWorker();
	~RWorker();

	int getData();
	void setData(int val);

	int getLog1();
	int getLog2();

	void setLog1(int val);
	void setLog2(int val);
	bool isDataUpdated();

	void startWorkBoth();
	void stopWork();
	
private:
	static DWORD WINAPI ThreadFunc_1(LPVOID ptr);
	static DWORD WINAPI ThreadFunc_2(LPVOID ptr);

};

class MutexLocker
{
	HANDLE hMutex;
public:
	MutexLocker(HANDLE mutex)
		:hMutex(mutex)
	{
		WaitForSingleObject(hMutex, INFINITE);
	}
	~MutexLocker()
	{
		ReleaseMutex(hMutex);
	}
};

