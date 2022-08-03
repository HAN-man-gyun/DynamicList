#pragma once
#include "Queue.h"
#include <iostream>

void Initialize(Queue& queue)
{
	queue.pHead = nullptr;
	queue.pTail = nullptr;
}

void DeleteAll(Queue& queue)
{
	Element* pElement{ queue.pTail };
	Element* pPrev{};
	while (pElement != nullptr)
	{
		pPrev = pElement->pPrev;
		delete pElement;
		pElement = pPrev;
	}
	Initialize(queue);

}

void Enqueue(Queue& queue, int value)
{
	Element* pElement = new Element{};
	pElement->value = value;
	if (queue.pHead == nullptr)
	{
		queue.pHead = pElement;
		queue.pTail = pElement;
		
	}
	else
	{
		queue.pTail ->pNext = pElement;
		queue.pTail = pElement;
	}
}

bool Dequeue(Queue& queue)
{
	if (queue.pHead == nullptr)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return false;
	}
	Element* pNextHead{ queue.pHead };
	queue.pHead = queue.pHead->pNext;
	std::cout << "Dequeue : " << pNextHead->value << std::endl;
	delete pNextHead;
	return true;
}

void Print(Queue& queue)
{
	Element* pElement = queue.pHead;
	while (pElement != nullptr)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}
