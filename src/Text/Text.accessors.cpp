#include "Text.hpp"
#include <string>

const std::size_t	&Text::getCursor(void) const
{
	return (this->_cursor);
}

const std::string	&Text::getContent(void) const
{
	return (this->_content);
}

const std::string	&Text::getSeparators(void) const
{
	return (this->_separators);
}

const std::string	&Text::getFoundSeparators(void) const
{
	return (this->_found_separators);
}

const Text::Mode	&Text::getMode(void) const
{
	return (this->_mode);
}

void	Text::addSeparators(const std::string &sep)
{
	for (std::size_t i(0); i < sep.size(); i++)
	{
		if (this->_separators.find(sep[i]) == std::string::npos)
			this->_separators += sep[i];
	}
}

void	Text::rmSeparators(const std::string &sep)
{
	std::size_t	pos(std::string::npos);

	for (std::size_t i(0); i < sep.size(); i++)
	{
		pos = this->_separators.find(sep[i]);
		if (pos != std::string::npos)
			this->_separators.erase(pos, 1);
	}
}

void	Text::setMode(const Text::Mode &mode)
{
	this->_mode = mode;
	this->_cursor = this->_mode == Text::Mode::NORMAL ? 0 : this->_size - 1;
}

void	Text::setContent(const std::string &content)
{
	this->reset();
	this->_content = Utils::trim(content);
	this->_size = this->_content.size();
}

void	Text::updateCursor(std::size_t cursor_position)
{
	if (cursor_position == std::string::npos)
	{
		if (this->_mode == Text::Mode::NORMAL)
			this->_cursor = this->_content.size() - 1;
		if (this->_mode == Text::Mode::REVERSE)
			this->_cursor = 0;
	}
	else
		this->_cursor = cursor_position < this->_size ? cursor_position : this->_size - 1;
}
