#include "Utils.hpp"
#include "../Text/Text.hpp"

std::string	Utils::trim(const std::string& s)
{
	auto start = std::find_if_not(s.begin(), s.end(), ::isspace);
	auto end = std::find_if_not(s.rbegin(), s.rend(), ::isspace).base();
	return (start < end) ? std::string(start, end) : std::string();
}

void	Utils::removeAll(std::string &to_change, const std::string &str, std::size_t pos)
{
	std::size_t	len;

	if (pos >= to_change.length())
		return ;
	pos = to_change.find(str, pos);
	len = str.length();
	while (pos != std::string::npos)
	{
		to_change = to_change.erase((pos > 0 ? pos - 1 : pos), len);
		pos = to_change.find(str, pos);
	}
}

void	Utils::replaceAll(std::string &to_change, const std::string &word, const std::string &replace, std::size_t pos)
{
	std::size_t	len;

	if (pos >= to_change.length())
		return ;
	pos = to_change.find(word, pos);
	len = word.length();
	while (pos != std::string::npos)
	{
		to_change = to_change.replace(pos, len, replace);
		pos = to_change.find(word, pos);
	}
}

Vector::string	Utils::split(const std::string &word, const std::string &separators)
{
	Vector::string	rvalue;
	Text			text(word);

	text.addSeparators(separators);
	while (!text.eof())
		rvalue.push_back(text.getWord());
	return (rvalue);
}
