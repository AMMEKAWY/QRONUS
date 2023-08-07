#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "header.h"

double low_energy(){

	double maxtheta;
	double mindsigma;
	vector <double> shift=shiftfinder();
	vector <double> sangle;
	vector <double> si;
	vector <double> tsig;
	double total=0;
	
	printtofile("shift.txt", shift);
	
	ofstream file;
	file.open("sigma.txt");
	
	//for(int i=0; i<=size(shift); i++){cout<<shift[i]<<endl;}
	
	for(double theta=0; theta<=pi; theta=theta+deltak*pi/180){
	
		double ref=0;
		double imf=0;
		
		sangle.push_back(theta);
	
		for(int i=0; i<=size(shift); i++){
	
			ref=ref+((2*i+1)/sqrt(k))*cos(shift[i])*sin(shift[i])*legendre(i, cos(theta));
			imf=imf+((2*i+1)/sqrt(k))*pow(sin(shift[i]), 2)*legendre(i, cos(theta));
			total=total+4*pi*(2*i+1)/k*pow(sin(shift[i]),2);
	
		}
	
		double dsigma=(pow(ref,2)+pow(imf,2));
	
		si.push_back(dsigma);
	
		file<<dsigma<<endl;
		tsig.push_back(dsigma*2*pi*sin(theta));
	}
	
	file.close();

	
	//for(int i=0; i<=size(shift);i++){cout<<shift[i]<<endl;}
	
		
	double min=minimum(si);

	for(int i=0; i<size(si); i++){

		if(si[i]==min){
	
			maxtheta=sangle[i];
			mindsigma=si[i];
			break;
		}
		
	}

	cout<<total<<endl;
	//cout<<sqrt(mindsigma*16*pow(sin(maxtheta/2), 4))<<endl;
	
	return sqrt(mindsigma*16*pow(sin(maxtheta/2), 4));
	
}
