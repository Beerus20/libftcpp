#ifndef __TEXT_HPP__
# define __TEXT_HPP__

# include <iostream>
#include <string>
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

		const std::string	&getCurrentWord(void) const;
		const std::string	&getWord(void);
		const std::string	&getRWord(void);
		const std::size_t	&getCursor(void) const;
		const std::string	&getContent(void) const;
		const std::string	&getOriginalContent(void) const;
		const std::string	&getSeparators(void) const;
		const std::string	&getFoundSeparators(void) const;
		const std::string	&getTmpSeparators(void) const;
		const bool			&getTmpSeparatorStatus(void) const;
		const Mode			&getMode(void) const;
		const std::size_t	&getSize(void) const;
		std::size_t			getOriginalSize(void) const;

		void				setMode(const Mode &mode);
		void				setContent(const std::string &content);
		void				setTmpSeparatorStatus(const bool &status);
		void				updateCursor(std::size_t cursor_position);
		
		void				addSeparators(const std::string &sep);
		void				rmSeparators(const std::string &sep);
		void				addTmpSeparators(const std::string &sep);
		void				rmTmpSeparators(const std::string &sep);
		
		bool				hasFoundSeparator(const std::string &to_search) const;
		bool				hasFoundSeparatorOther(const std::string &to_search) const;
		bool				testFoundSeparators(int (*func)(int));

		bool				eof(void);
		void				reset(void);
		void				resetContent(void);
		void				clear(void);
		void				showSeparators(bool printable = true) const;
		void				showWords(void);

		Vector::string		split(bool all = false);
		const std::string	&replace(const std::string &word, const std::string &replace_word, std::size_t nb = 0);
		const std::string	&replaceChars(const std::string &chars, const std::string &replace_chars, std::size_t nb = 0);
		bool				hasChar(const char c, const std::size_t &pos = 0) const;
		std::size_t			findChar(const char c, const std::size_t &pos = 0) const;
		bool				hasWord(const std::string &word, const std::size_t &pos = 0) const;
		std::size_t			findWord(const std::string &word, const std::size_t &pos = 0) const;

	private:
		std::string	_word;
		std::size_t	_cursor;
		std::string	_content;
		std::string	_original_content;
		std::string	_separators;
		std::string	_found_separators;
		std::string	_tmp_separators;
		Mode		_mode;
		std::size_t	_size;
		bool		_tmp_separator_status;

		bool		findSeparator(void) const;
	
};

std::ostream	&operator<<(std::ostream &os, const Text &to_show);

#endif