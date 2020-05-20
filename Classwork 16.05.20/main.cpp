#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <time.h>
#include <Time.h>
#include <ctime>
#include <windows.h>

#include "QueuePushPriority.h"
#include "QueuePriority.h"

using namespace std;
//#define MAX 256





void main()
{
	QueuePushPriority q(25);

	for (int i{}; i < 5; i++)
	{
		q.push(rand() % 100, rand() % 10);
	}
	cout << q;

	q.push(333, 1);
	cout << q;

	q.push(3, 3);
	cout << q;

	q.pop();
	cout << q;

	q.pop();
	cout << q;

	QueuePriority a(25);

	for (int i{}; i < 5; i++)
	{
		a.push(rand() % 100, rand() % 10);
	}
	cout << a;

	a.push(555, 2);
	cout << a;

	a.push(5, 1);
	cout << a;

	a.pop();
	cout << a;

	a.pop();
	cout << a;
}