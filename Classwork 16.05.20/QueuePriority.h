#pragma once
#ifndef QUEUE_PRIORITY_H
#define QUEUE_PRIORITY_H
#include<iostream>

class QueuePriority
{
private:
	int* _arr;
	int* _pri;
	int _capacity;
	int _count;
public:
	QueuePriority(int capacity);
	~QueuePriority();
	void push(int val, int priority);
	int pop();
	void clear();
	bool isEmpty();
	bool isFull();
	int getCount();

	friend std::ostream& operator << (std::ostream& out, const QueuePriority& q);

};


#endif

