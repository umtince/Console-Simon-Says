#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <thread>
#include <chrono>

class Node {

public:
	char value;
	Node* next = NULL;

	Node() : value('s'),next(NULL) {}
	Node(const char& item) : value(item), next(NULL) {}

};

void add2back(Node* front, const char item)
{
	Node* curr = front;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr->next = new Node(item);
	
}

void printList(Node* curr)
{
	curr = curr->next;

	while (curr != NULL)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}
}

bool checkResults(Node* curr, std::vector<char> answers)
{
	curr = curr->next;
	int index = 0;

	while (curr != NULL)
	{
		if (curr->value != answers[index])
		{
			return false;
		}
		curr = curr->next;
		index++;
	}

	return true;


}

void printRules()
{
	std::cout << "Welcome to Console Simon Says\n";
	std::cout << "There are 4 colors\n";
	std::cout << "Simon will output random colors\n";
	std::cout << "RED = R\nGREEN = G\nYELLOW = Y\nBLUE = B\n";
	std::cout << "At the end of each sequence of colors Simon will give you time equivalent to your score.\n";
	std::cout << "When Simon says \"Your Turn\" its your turn to give answers.\n";
	std::cout << "USE R/r G/g Y/y B/b\n";
	std::cout << "\n\n";
	std::cout << "Type 1 to start!	";
}

int main()
{
	Node* front = new Node();
	char arr[4] = { 'R', 'G',  'Y',  'B' };
	int start = 0;
	int random;
	int score = -1;
	char input;
	std::vector<char> answers;

	printRules();
	srand(time(NULL));
	
	while (1)
	{
		std::cin >> start;
		
		if (start != 1)
		{
			std::cout << "\nType 1 to start!	";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		else
		{
			break;
		}
	}
	system("cls");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
	do
	{
		answers.clear();
		score++;
		random = rand() % 4;
		add2back(front, arr[random]);
		std::cout << "Simon Says: ";
		printList(front);
		std::this_thread::sleep_for(std::chrono::seconds(score+1));
		system("cls");
		std::cout << "\nYour Turn\n";

		for (int i = 0; i < score + 1; i++)
		{
			std::cin >> input;
			answers.push_back(toupper(input));
		}
		system("cls");
	} while (checkResults(front, answers));

	system("cls");

	std::cout << "GAME OVER !\n\nYour score : " << score << "\n\n";

	return 0;
}