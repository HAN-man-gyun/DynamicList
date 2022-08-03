#include <iostream>
#include "stack.h"
//솔루션 탐색기에서 굵은 글씨가 현재 실행이되는 시작프로젝트를 나타낸다.
void PrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] push" << std::endl;
	std::cout << "[2] pop" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "-------------" << std::endl;
}
void ProcessUserInput(Stack& stack)
{
	int command{};
	bool isExit{ false };
	while (true)
	{
		Print(stack);
		std::cout << std::endl;
		std::cout << ">";
		std::cin >> command;
		switch (command)
		{
			case PUSH:
			{
				int value;
				std::cout << "         value :";
				std::cin >> value;
				Push(stack, value);
				break;
			}
			case POP:
			{
				Pop(stack);
				break;
			}
			case EXIT:
			{
				isExit = true;
				break;
			}
			default:
			{
				std::cout << "Invalid Command!" << std::endl;
				break;
			}
		}
	}
}
int main()
{
	Stack myStack;
	Initialize(myStack);
	PrintInfo();
	ProcessUserInput(myStack);
	DeleteAll(myStack);
}