#pragma once

template <class T>
class TQueue
{
	T* Array;
	int MaxSize;
	int Head, Tail;
	int CountEl;

public:
	TQueue(int size = 10) {
		if (size < 0)
			throw gcnew System::Exception("Can't create queue with negative size");

		MaxSize = size;
		Array = new T[MaxSize];
		Head = 0;
		Tail = -1;
		CountEl = 0;
	}

	~TQueue() {
		delete[] Array;
	}

	bool IsEmpty() {
		if (CountEl == 0)
			return true;
		return false;
	}

	bool IsFull() {
		if (CountEl == MaxSize)
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
			throw gcnew System::Exception("Queue is full");
	}

	T Pop() {
		if (!IsEmpty()) {
			T res = Array[Head];
			Head = (Head + 1) % MaxSize;
			CountEl--;
			return res;
		}
		else
			throw gcnew System::Exception("Queue is empty");
	}

	int GetHead() {
		return Head;
	}

	int GetMaxSize() {
		return MaxSize;
	}

	int GetSize() {
		return CountEl;
	}

};