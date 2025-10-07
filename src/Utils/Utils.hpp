#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "../../includes/dependencies.hpp"

class Utils
{
	private:
		Utils(void);
		Utils(const Utils &other);
		Utils	&operator=(const Utils &other);

	public:
		virtual ~Utils(void);

		static const std::vector<std::string >	keyword;

		static void			readLines(const std::string &path, void (*func)(const std::string &) = NULL);
		static void			readLines(const std::string &, void *, void (*func)(const std::string &, void *));
		static std::string	getFileName(const std::string &path);

		static std::string	trim(const std::string& s);
		static void			removeAll(std::string &to_change, const std::string &str, std::size_t pos = 0);
		static void			replaceAll(std::string &to_change, const std::string &word, const std::string &replace, std::size_t pos = 0);
		
		template <typename R, typename A>
		static R convert(const A &value);
};

template <typename R, typename A>
R Utils::convert(const A &value)
{
	std::stringstream ss;
	R res;

	ss << value;
	ss >> res;

	return res;
}

#endif