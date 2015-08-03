/***********************************************************
	endian.h -- エンディアンネス
***********************************************************/
#ifndef ENDIAN_H
#define ENDIAN_H

enum Endian
{
    LITTLE     = 0,
    BIG          = 1,
    UNKNOWN = 2,
};

int endian();

#endif
