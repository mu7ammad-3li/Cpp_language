#ifndef TOKEN_H
#define TOKEN_H


class token{
public:
        char type;
        double value;

};


class token_stream{
public:
        token get();
        void put_back(token t);
private:
        bool full {false};
        token buffer;
};

#endif // TOKEN_H
