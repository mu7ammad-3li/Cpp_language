#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H
#include "token.h"

class token_stream{
public:
	token get();
	void put_back(token t);
private:
	bool full {false};
	token buffer;
};

#endif // TOKEN_STREAM_H
