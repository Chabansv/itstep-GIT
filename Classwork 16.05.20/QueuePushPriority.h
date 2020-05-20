#pragma once
#ifndef QUEUE_PUSH_PRIORITY_H
#define QUEUE_PUSH_PRIORITY_H
#include<iostream>

class QueuePushPriority
{
private:
	int* _arr;
	int* _pri;
	int _capacity; //вместимость
	int _count;
public:
	QueuePushPriority(int capacity);
	~QueuePushPriority();
	void push(int val, int priority);
	void pop();
	void clear();
	//Проверка существования элементов в очереди
	bool isEmpty();
	// Проверка на переполнение очереди
	bool isFull();

	int getCount();

	friend std::ostream& operator << (std::ostream& out, const QueuePushPriority& q);

};

#endif

