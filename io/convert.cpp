#include "convert.hpp"

namespace kdo
{
	std::string	chex(unsigned char c)
	{
		std::stringstream	ss;

		ss << std::setfill('0') << std::hex << std::setw(2) << (unsigned int)c;
		return (ss.str());
	}

	std::ios_base::iostate	convert(std::string &output, std::string const &input)
	{
		output = input;
		return (std::ios_base::iostate());
	}

	bool    allConverted(std::ios_base::iostate state)
	{
		return (!((state ^ std::ios::eofbit) & (std::ios::badbit | std::ios::eofbit)));
	}

}
