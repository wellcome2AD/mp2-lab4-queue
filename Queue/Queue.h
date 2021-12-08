#pragma once

template <class T>
class TQueue
{
	T* Array;
	int MaxSize;
	int Head, Tail;
	int CountEl;

	TQueue(int size = 10) {
		if (size < 0)
			throw "Can't create queue with negative size";

		MaxSize = size;
		Array = new T[MaxSize];
		Head = 0;
		Tail = -1;
		CountEl = 0;
	}

	~TQueue() {
		delete[] Array;
	}

	IsEmpty() {
		if (CountEl == 0)
			return true;
		return false;
	}

	IsFull() {
		if (CountEl == Maxsize - 1)
			return true;
		return false;
	}

	void Push(T el) {
		Tail = (Tail + 1) % MaxSize;
		if (!IsFull()) {
			Array[Tail] = el;
			CountEl++;
		}			
		else
			throw "Queue is full";
	}

	T Pop() {
		if (!IsEmpty()) {
			T res = Array[Head];
			Head = (Head + 1) % MaxSize;
			CountEl--;
			return res;
		}
		else
			throw "Queue is empty";			
	}

	//тесты: могу создать + размера, не могу -, могу добавить, извлечь, если полон/пуст - не могу

};