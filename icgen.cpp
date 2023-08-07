#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "header.h"

using namespace std;

vector <double> a={1};
//vector <double> x;


double ai(int l, int n){

	double t=sqrt(l*(l+1));

	double a1=2*m*z2*z1/((t+1)*(t+2)-l*(l+1));

	//double a1=0;

	return a1;

}

vector <double> ageneral(double l, double n){

	a.push_back(ai(l, n));

	//double xi=;

	//double xi=sqrt(2);

	double t=sqrt(l*(l+1));

	for(int i=2; i<n; i++){

		a.push_back((2*m*z1*z2*a[i-1]-2*m*energy*a[i-2])/((i+t)*(i+t+1)-l*(l+1)));
		//a.push_back(2*a[i-1]/(i));	
		//a.push_back((-xi+2*l+2+2*(i-1))/((i)*(i+2*l+1))*a[i-1]);
	
	}
			
	return a;

}

vector <double> coeff(int l, int n){

	vector <double> an= ageneral(l, n);
	//vector <double> x=xaxis(xo, xf, h);
	vector <double> dy;
	
	for(int i=0; i< size(x); i++){
		
		double y=a[0];
		
		for(int j=0; j< size(an); j++){
	
			y=y+(a[j]*pow(x[i], j+sqrt(l*(l+1))));
	
		}
		
		dy.push_back(y);	
		
	}

	return dy;

}


