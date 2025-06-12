#include "TodoFile.hpp"
#include <iostream>
#include <vector>

static const char *m_FilePath;
static std::vector<Todo> m_TrackedTodos;

TodoFile::TodoFile(const char *Path) {
  m_FilePath = Path;
}

std::vector<Todo> TodoFile::ReadTodos() {
  // This should be in File class;
  std::fstream file;

  // Open todo file
  file.open(TodoFile::GetPath());

  // Init return array
  std::vector<Todo> toReturn;

  if ((file.rdstate() & std::ifstream::failbit) != 0) {
    std::cerr << "Could not open file!" << std::endl;
    return toReturn;
  }

  // Load the entire buffer.
  std::filebuf *inputBuffer = file.rdbuf();

  // get the first char.
  char c = inputBuffer->sbumpc();

  std::string currentString;
	
  while (c != EOF) {
		
	if (c != '\n')
	{	
		currentString.push_back(c);
    	c = inputBuffer->sbumpc();
		continue;
	}

    size_t sSplitIndex = currentString.find(':');

    std::string title = currentString.substr(0, sSplitIndex);
    std::string desc = currentString.substr(sSplitIndex + 1, currentString.length());

    Todo todo(title, desc);
    toReturn.push_back(todo);

    currentString.clear();

    c = inputBuffer->sbumpc();
  }

  m_TrackedTodos = toReturn;
  return toReturn;
}

int TodoFile::AddTrackedTodo(Todo todo) {
  m_TrackedTodos.push_back(todo);
  return m_TrackedTodos.size();
}

void TodoFile::WriteTodos(std::vector<Todo> todos) {}

void TodoFile::RemoveTodo(Todo todo) {}
