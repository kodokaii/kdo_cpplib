#include "../kdo_cpplib.hpp"

namespace kdo
{
	std::string	strtrim(const std::string &str, const std::string set)
	{
		std::string	dst;
		size_t		start;
		size_t		len;

		start = str.find_first_not_of(set);
		if (start != std::string::npos)
		{
			len = str.find_last_not_of(set) - start + 1;
			dst = str.substr(start, len);
		}
		return (dst);
	}
}
