#include "worker.h"

Worker::Worker()
{
	
	selection = 0;
	hMutex = CreateMutex(NULL, FALSE, NULL);
	InitializeCriticalSection(&critSec);
	hEvent = CreateEvent(NULL, FALSE, TRUE, NULL);
	hSem = CreateSemaphore(NULL, 1, 1, NULL);

	
	DATA = 0;

	hThread = INVALID_HANDLE_VALUE;
	hThread2 = INVALID_HANDLE_VALUE;

	
}

Worker::~Worker()
{
	if (hThread != NULL) CloseHandle(hThread);
	if (hThread2 != NULL) CloseHandle(hThread2);
	DeleteCriticalSection(&critSec);
	CloseHandle(hMutex);
	CloseHandle(hEvent);
	CloseHandle(hSem);
	
}

void Worker::startWorkBoth()
{
	if (hThread != INVALID_HANDLE_VALUE || hThread2 != INVALID_HANDLE_VALUE) return; //уже запущен
	
	hThread = CreateThread(NULL, 0, ThreadFunc_1, this, 0, NULL); //запускаем в работу
	hThread2 = CreateThread(NULL, 0, ThreadFunc_2, this, 0, NULL);
}


void Worker::stopWork()
{
	log1.clear();
	log2.clear();

	if (hThread == INVALID_HANDLE_VALUE) return;
	

	if (WaitForSingleObject(hThread, 5000) != WAIT_OBJECT_0)
	{
		TerminateThread(hThread, 1);
	}

	CloseHandle(hThread);
	hThread = INVALID_HANDLE_VALUE;

	if (hThread2 == INVALID_HANDLE_VALUE) return;
	

	if (WaitForSingleObject(hThread2, 5000) != WAIT_OBJECT_0)
	{
		TerminateThread(hThread2, 1);
	}

	CloseHandle(hThread2);
	hThread2 = INVALID_HANDLE_VALUE;
}

int Worker::getData()
{
	return DATA;
}

void Worker::setData(int val)
{
	DATA = val;
}

std::vector<int> Worker::getLog1()
{
	
	if (log1.size() > 0)
		return log1;
	
}

void Worker::setLog1(int val)
{
	
	log1.push_back(val);


}

std::vector<int> Worker::getLog2()
{
	
	if (log1.size() > 0)
		return log1;
	
}

void Worker::setLog2(int val)
{
	
	log2.push_back(val);
	

}



int Worker::getSelection()
{
	return selection;
}

void Worker::setSelection(int val) {
	selection = val;
}

DWORD WINAPI Worker::ThreadFunc_1(LPVOID ptr)
{
	Worker* _this = (Worker*)ptr;
	if (!_this) return 1;
	
	int  j = 0;
	int n = 30;
	for (j = 0; j < n; j++)
	{
		if (_this->getSelection() == 1)				EnterCriticalSection(&_this->critSec);
		if (_this->getSelection() == 2)			WaitForSingleObject(_this->hMutex, INFINITE);
		if (_this->getSelection() == 3)		WaitForSingleObject(_this->hEvent, INFINITE);
		if (_this->getSelection() == 4)   	WaitForSingleObject(_this->hSem, INFINITE);
		
		_this->setData(_this->getData() - 3);
		Sleep(1);
		_this->setData(_this->getData() + 3);
		
		_this->setLog1(_this->getData());

		if (_this->getSelection() == 1)				LeaveCriticalSection(&_this->critSec);
		if (_this->getSelection() == 2)			ReleaseMutex(_this->hMutex);
		if (_this->getSelection() == 3)		SetEvent(_this->hEvent);
		if (_this->getSelection() == 4)   ReleaseSemaphore(_this->hSem, 1, NULL);
		Sleep(1);
	}

	return 0;
}

DWORD WINAPI Worker::ThreadFunc_2(LPVOID ptr)
{
	Worker* _this = (Worker*)ptr;
	if (!_this) return 1;

	int  j = 0;
	int n = 30;
	for (j = 0; j < n; j++)
	{
		if (_this->getSelection() == 1)				EnterCriticalSection(&_this->critSec);
		if (_this->getSelection() == 2)			WaitForSingleObject(_this->hMutex, INFINITE);
		if (_this->getSelection() == 3)		WaitForSingleObject(_this->hEvent, INFINITE);
		if (_this->getSelection() == 4)   	WaitForSingleObject(_this->hSem, INFINITE);

		_this->setData(_this->getData() - 3);
		Sleep(1);
		_this->setData(_this->getData() + 3);
		
		_this->setLog2(_this->getData());

		if (_this->getSelection() == 1)				LeaveCriticalSection(&_this->critSec);
		if (_this->getSelection() == 2)			ReleaseMutex(_this->hMutex);
		if (_this->getSelection() == 3)		SetEvent(_this->hEvent);
		if (_this->getSelection() == 4)   ReleaseSemaphore(_this->hSem, 1, NULL);
		Sleep(1);
	}


	return 0;
}

