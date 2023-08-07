#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include "header.h"

using namespace std;

//double h=0.001;

double g(double x, double y, double z, int q){

	long double v=potential(x);
	double A=2*m*v/(pow(h_bar, 2))+energy;
	double k=2*m*energy/pow(h_bar, 2);
	
	//double q=2*(energy-potential(x)+l*(l+1)/(2*m*pow(x, 2)));

	//double df=-q*y;
	
	//double df=-((1-l*(l+1)/pow(x, 2))*y+2*z/x);
	
	double df=(-2*m*energy*y+2*m*potential(x)*y+q*(q+1)*y/pow(x, 2)-2*z/x);
	
	//double df=-2*z/(pow(scale, 2)*x)-(k-alpha*v)*y/pow(scale, 2);
	
	//double df=-y;
	
	return df;
	
}


double f(double x, double y, double z){

	double df=z;
	
	//double df=1;
	
	return df;
	
}

vector <double> schrodinger(int q, double yo, double zo){

	//vector <double> x=xaxis();	

	
	//vector <double> tau;

	double C;
	double B;
	double A;
	double k2;
	
	//vector <double> ib=rey();
	//vector <double> ic=coeff(q, 50);

	//for(int k=0; k<size(ib); k++){
	
	vector <double> ysol;
	vector <double> zsol;
	vector <double> telda;	
	ysol.push_back(yo);
	zsol.push_back(zo);
	
	

	for(int i=0; i<=size(x)-1; i++){
		
		//cout<<x[i]<<endl;		
			
		double k0=h*f(x[i],ysol[i],zsol[i]);
		double l0=h*g(x[i],ysol[i],zsol[i], q);
		double k1=h*f(x[i]+(1/2)*h,ysol[i]+(1/2)*k0,zsol[i]+(1/2)*l0);
		double l1=h*g(x[i]+(1/2)*h,ysol[i]+(1/2)*k0,zsol[i]+(1/2)*l0, q);
		double k2=h*f(x[i]+(1/2)*h,ysol[i]+(1/2)*k1,zsol[i]+(1/2)*l1);
		double l2=h*g(x[i]+(1/2)*h,ysol[i]+(1/2)*k1,zsol[i]+(1/2)*l1, q);
		double k3=h*f(x[i]+h,ysol[i]+k2,zsol[i]+l2);
		double l3=h*g(x[i]+h,ysol[i]+k2,zsol[i]+l2, q);
		double yf=ysol[i]+(k0+2*k1+2*k2+k3)/(6);
		double zf=zsol[i]+(l0+2*l1+2*l2+l3)/(6);
		
		ysol.push_back(yf);
		zsol.push_back(zf);
	
	}
	
	for(int i=0; i<size(x); i++){

		telda.push_back(ysol[i]*x[i]*sqrt(k));	
	
	}
	
	vector <double> tau;
	
	for(int i=0; i<size(x); i++){

		tau.push_back(telda[i]/maximum(telda));	
		
		//cout<<tau[i]<<endl;
	
	}
	
	//printvector(tau);
	
	//printtofile("schrodinger.txt", tau);
	
	//cout<<size(tau)<<endl;

	return tau;

}

