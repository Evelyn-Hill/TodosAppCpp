#pragma once
#include <fstream>
#include <vector>
#include "Todo.hpp"

class TodoFile {
public:
  TodoFile(const char *Path);

  std::vector<Todo>* ReadTodos();
  void WriteTodos(std::vector<Todo> todos);
  void RemoveTodo(Todo todo);
  void ClearFile();
  void DisplayTodos();

  int AddTrackedTodo(Todo todo);

  inline static const char *GetPath() { return m_FilePath; }
  inline static std::vector<Todo> GetTodos() { return *m_TrackedTodos; }

private:
  inline static const char *m_FilePath;
  inline static std::vector<Todo> *m_TrackedTodos;
};
