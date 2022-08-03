#pragma once
#include<iostream>
#include"stack.h"

void Initialize(Stack& stack)
{
	stack.count = 0;
	stack.pTop = nullptr;
}

void DeleteAll(Stack& stack)
{
	Element* pElement{ stack.pTop };
	Element* pNext{};
	while (pElement != nullptr)
	{
		pNext = pElement->pNext;
		delete pElement;
		pElement = pNext;
	}
	Initialize(stack);
}

void Push(Stack& stack, int value)
{
	Element* pElement = new Element{};
	pElement->value = value;
	pElement->pNext = stack.pTop;
	stack.pTop = pElement;

	stack.count++;
}
bool Pop(Stack& stack)
{
	if (stack.count == 0)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return false;
	}
	Element* pPrevTop { stack.pTop };
	stack.pTop = stack.pTop->pNext;
	stack.count--;
	std::cout << "pop : " << pPrevTop->value << std::endl;
	delete pPrevTop;
	return true;
}
void Print(Stack& stack)
{
	Element* pElement = stack.pTop;
	while (pElement != nullptr)
	{
		std::cout << pElement->value << std::endl;
		pElement = pElement->pNext;
	}
}