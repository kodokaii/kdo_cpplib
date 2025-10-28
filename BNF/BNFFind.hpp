#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;
class BNFInher;

class BNFFind: public std::vector<BNFInher>
{
	public:
					BNFFind(void);
					BNFFind(BNFFind const &other);
					~BNFFind(void);
		void		merge(BNFFind const &other);
		void		pushParent(BNFParser const &parent);
		BNFFind		heir(t_uint count, ...) const;
		BNFFind		fail(void) const;
		BNFFind		good(void) const;
		BNFFind     inherFail(void) const;
		BNFFind     inherGood(void) const;
		BNFFind		&operator=(BNFFind const &other);
};
