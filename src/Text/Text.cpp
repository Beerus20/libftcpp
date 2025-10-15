#include "Text.hpp"
#include <cctype>
#include <string>

Text::Text(void) :
	_cursor(0),
	_content(""),
	_separators(SEPARATORS),
	_found_separators(""),
	_tmp_separators(""),
	_mode(Mode::NORMAL),
	_size(_content.size()),
	_tmp_separator_status(false) {}

Text::Text(const  std::string &content, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(SEPARATORS),
	_found_separators(""),
	_tmp_separators(""),
	_mode(mode),
	_size(_content.size()),
	_tmp_separator_status(false) {}

Text::Text(const  std::string &content, const std::string &separators, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_separators(separators),
	_found_separators(""),
	_tmp_separators(""),
	_mode(mode),
	_size(_content.size()),
	_tmp_separator_status(false) {}

Text::Text(const Text &other) { *this = other; }
Text::~Text(void) {}

bool	Text::findSeparator(void) const
{
	if (this->_tmp_separator_status)
		return (
			this->_separators.find(this->_content[this->_cursor]) != std::string::npos ||
			this->_tmp_separators.find(this->_content[this->_cursor]) != std::string::npos);
	return (this->_separators.find(this->_content[this->_cursor]) != std::string::npos);
}

const std::string	Text::getWord(void)
{
	std::string	word("");

	this->_found_separators.clear();
	while (this->_cursor < this->_size && !this->findSeparator())
		word += this->_content[this->_cursor++];
	while (this->_cursor < this->_size && this->findSeparator())
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
	this->_tmp_separators.clear();
	this->_tmp_separator_status = false;
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

void	Text::showSeparators(bool printable) const
{
	std::cout << "Separators : [";
	for (std::size_t i(0); i < this->_separators.size(); i++)
	{
		if (!std::isprint(this->_separators[i]) && printable)
			continue ;
		std::cout << this->_separators[i];
	}
	std::cout << "]" << std::endl;
}

void	Text::showWords(void)
{
	std::size_t	tmp_cursor(this->_cursor);
	Text::Mode	tmp_mode(this->_mode);
	std::size_t	i(1);

	this->reset();
	while (!this->eof())
		std::cout << "[" << i++ << "] : " << this->getWord() << std::endl;
	std::cout << std::endl;
	this->_cursor = tmp_cursor;
	this->_mode = tmp_mode;
}

