#include "Queue.h"


Queue::Queue(int capacity)
{
	_capacity = capacity;
	_arr = new int[_capacity];
	_count = 0;
}

Queue::~Queue()
{
	delete[]_arr;
	_arr = nullptr;
}

void Queue::add(int c)
{
	if (!isFull())
		_arr[_count++] = c;

}

int Queue::extract()
{
	if (!isEnpty())
	{
		int temp = _arr[0];

		for (int i = 1; i < _count; i++)
		{
			_arr[i - 1] = _arr[i];
		}

		_arr[_count - 1] = temp;
		//--_count;
		return temp;
	}
	return -1;
}

void Queue::clear()
{
	_count = 0;
}

bool Queue::isEnpty()
{
	return _count == 0;
}

bool Queue::isFull()
{
	return _count == _capacity;
}

int Queue::getCount()
{
	return _count;
}

void Queue::show()
{
	cout << "-----------------------------\n";

	for (int i{}; i < _count; i++)
		cout << _arr[i] << " ";

	cout << "\n-----------------------------\n";
}