#pragma once

#include "../kdo_cpplib.hpp"

namespace kdo
{
	template <class S1, class S2>
	int	stricmp(S1 const &s1 , S2 const &s2)
	{
		size_t	i;

		i = 0;
		while (i < s1.size() && i < s2.size() && std::tolower(s1[i]) == std::tolower(s2[i]))
			i++;
		if (i == s1.size() && i == s2.size())
			return (0);
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}

	template <class S1>
	int	stricmp(S1 const &s1 , char const *s2)
	{
		size_t	i;

		i = 0;
		while (i < s1.size() && s2[i] && std::tolower(s1[i]) == std::tolower(s2[i]))
			i++;
		if (i == s1.size() && !s2[i])
			return (0);
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}

	template <class S2>
	int	stricmp(char const *s1 , S2 const &s2)
	{
		size_t	i;

		i = 0;
		while (s1[i] && i < s2.size() && std::tolower(s1[i]) == std::tolower(s2[i]))
			i++;
		if (!s1[i] && i == s2.size())
			return (0);
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
