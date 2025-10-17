#include "Text.hpp"
#include <cctype>
#include <string>

Text::Text(void) :
	_cursor(0),
	_content(""),
	_original_content(_content),
	_separators(SEPARATORS),
	_found_separators(""),
	_tmp_separators(""),
	_mode(Mode::NORMAL),
	_size(_content.size()),
	_tmp_separator_status(false) {}

Text::Text(const  std::string &content, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_original_content(_content),
	_separators(SEPARATORS),
	_found_separators(""),
	_tmp_separators(""),
	_mode(mode),
	_size(_content.size()),
	_tmp_separator_status(false) {}

Text::Text(const  std::string &content, const std::string &separators, Mode mode) :
	_cursor(0),
	_content(Utils::trim(content)),
	_original_content(_content),
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

const std::string	&Text::getWord(void)
{
	this->_word.clear();
	this->_found_separators.clear();
	while (this->_cursor < this->_size && !this->findSeparator())
		this->_word += this->_content[this->_cursor++];
	while (this->_cursor < this->_size && this->findSeparator())
	{
		if (this->_found_separators.find(this->_content[this->_cursor]) == std::string::npos)
			this->_found_separators += this->_content[this->_cursor];
		this->_cursor++;
	}
	return (this->_word);
}

const std::string	&Text::getRWord(void)
{
	this->_word.clear();
	this->_found_separators.clear();
	while (this->_cursor != std::string::npos && this->_separators.find(this->_content[this->_cursor]) != std::string::npos)
	{
		if (this->_found_separators.find(this->_content[this->_cursor]) == std::string::npos)
			this->_found_separators += this->_content[this->_cursor];
		this->_cursor--;
	}
	while (this->_cursor != std::string::npos && this->_separators.find(this->_content[this->_cursor]) == std::string::npos)
		this->_word = this->_content[this->_cursor--] + this->_word;
	return (this->_word);
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

bool	Text::hasFoundSeparatorOther(const std::string &to_search) const
{
	for (std::size_t i(0); i < this->_found_separators.size(); i++)
	{
		if (to_search.find_first_of(this->_found_separators[i]) == std::string::npos)
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

void	Text::resetContent(void)
{
	this->_content = this->_original_content;
	this->_size = this->_content.size();
}

void	Text::clear(void)
{
	this->reset();
	this->_mode = Text::Mode::NORMAL;
	this->_content.clear();
	this->_original_content.clear();
	this->_tmp_separators.clear();
	this->_tmp_separator_status = false;
	this->_size = 0;
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
