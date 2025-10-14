#ifndef __TEXT_HPP__
# define __TEXT_HPP__

# include <iostream>
# include "../Utils/Utils.hpp"

# define SEPARATORS	" \t\n\v\f\r"

class Text
{
	public:
		enum class Mode
		{
			NORMAL,
			REVERSE
		};

		Text(void);
		Text(const std::string &content, Mode mode = Mode::NORMAL);
		Text(const std::string &content, const std::string &separators, Mode mode = Mode::NORMAL);
		Text(const Text &other);
		virtual ~Text(void);
		Text			&operator=(const Text &other);
		Text			&operator>>(std::string &str);
		Text			&operator<<(const std::string &str);

		const std::string	getWord(void);
		const std::string	getRWord(void);
		const std::size_t	&getCursor(void) const;
		const std::string	&getContent(void) const;
		const std::string	&getSeparators(void) const;
		const std::string	&getFoundSeparators(void) const;
		const Mode			&getMode(void) const;
		void				addSeparators(const std::string &sep);
		void				rmSeparators(const std::string &sep);

		void				setMode(const Mode &mode);
		void				setContent(const std::string &content);
		void				updateCursor(std::size_t cursor_position);

		bool				hasFoundSeparator(const std::string &to_search) const;

		bool				eof(void);
		void				reset(void);
		void				clear(void);
		void				showSeparators(bool printable = true) const;

		Vector::string		split(bool all = false);

	private:
		std::size_t	_cursor;
		std::string	_content;
		std::string	_separators;
		std::string	_found_separators;
		Mode		_mode;
		std::size_t	_size;

	
};

std::ostream	&operator<<(std::ostream &os, const Text &to_show);

#endif