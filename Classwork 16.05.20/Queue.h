#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>

using namespace std;

class Queue
{
private:
	int* _arr;
	int _capacity;
	int _count;
public:
	Queue(int capacity);
	~Queue();
	void add(int c);
	int extract();
	void clear();
	bool isEnpty();
	bool isFull();
	int getCount();
	void show();
};

#endif

