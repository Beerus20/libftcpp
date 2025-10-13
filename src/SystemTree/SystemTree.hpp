#ifndef __HTTPSYSTEMTREE_HPP__
# define __HTTPSYSTEMTREE_HPP__

# include "../../includes/json.hpp"
# include <cstddef>
# include <string>
# include <vector>
# include <dirent.h>
# include "Node.hpp"

# define PATHS	"paths"
# define NAMES	"names"

typedef struct dirent *		Dirent;

using Json = nlohmann::json;

class SystemTree : public Node
{
	public:
		enum status
		{
			SUCCESS,
			FAILED
		};

		SystemTree (void);
		SystemTree(const std::string &path, int deep = -1);
		SystemTree (const SystemTree &);
		SystemTree (SystemTree &&) noexcept;
		virtual ~SystemTree (void);
		SystemTree &operator=(const SystemTree &);
		SystemTree &operator=(SystemTree &&) noexcept;

		std::ostream& 	print(std::ostream& os) const;
		bool			load(const std::string &path, std::size_t deep = 1);


	private:
		Json			_infos;

		std::string		checkPath(const std::string &path);
		bool			load(const std::string &path, Json &data, std::size_t deep = 1);
		bool			loadDirectory(const std::string &path, Json &data, std::size_t deep = 0);
		void			initJsonInfo(Json &data);
};

std::ostream& operator << ( std::ostream& os, const SystemTree &httpsystemtree);

#endif