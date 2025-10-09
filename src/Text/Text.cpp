#include "Text.hpp"

Text::Text(void) :
	_cursor(0),
	_content(""),
	_separators(SEPARATORS) {}

Text::Text(const  std::string &content) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(SEPARATORS) {}

Text::Text(const  std::string &content, const std::string &separators) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(separators) {}

Text::Text(const Text &other) { *this = other; }
Text::~Text(void) {}

const std::string	Text::getWord(void)
{
	std::string	word("");

	this->_found_separators.clear();
	while (this->_cursor < this->_content.size() && this->_separators.find(this->_content[this->_cursor]) == std::string::npos)
		word += this->_content[this->_cursor++];
	while (this->_cursor < this->_content.size() && this->_separators.find(this->_content[this->_cursor]) != std::string::npos)
	{
		if (this->_found_separators.find(this->_content[this->_cursor]) == std::string::npos)
			this->_found_separators += this->_content[this->_cursor];
		this->_cursor++;
	}
	return (word);
}

bool	Text::eof(void)
{
	return (this->_cursor >= this->_content.size());
}

void	Text::reset(void)
{
	this->_cursor = 0;
	this->_found_separators.clear();
}

void	Text::clear(void)
{
	this->reset();
	this->_content.clear();
}
