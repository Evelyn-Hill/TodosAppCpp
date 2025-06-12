#include <iostream>
#include <memory>
#include <string>
#include "TodoFile.hpp"

#define LOG(x) std::cout << x << std::endl
#define ERR(x) std::cerr << x << std::endl

void AddTodo(char** argv);
void RemoveTodo(char** argv);
void FinishTodo(char** argv);
void ClearTodos();

TodoFile* g_todoFile;

int main(int argc, char** argv)
{
	g_todoFile = new TodoFile("Todos.txt");

	if (argc <= 1)
	{
		g_todoFile->ReadTodos();

		LOG("Your Todos\n---------------------");
		g_todoFile->DisplayTodos();
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
	std::string Title = (std::string)argv[2];
	std::string Desc = (std::string)argv[3];
	Todo t(Title, Desc);
	g_todoFile->AddTrackedTodo(t);
	g_todoFile->WriteTodos();
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


