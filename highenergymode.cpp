#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "header.h"

double high_energy(){

	double amax=10;
	int lmax=sqrt(k)*amax;


	double maxtheta;
	double mindsigma;
			

	//vector <double> shift=phase(ls);
	vector <double> sangle;
	vector <double> si;

	ofstream file;
	file.open("sigmaapprox.txt");
	
	//for(int i=0; i<=size(shift); i++){cout<<shift[i]<<endl;}
	
	for(double theta=0; theta<pi; theta=theta+deltak*pi/180){
	
		double ref=0;
		double imf=0;
		
		sangle.push_back(theta);
	
		for(int i=0; i<=lmax; i++){
	
			imf=imf+((2*i+1)/(2*sqrt(k)))*legendre(i, cos(theta));
			
		}
		
		//cout<<theta/pi<<endl;
	
		double dsigma=pow(ao, 2)*(pow(ref,2)+pow(imf,2));
	
		si.push_back(dsigma);
	
		file<<dsigma<<endl;
	
	}
	
	file.close();

		
	double min=minimum(si);

	for(int i=0; i<size(si); i++){

		if(si[i]==min){
	
			maxtheta=sangle[i];
			mindsigma=si[i];
			break;
		}
		
	}

	cout<<sqrt(mindsigma*16*pow(sin(maxtheta/2), 4))<<endl;
	
	return sqrt(mindsigma*16*pow(sin(maxtheta/2), 4));

}


