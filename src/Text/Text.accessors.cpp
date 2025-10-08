#include "Text.hpp"

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

void	Text::addSeparators(const std::string &sep)
{
	for (std::size_t i(0); i < sep.size(); i++)
	{
		if (this->_separators.find(sep[i]) == std::string::npos)
			this->_separators += sep[i];
	}
}

void	Text::setContent(const std::string &content)
{
	this->reset();
	this->_content = Utils::trim(content);
}
