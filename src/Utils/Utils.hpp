#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "../../includes/dependencies.hpp"
# include <algorithm>
# include <ostream>
# include "../../includes/Types.hpp"

class Utils
{
	private:
		Utils(void);
		Utils(const Utils &other);
		Utils	&operator=(const Utils &other);

	public:
		virtual ~Utils(void);

		static const std::vector<std::string >	keyword;

		static void				readLines(const std::string &path, void (*func)(const std::string &) = NULL, bool empty_line = false);
		static void				readLines(const std::string &, void *, void (*func)(const std::string &, void *), bool empty_line = false);
		static std::string		getFileName(const std::string &path);

		static std::string		trim(const std::string& s);
		static void				removeAll(std::string &to_change, const std::string &str, std::size_t pos = 0);
		static void				replaceAll(std::string &to_change, const std::string &word, const std::string &replace, std::size_t pos = 0);
		
		static Vector::string	split(const std::string &word, const std::string &sep = "");

		template <typename R, typename A>
		static R convert(const A &value);

		template <typename T>
		static typename std::vector<T>::const_iterator find(const std::vector<T> &vec, const T &to_find);
		
		template <typename T>
		bool find(const std::vector<T> &vec, const T &to_find);
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

template <typename T>
typename std::vector<T>::const_iterator Utils::find(const std::vector<T> &vec, const T &to_find)
{
	return (std::find(vec.begin(), vec.end(), to_find));
}

template <typename T>
bool Utils::find(const std::vector<T> &vec, const T &to_find)
{
	return (std::find(vec.begin(), vec.end(), to_find) != vec.end());
}

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Vector::_<T> &container)
{
	std::for_each(container.begin(), container.end(), [&os](const T &value){
		os << value << std::endl;
	});
	return (os);
}

#endif