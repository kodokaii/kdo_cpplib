#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;
class BNFRep;
class BNFCat;
class BNFAlts;

class BNFRange: public BNFParser
{
	protected:
		t_uchar	cMin;
		t_uchar	cMax;

	public:
					BNFRange(std::string const &name, t_uchar cMIn, t_uchar cMax);
					BNFRange(t_uchar cMin, t_uchar cMax);
					BNFRange(BNFRange const &other);
					~BNFRange(void);
		BNFParser	*clone(void) const;
		int			parse(kdo::string_view const &str, size_t start = 0, size_t len = std::string::npos);
		BNFRange	&operator=(BNFRange const &other);
};
