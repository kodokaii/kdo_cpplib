#include "stricmp.hpp"

namespace kdo
{
	int	stricmp(char const *s1 , char const *s2)
	{
		size_t	i;

		i = 0;
		while (s1[i] && std::tolower(s1[i]) == std::tolower(s2[i]))
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
