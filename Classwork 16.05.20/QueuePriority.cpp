#include "QueuePriority.h"

QueuePriority::QueuePriority(int capacity)
{
	_capacity = capacity;
	_arr = new int[_capacity];
	_pri = new int[_capacity];
	_count = 0;


}

QueuePriority::~QueuePriority()
{
	delete[]_arr;
	_arr = nullptr;
	delete[]_pri;
	_pri = nullptr;
}

void QueuePriority::push(int val, int priority)
{
	if (!isFull())
		_arr[_count] = val;
	_pri[_count] = priority;
	_count++;
}

int QueuePriority::pop()
{
	if (!isEmpty()) {
		int maxPri = 0;
		int posMaxPri = 0;

		for (int i{}; i < _count; i++) {
			if (maxPri < _pri[i]) {
				maxPri = _pri[i];
				posMaxPri = i;
			}
		}
		int val = _arr[posMaxPri];
		for (int i = posMaxPri; i < _count - 1; i++) {
			_arr[i] = _arr[i + 1];
			_pri[i] = _pri[i + 1];
		}
		--_count;

		return val;
	}
	else

		return -1;
}

void QueuePriority::clear()
{
	_count = 0;
}

bool QueuePriority::isEmpty()
{
	return _count == 0;
}

bool QueuePriority::isFull()
{
	return _count == _capacity;
}

int QueuePriority::getCount()
{
	return _count;
}

std::ostream& operator<<(std::ostream& out, const QueuePriority& q)
{
	for (int i{}; i < q._count; i++) {
		out << q._arr[i] << " - " << q._pri[i] << "\n\n";
	}
	out << "----------------------------------------------\n";
	return out;
}