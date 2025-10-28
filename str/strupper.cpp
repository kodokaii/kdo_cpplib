#include "../kdo_cpplib.hpp"

namespace kdo
{
	std::string strupper(std::string str)
	{
		std::string::iterator   it;

		for (it = str.begin(); it != str.end(); ++it)
			*it = std::toupper(*it);
		return (str);
	}
}
