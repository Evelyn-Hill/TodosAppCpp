#include <iostream>
#include <string>
#include "TodoFile.hpp"

#define LOG(x) std::cout << x << std::endl;
#define ERR(x) std::cerr << x << std::endl;

void AddTodo(char** argv);
void RemoveTodo(char** argv);
void FinishTodo(char** argv);
void ClearTodos();

int main(int argc, char** argv)
{
	TodoFile* todoFile = new TodoFile("Todo.txt");

	if (argc <= 1)
	{
		LOG("Printing Todos");
		todoFile->ReadTodos();
		for (Todo t : todoFile->GetTodos())
		{
			LOG(t.Title + " : " + t.Description);
		}

		return 0;
	}
	
	std::string argv1 = (std::string)argv[1];
	
	// Parse first argument.
	
	if (argv1.compare("-a") == 0)
	{
		AddTodo(argv);
	}
	else if (argv1.compare("-r") == 0) 
	{
		RemoveTodo(argv);
	}
	else if (argv1.compare("-f") == 0) 
	{
		FinishTodo(argv);
	}
	else if (argv1.compare("-c") == 0) 
	{
		ClearTodos();
	}
	else if (argv1.compare("-h") == 0) 
	{
		// Help messages
		LOG("Eve's Epic Todo App!\n");
		LOG("-a <title> <description> to add new todo");
		LOG("-r <title> to remove todo");
		LOG("-f <title> to mark todo as finished");
		LOG("-c to clear todo list");
	}
}

void AddTodo(char** argv)
{
}

void RemoveTodo(char** argv)
{
}

void FinishTodo(char** argv)
{
}

void ClearTodos()
{
}


