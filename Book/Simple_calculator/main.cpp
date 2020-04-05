/*
 * =====================================================================================
 *
 *      Filename    :  simpleCalculator.cpp
 *
 *      Description :  This is a simple  terminal calulator
 *                      and  is a part of my C++ learning process
 *                      using "programming_principles_and_practice_using_c_2nd_ed"
 *
 *      Version     :  1.0
 *      Created     :  march 9 2020 1:11
 *      Revision    :  none
 *      Compiler    :  g++
 *
 *      Author      :  Muhammad Ali Al-sayed, Mu7ammad.3lii@gmail.com
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include "token.h"
#include "token_stream.h"
#include "functions.h"


extern token_stream ts ;

using namespace std;

int main()
{
	cout << "   SIMPLE CALCULATOR   \n";

	cout <<"Type q= to Exit \n"
		<<"Enter your Expressions followed by = \n ";
	double val ;
	while(cin){
		token t = ts.get();
		if (t.type== 'q'){
			cout <<"Program terminated \n";
			break;
		}
		if(t.type=='=')
			cout<< val<< endl;
		else
			ts.put_back(t);
		val=expression();
	}
}
