#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;
class BNFRep;
class BNFCat;
class BNFAlts;

class BNFChar: public BNFParser
{
	protected:
		char	c;

	public:
					BNFChar(std::string const &name, char c);
					BNFChar(char c);
					BNFChar(BNFChar const &other);
					~BNFChar(void);
		BNFParser	*clone(void) const;
		int			parse(kdo::string_view const &str, size_t start = 0, size_t len = std::string::npos);
		BNFChar		&operator=(BNFChar const &other);
};
