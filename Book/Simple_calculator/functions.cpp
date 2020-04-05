#include<iostream>
#include <string>
#include"functions.h"
#include "token.h"
#include "token_stream.h"


using namespace std;

token_stream ts ;

void error(string s) {
	throw runtime_error(s);
}


double primary(){
	token t = ts.get();
	switch(t.type){
	case '(':{
		double d = expression();
		t=ts.get();
		if (t.type!=')'){
			error("')' is expected. ");
		}
		return d;

	}
	case '8':
		return t.value;
	default:
		error("Primary is expected. ");
	}

}


double term(){
	double left = primary();
	token t = ts.get();
	while(cin){
		switch(t.type){
		case '*':
			left *= primary();
			t=ts.get();
			break;
		case '/':{
			double d = primary();
			if (d== 0) error("Division by Zero is Infinite. ");
			left /= d;
			t=ts.get();
			break;
		}
		case '!':
			return fac(left);
		default:
			ts.put_back(t);
			return left;
		}
	}
}
double expression(){
	double left =term();
	token t = ts.get();
	while(cin){
		switch(t.type){
		case '+':
			left +=term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t= ts.get();
			break;
		default :
			ts.put_back(t);
			return left;
		}
	}
}
double fac(double anum){
	if (anum == 1) return 1;
	else return anum * fac(anum -1 );
}
