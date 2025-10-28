#pragma once

#include "../kdo_cpplib.hpp"

class BNFParser;

class BNFInher: public kdo::string_view
{
	protected:
		std::vector<std::string const *>	inher;
		kdo::State							inherState;
		std::string const					&name;
		kdo::State							state;

	public:
							BNFInher(BNFParser const &son);
							BNFInher(BNFInher const &other);
							~BNFInher(void);
		size_t				pushParent(BNFParser const &parent);
		bool				isHeir(t_uint count, ...) const;
		bool				isHeir(t_uint count, va_list argList) const;
		std::string const	&getName(void) const;
		kdo::State const	&getState(void) const;
		kdo::State const	&getInherState(void) const;
		BNFInher			&operator=(BNFInher const &other);
};
