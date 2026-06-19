// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	for (int i = 0; i < n; ++i)
	{
		mtx.lock();
		std::cout << c;
		mtx.unlock();
	}
	std::cout << '\n';
}

int main()
{
	std::thread th1(print_block, 5000, '*');
	std::thread th2(print_block, 5000, '$');

	th1.join();
	th2.join();

	return 0;
}