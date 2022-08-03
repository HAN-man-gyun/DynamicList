#include <iostream>
#include "Queue.h"
void PrintInfo()
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl;
	std::cout << "[2] DEQUEUE" << std::endl;
	std::cout << "[3] EXIT" << std::endl;
	std::cout << "-------------" << std::endl;
}
void ProcessUserInput(Queue& queue)
{
	int command{};
	bool isExit{ false };
	while (true)
	{
		Print(queue);
		std::cout << std::endl;
		std::cout << ">";
		std::cin >> command;
		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "         value :";
			std::cin >> value;
			Enqueue(queue, value);
			break;
		}
		case DEQUEUE:
		{
			Dequeue(queue);
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
	Queue myQueue;
	Initialize(myQueue);
	PrintInfo();
	ProcessUserInput(myQueue);
	DeleteAll(myQueue);
}