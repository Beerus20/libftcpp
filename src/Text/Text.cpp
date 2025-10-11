#include "Text.hpp"
#include <string>

Text::Text(void) :
	_cursor(0),
	_content(""),
	_separators(SEPARATORS),
	_mode(Mode::NORMAL),
	_size(_content.size()) {}

Text::Text(const  std::string &content, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(SEPARATORS),
	_mode(mode),
	_size(_content.size()) {}

Text::Text(const  std::string &content, const std::string &separators, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(separators),
	_mode(mode),
	_size(_content.size()) {}

Text::Text(const Text &other) { *this = other; }
Text::~Text(void) {}

const std::string	Text::getWord(void)
{
	std::string	word("");

	this->_found_separators.clear();
	while (this->_cursor < this->_size && this->_separators.find(this->_content[this->_cursor]) == std::string::npos)
		word += this->_content[this->_cursor++];
	while (this->_cursor < this->_size && this->_separators.find(this->_content[this->_cursor]) != std::string::npos)
	{
		if (this->_found_separators.find(this->_content[this->_cursor]) == std::string::npos)
			this->_found_separators += this->_content[this->_cursor];
		this->_cursor++;
	}
	return (word);
}

const std::string	Text::getRWord(void)
{
	std::string	word("");

	this->_found_separators.clear();
	while (this->_cursor != std::string::npos && this->_separators.find(this->_content[this->_cursor]) != std::string::npos)
	{
		if (this->_found_separators.find(this->_content[this->_cursor]) == std::string::npos)
			this->_found_separators += this->_content[this->_cursor];
		this->_cursor--;
	}
	while (this->_cursor != std::string::npos && this->_separators.find(this->_content[this->_cursor]) == std::string::npos)
		word = this->_content[this->_cursor--] + word;
	return (word);
}

bool	Text::hasFoundSeparator(const std::string &to_search) const
{
	for (std::size_t i(0); i < to_search.size(); i++)
	{
		if (this->_found_separators.find_first_of(to_search[i]) != std::string::npos)
			return (true);
	}
	return (false);
}

bool	Text::eof(void)
{
	return (this->_cursor >= this->_size);
}

void	Text::reset(void)
{
	this->_cursor = this->_mode == Text::Mode::NORMAL ? 0 : this->_size - 1;
	this->_found_separators.clear();
}

void	Text::clear(void)
{
	this->reset();
	this->_mode = Text::Mode::NORMAL;
	this->_content.clear();
	this->_size = 0;
}

Vector::string		Text::split(bool all)
{
	Vector::string	rvalue;
	std::size_t		tmp_cursor_value(this->_cursor);

	if (all)
		this->_cursor = 0;
	while (!this->eof())
		rvalue.push_back(this->getWord());
	this->_cursor = tmp_cursor_value;
	return (rvalue);
}
