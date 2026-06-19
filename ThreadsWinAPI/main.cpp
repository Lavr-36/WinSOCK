#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

bool finish = false;

HANDLE ghMutex = NULL;

void Plus()
{
	while (!finish)
	{
		WaitForSingleObject(ghMutex, INFINITE);
		cout << "+ ";
		Sleep(1);
		ReleaseMutex(ghMutex);
	}
}
void Minus()
{
	while (!finish)
	{
		WaitForSingleObject(ghMutex, INFINITE);
		cout << "- ";
		Sleep(1);
		ReleaseMutex(ghMutex);
	}
}

void main()
{
	setlocale(LC_ALL, "");
	ghMutex = CreateMutex(NULL, FALSE, NULL);
	HANDLE hThreads[2] = {};
	hThreads[0] = CreateThread
	(
		NULL,
		NULL,
		(LPTHREAD_START_ROUTINE)Plus,
		NULL,
		NULL,
		NULL
	);
	hThreads[1] = CreateThread
	(
		NULL,
		NULL,
		(LPTHREAD_START_ROUTINE)Minus,
		NULL,
		NULL,
		NULL
	);
	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
}