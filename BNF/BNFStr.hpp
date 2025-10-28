#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;
class BNFRep;
class BNFCat;
class BNFAlts;

class BNFStr: public BNFParser
{
	protected:
		std::string	ref;

	public:
					BNFStr(std::string const &name, std::string const &str);
					BNFStr(std::string const &str);
					BNFStr(BNFStr const &other);
					~BNFStr(void);
		BNFParser	*clone(void) const;
		int			parse(kdo::string_view const &str, size_t start = 0, size_t len = std::string::npos);
		BNFStr		&operator=(BNFStr const &other);
};
