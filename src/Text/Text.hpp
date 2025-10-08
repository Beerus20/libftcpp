#ifndef __TEXT_HPP__
# define __TEXT_HPP__

# include <iostream>
# include "../Utils/Utils.hpp"

# define SEPARATORS	" \t\n\v\f\r"

class Text
{
	private:
		std::size_t	_cursor;
		std::string	_content;
		std::string	_separators;
		std::string	_found_separators;

	public:
		Text(void);
		Text(const std::string &content);
		Text(const std::string &content, const std::string &separators);
		Text(const Text &other);
		virtual ~Text(void);
		Text			&operator=(const Text &other);
		Text			&operator>>(std::string &str);
		Text			&operator<<(const std::string &str);

		const std::string	getWord(void);
		const std::size_t	&getCursor(void) const;
		const std::string	&getContent(void) const;
		const std::string	&getSeparators(void) const;
		const std::string	&getFoundSeparators(void) const;
		void				addSeparators(const std::string &sep);

		void				setContent(const std::string &content);

		void				reset(void);
		void				clear(void);
};

std::ostream	&operator<<(std::ostream &os, const Text &to_show);

#endif