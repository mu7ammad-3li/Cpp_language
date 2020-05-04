#ifndef GRAMMER_H
#define GRAMMER_H

class token
{
public:
   double value;
   char type;

};

class token_stream
{
public:
    token get ();
    void put_back(token);
private:
    bool full ;
    token buffer;
};


class grammer
{
public:
    grammer();
};

#endif // GRAMMER_H
