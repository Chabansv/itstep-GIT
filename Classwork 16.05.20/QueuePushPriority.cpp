#include "QueuePushPriority.h"

QueuePushPriority::QueuePushPriority(int capacity)
{
	_capacity = capacity;
	_arr = new int[_capacity];
	_pri = new int[_capacity];
	_count = 0;
}

QueuePushPriority::~QueuePushPriority()
{
	delete[]_arr;
	_arr = nullptr;
	delete[]_pri;
	_pri = nullptr;
}

void QueuePushPriority::push(int val, int priority)
{
	_arr[_count] = val;
	_pri[_count] = priority;
	_count++;

	if (!isEmpty())
	{
		int temp; // временная переменная для обмена элементов местами
		int temp2;
		// Сортировка массива
		for (int i = 0; i < _count - 1; i++)
		{
			for (int j = 0; j < _count - i - 1; j++)
			{
				if (_pri[j] > _pri[j + 1]) {

					temp = _pri[j];
					temp2 = _arr[j];

					_pri[j] = _pri[j + 1];
					_arr[j] = _arr[j + 1];

					_pri[j + 1] = temp;
					_arr[j + 1] = temp2;
				}
			}
		}
	}


}


void QueuePushPriority::pop()
{
	if (!isFull())
	{
		for (int i = 0; i < _count; i++)
		{
			_arr[i] = _arr[i + 1];
			_pri[i] = _pri[i + 1];
		}
		--_count;
	}
}

void QueuePushPriority::clear()
{
	_count = 0;
}

bool QueuePushPriority::isEmpty()
{
	return _count == 0;
}

bool QueuePushPriority::isFull()
{
	return _count == _capacity;
}

int QueuePushPriority::getCount()
{
	return _count;
}

std::ostream& operator<<(std::ostream& out, const QueuePushPriority& q)
{
	for (int i{}; i < q._count; i++) {
		out << q._arr[i] << " - " << q._pri[i] << "\n\n";
	}
	out << "----------------------------------------------\n";
	return out;
}
