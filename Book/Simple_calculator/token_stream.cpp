#include<iostream>
#include <string>
#include "token_stream.h"
#include "functions.h"

void token_stream::put_back(token t){
	if (full) error(" Buffer is full");
	buffer = t ;
	full = true;
}

token token_stream::get(){
	if (full){
		full = false;
		return buffer;
	}
	char ch;
	cin>>ch;
	switch(ch){
	case '=':
	case 'q':
	case '(':case ')':case '+':case '-':case '*':case '/':case '!':
		return token{ch};
	case '.':
	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
	{
		cin.putback(ch);    // return token to Istream
		double val;
		cin>>val;
		return token{'8',val};
	}
	default:
		error("Bad Entry ");

	}
}
