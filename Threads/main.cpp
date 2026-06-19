#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono_literals;

bool finish = false;
char symbol = 43;
//std::mutex mutex;

void Plus(std::mutex& mutex)
{
	while (!finish)
	{
		mutex.lock();
		//symbol = '+';
		cout << "+ ";
		std::this_thread::sleep_for(100ms);
		mutex.unlock();
	}
}
void Minus(std::mutex& mutex)
{
	while (!finish)
	{
		mutex.lock();
		//symbol = '-';
		cout << "- ";
		std::this_thread::sleep_for(100ms);
		mutex.unlock();
	}
}
//void Print()
//{
//	while (!finish)
//	{
//		mutex.lock();
//		cout << symbol;
//		std::this_thread::sleep_for(100ms);
//		mutex.unlock();
//	}
//}

void main()
{
	setlocale(LC_ALL, "");
	//Plus();
	//Minus();
	std::mutex mutex;
	std::thread plus_thread(Plus,mutex);
	std::thread minus_thread(Minus,mutex);
	//std::thread print_thread(Print);


	cin.get();		//ќжидает нажатие 'Enter'
	finish = true;

	//if(print_thread.joinable())print_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
	if(plus_thread.joinable())plus_thread.join();
}