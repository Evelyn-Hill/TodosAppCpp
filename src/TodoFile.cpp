#include "TodoFile.hpp"
#include <fstream>
#include <iostream>
#include <vector>

static const char *m_FilePath;
static std::vector<Todo> m_TrackedTodos;

TodoFile::TodoFile(const char *Path) { s_FilePath = Path; }

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

    if (c != '\n') {
      currentString.push_back(c);
      c = inputBuffer->sbumpc();
      continue;
    }

    size_t sSplitIndex = currentString.find(':');

    std::string title = currentString.substr(0, sSplitIndex);
    std::string desc =
        currentString.substr(sSplitIndex + 1, currentString.length());

    Todo todo(title, desc);
    toReturn.push_back(todo);

    currentString.clear();

    c = inputBuffer->sbumpc();
  }
	
		
	s_TrackedTodos.clear();

	s_TrackedTodos = toReturn;

	return s_TrackedTodos;
}

int TodoFile::AddTrackedTodo(Todo todo) {
  s_TrackedTodos.push_back(todo);
  return s_TrackedTodos.size();
}

void TodoFile::WriteTodos() {
	ReadTodos();		
	ClearFile();
	std::ofstream is;
	is.open(TodoFile::GetPath());	

  for (Todo t : TodoFile::s_TrackedTodos) {
		is << t.Title << " : " << t.Description << "\n";
  }

	is << EOF;
}

void TodoFile::RemoveTodo(const char* title) {
	if (m_TrackedTodos.size() == 0)
	{
		ReadTodos();
	}
	
	for (int i = 0; i < m_TrackedTodos.size(); i++)
	{
		if (m_TrackedTodos[i].Title == title)
		{
			m_TrackedTodos.erase(m_TrackedTodos.begin() + i);
		}
	}

	WriteTodos();
}

void TodoFile::DisplayTodos() {
  if (s_TrackedTodos.size() == 0) {
    return;
  }

  for (Todo t : GetTodos()) {
    std::cout << t.Title << " : " << t.Description << std::endl;
  }
}

void TodoFile::ClearFile()
{
	std::ofstream ofs;
	ofs.open(GetPath(), std::ofstream::out | std::ofstream::trunc);
}
