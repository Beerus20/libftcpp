#include "Utils.hpp"
#include <string>

Utils::Utils(void) {}
Utils::Utils(const Utils &) {}
Utils::~Utils(void) {}
Utils	&Utils::operator=(const Utils &)
{
	return (*this);
}

void	Utils::readLines(const std::string &path, void (*func)(const std::string &))
{
	std::ifstream	file(path);
	std::string		line("");

	if (file.is_open() && (*func) != NULL)
	{
		while (std::getline(file, line))
			(*func)(line);
		file.close();
	}
}

void	Utils::readLines(const std::string &path, void *result, void (*func)(const std::string &, void *))
{
	std::ifstream	file(path);
	std::string		line("");

	if (file.is_open() && (*func) != NULL)
	{
		while (std::getline(file, line))
			(*func)(line, result);
		file.close();
	}
}

std::string Utils::getFileName(const std::string &path)
{
	std::string rvalue;

	for (int i((int) path.size() - 1); i >= 0; i--)
	{
		if (path[i] == '/')
			break;
		rvalue = path[i] + rvalue;
	}
	return (rvalue);
}
