#ifndef SERVERA_H
#define SERVERA_H

#include "service.hpp"
#include "log.hpp"

#include "common.h"


class ServerA
{
public:
	ServerA( LightDS::Service &srv );
	LightDS::Service &srv;
protected:
	AFS::GFSError PRCHello( std::string words );
};

#endif // SERVERA_H
