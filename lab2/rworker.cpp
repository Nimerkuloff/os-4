#include "rworker.h"

RWorker::RWorker()
{
	hUpdateEvt = CreateEvent(NULL, TRUE, TRUE, NULL);
	hStopEvt = CreateEvent(NULL, TRUE, TRUE, NULL);
	hMutex = CreateMutex(NULL, FALSE, NULL);
	

	DATA = 0;
	hThread1 = INVALID_HANDLE_VALUE;
	hThread2 = INVALID_HANDLE_VALUE;
}

RWorker::~RWorker()
{
	stopWork();  
	CloseHandle(hUpdateEvt);
	CloseHandle(hStopEvt);
	CloseHandle(hMutex);
}

void RWorker::startWorkBoth()
{
	if (hThread1 != INVALID_HANDLE_VALUE || hThread2 != INVALID_HANDLE_VALUE) return; //уже запущен
	ResetEvent(hStopEvt); //перед началом работы сбрасываем флаг остановки
	hThread1 = CreateThread(NULL, 0, ThreadFunc_1, this, 0, NULL); //запускаем в работу
	hThread2 = CreateThread(NULL, 0, ThreadFunc_2, this, 0, NULL);
}

void RWorker::stopWork()
{
	if (hThread1 == INVALID_HANDLE_VALUE) return;
	SetEvent(hStopEvt);

	if (WaitForSingleObject(hThread1, 5000) != WAIT_OBJECT_0)
	{
		TerminateThread(hThread1, 1);
	}

	CloseHandle(hThread1);
	hThread1 = INVALID_HANDLE_VALUE;

	if (hThread2 == INVALID_HANDLE_VALUE) return;
	

	if (WaitForSingleObject(hThread2, 5000) != WAIT_OBJECT_0)
	{
		TerminateThread(hThread2, 1);
	}

	CloseHandle(hThread2);
	hThread2 = INVALID_HANDLE_VALUE;
}

int RWorker::getData()
{
	return DATA;
}

void RWorker::setData(int val)
{
	DATA = val;
}

int RWorker::getLog1()
{
	MutexLocker guard(hMutex);
	ResetEvent(hUpdateEvt);
	if (log1.size() > 0)
		return log1.back();
	else
		return 0;
}

void RWorker::setLog1(int val)
{
	MutexLocker guard(hMutex);
	log1.push_back(val);
	SetEvent(hUpdateEvt);
}

int RWorker::getLog2()
{
	MutexLocker guard(hMutex);
	ResetEvent(hUpdateEvt);
	if (log1.size() > 0)
		return log1.back();
	else
		return 0;
}

void RWorker::setLog2(int val)
{
	MutexLocker guard(hMutex);
	log2.push_back(val);
	SetEvent(hUpdateEvt);
}

bool RWorker::isDataUpdated()
{
	return WaitForSingleObject(hUpdateEvt, 0) == WAIT_OBJECT_0;
}

DWORD WINAPI RWorker::ThreadFunc_1(LPVOID ptr)
{
	RWorker* _this = (RWorker*)ptr;
	if (!_this) return 1;

	for (;;)
	{
		WaitForSingleObject(_this->hMutex, INFINITE);
		_this->setData(_this->getData() - 3);
		Sleep(1);
		_this->setData(_this->getData() + 3);
		_this->setLog1(_this->getData());
		ReleaseMutex(_this->hMutex);
		if (WaitForSingleObject(_this->hStopEvt, 100) != WAIT_TIMEOUT)
			break;
	}

	return 0;
}

DWORD WINAPI RWorker::ThreadFunc_2(LPVOID ptr)
{
	RWorker* _this = (RWorker*)ptr;
	if (!_this) return 1;

	for (;;)
	{
		WaitForSingleObject(_this->hMutex, INFINITE);
		_this->setData(_this->getData() + 3);
		Sleep(1);
		_this->setData(_this->getData() - 3);
		_this->setLog2(_this->getData());
		ReleaseMutex(_this->hMutex);
		if (WaitForSingleObject(_this->hStopEvt, 100) != WAIT_TIMEOUT)
			break;
	}

	return 0;
}

