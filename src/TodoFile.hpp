#pragma once
#include "Todo.hpp"
#include <fstream>
#include <vector>

class TodoFile {
public:
  TodoFile(const char *Path);

  std::vector<Todo> ReadTodos();
  void WriteTodos();
  void RemoveTodo(const char* title);
  void ClearFile();
  void DisplayTodos();

  int AddTrackedTodo(Todo todo);

  inline static const char *GetPath() { return s_FilePath; }
  inline static std::vector<Todo> GetTodos() { return s_TrackedTodos; }

private:
  inline static const char *s_FilePath;
  inline static std::vector<Todo> s_TrackedTodos;
};
