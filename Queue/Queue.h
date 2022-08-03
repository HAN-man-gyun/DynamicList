#pragma once
enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};
struct Element
{
	int value;
	Element* pNext;
	Element* pPrev;
};


struct Queue
{
	Element* pHead;
	Element* pTail;
};
void Initialize(Queue& queue);
void DeleteAll(Queue& queue);
void Enqueue(Queue& queue, int value);
bool Dequeue(Queue& queue);
void Print(Queue& queue);
