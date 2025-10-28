#pragma once

#include <string>
#include <iostream>
#include "convert.hpp"

namespace kdo
{
	template<typename T>
	int	userinput(const std::string &prompt, T &output)
	{
		std::string			line;
		
		std::cout << prompt;	
		std::getline(std::cin, line);
		return (!allConverted(kdo::convert(output, line)));
	}
}
