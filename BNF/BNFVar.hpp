#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;
class BNFAlts;
class BNFCat;
class BNFRep;

class BNFVar: public BNFParser
{
	protected:
		BNFParser	*rule;

	public:
					BNFVar(std::string const &name = "");
					BNFVar(std::string const &name, BNFParser const &rule);
					BNFVar(BNFVar const &other);
					~BNFVar(void);
		BNFParser	*clone(void) const;
		int			parse(kdo::string_view const &str, size_t start = 0, size_t len = std::string::npos);
		BNFFind     find(std::string const &name, size_t depth = BNF_INFINI) const;
		BNFVar		&operator=(BNFVar const &other);
		BNFVar		&operator=(BNFParser const &other);
};
