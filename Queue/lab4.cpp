#include <iostream>
#include "Tqueue.h"

void main() {
	/*
	top
	0,1,2,3,4,5,6,7,8,9 - индексы элементов массива
	*/

	TQueue<int> q(10);
	int elem;

	std::cout << "empty: " << q.IsEmpty() << '\n';
	std::cout << "full: " << q.IsFull() << '\n';

	for (int i = 0; i < 10; i++) {
		std::cin >> elem;
		q.Push(elem);
	}

	std::cout << "empty: " << q.IsEmpty() << '\n';
	std::cout << "full: " << q.IsFull() << '\n';

	for (int i = 0; i < 5; i++)
		std::cout << q.Pop() << ' ';

	std::cout << '\n';

	for (int i = 0; i < 4; i++) {
		std::cin >> elem;
		q.Push(elem);
	}

	std::cout << "empty: " << q.IsEmpty() << '\n';
	std::cout << "full: " << q.IsFull() << '\n';

	for (int i = 0; i < 9; i++)
		std::cout << q.Pop() << ' ';

	std::cout << '/n';
}