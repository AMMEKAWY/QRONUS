#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "header.h"



double potential(double x){

	//double A=sqrt(1-2*x+pow(x, 2));
	
	double rv=1;
	
	double b=0.81;
	
	double ro=0.91;
	
	double a=1;
	double c=0.4;
	
	//double v=-z1*z2*exp(-b*(x))/((x));

	//double b=2;

	double v=-z1*z2*exp(-pow(x/ro,1))/(x/c);

	//double b=1.1;

	//double v=-z1*z2/x;


	//double v;

	//if(x<=1){v=1/x-1/(1-x);}
	
	//else{v=1/x-1/(x-1);}
	
	return v;

}

