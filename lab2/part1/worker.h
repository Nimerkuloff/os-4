#pragma once
#include <windows.h>
#include <vector>

class Worker
{
	
	HANDLE hMutex;  
	HANDLE hEvent,  hSem;
	CRITICAL_SECTION critSec;
	

	int    DATA;    
	int selection;
	std::vector<int> log1;
	std::vector<int> log2;

	HANDLE hThread;
	HANDLE hThread2;
public:
	Worker();
	~Worker();

	int getData();
	void setData(int val);

	std::vector<int> getLog1();
	void setLog1(int val);
	
	std::vector<int> getLog2();
	void setLog2(int val);

	
	
	int getSelection();
	void setSelection(int val);

	void startWorkBoth();
	void stopWork();
	
private:
	static DWORD WINAPI ThreadFunc_1(LPVOID ptr);
	static DWORD WINAPI ThreadFunc_2(LPVOID ptr);

};


