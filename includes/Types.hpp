#ifndef __TYPES_HPP__
# define __TYPES_HPP__

# include <string>
# include <vector>
# include <map>
# include <deque>

namespace Deque {
	using string = std::deque<std::string>;
	using c = std::deque<char>;
	using i = std::deque<int>;
	using f = std::deque<float>;
	using d = std::deque<double>;
};

namespace Vector {
	using string = std::vector<std::string>;
	using c = std::vector<char>;
	using i = std::vector<int>;
	using f = std::vector<float>;
	using d = std::vector<double>;
	template <typename T>
	using _ = std::vector<T>;
};

namespace Map {
	template <typename T>
	using string = std::map<T, std::string>;
	template <typename T>
	using c = std::map<T, char>;
	template <typename T>
	using i = std::map<T, int>;
	template <typename T>
	using f = std::map<T, float>;
	template <typename T>
	using d = std::map<T, double>;
	template <typename T, typename V>
	using _ = std::map<T, V>;
};

#endif
