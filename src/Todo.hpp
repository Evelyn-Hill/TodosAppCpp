#pragma once

#include <string>

// Always meant to be allocated on stack

class Todo {
public:
	Todo(std::string Title, std::string Description);

	std::string Title;
	std::string Description;
};
