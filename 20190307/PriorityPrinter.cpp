#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) 
{
	priority_queue<int> priorityQueue;
	queue<int> printQueue;
	for (int i = 0; i < priorities.size(); i++)
	{
		priorityQueue.push(priorities[i]);
		printQueue.push(priorities[i]);
	}

	int printCount = 0;

	while (true)
	{
		if (printQueue.front() != priorityQueue.top())
		{
			int firstPrint = printQueue.front();
			printQueue.push(firstPrint);
			printQueue.pop();
		}
		else
		{
			priorityQueue.pop();
			printQueue.pop();

			printCount++;

			if (location == 0)
			{
				return printCount;
			}
		}

		location--;
		if (location < 0)
		{
			location = printQueue.size() - 1;
		}
	}
}