#include "Text.hpp"

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

const std::string	&Text::replace(const std::string &word, const std::string &replace_word, std::size_t nb)
{
	std::size_t	pos(0);
	std::size_t	len(word.length());
	std::size_t	nb_found(0);

	while ((pos = this->_content.find(word, pos)) != std::string::npos)
	{
		this->_content.replace(pos, len, replace_word);
		nb_found++;
		if (nb != 0 && nb_found == nb)
			break ;
	}
	this->_size = this->_content.size();
	return (this->_content);
}
