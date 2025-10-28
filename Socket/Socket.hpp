#pragma once

#include <sys/socket.h>
#include "../kdo_cpplib.hpp"

class Socket
{
	protected:
		int		fd;

	public:
				Socket(void);
				Socket(int fd);
				Socket(int domain, int type, int protocol = 0);
				~Socket(void);
		int		open(int domain, int type, int protocol = 0);
		bool	is_open(void) const;
		void	close(void);
		int		getFd(void) const;
		void	setFd(int fd);
};
