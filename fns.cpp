#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include "header.h"

using namespace std;


vector <double> normalized={};


double fastbessel(int tt, double xi){
	
	
	double stbessel;

	
	try{
	
		stbessel=sph_bessel(tt, xi);
	
	} catch (...){
	
		stbessel=sin(xi-tt*3.1415/2)/xi;
	
	}
	
	
	return stbessel;
	
}


double fastneumann(int tt, double xi){
		
	double stneumann;

	try{
	
		stneumann=sph_neumann(tt, xi);
	
	} catch (...){
	
		stneumann=-cos(xi-tt*3.1415/2)/xi;
	
	}

	//stbessel=sin(xi-tt*3.1415/2);
	
	return stneumann;
	
}


vector <double> xaxis(double uo, double uf, double hi){

	vector <double> r;

	for(double i=uo; i<uf; i=i+hi){
	
		r.push_back(i);
	
	}
	
	return r;

}

double finale(){

	double xfinale=0;

	while(round(potential(xfinale), 1000)!=0){
	
		xfinale=xfinale+0.01;
	
	}
	
	return xfinale;

}

double stepper(){

	double step=pi*abs(1/sqrt(k)-1/sqrt(k1))/2;
	
	return step/10000;

}

double round(double n, double k){
 
	double rounded = (int)(n*k)/k;
	
	return rounded;

}



double maximum(vector <double> vector){

	double maxim=*max_element(vector.begin(), vector.end());
		
	return maxim;
}


double minimum(vector <double> vector){

	double mini=*min_element(vector.begin(), vector.end());
		
	return mini;
}

double area (double a,double b,double deltak){

	double ar=(a+b)*deltak/2;
	
	return ar;

}


double integration(vector <double> func){

	int n=size(func);
	double tarea=0;

	for(int i=0; i<n; i++){
	
		tarea=tarea+area(func[i],func[i+1], deltak);

	}

	return tarea;

}

void printvector(vector <double> vector){

	for(int i=0; i<=size(vector)-1; i++){
	
		cout<<vector[i]<<endl;
	
	}

}

void printtofile(string filename, vector <double> vector){

	
	ofstream file;
	file.open(filename);
	
	
	for(int i=0; i<=size(vector)-1; i++){
	
		file<<vector[i]<<endl;
		
	}
		
	file.close();

}

vector <double> normalizer(vector <double> vector){
	
	for(int i=0; i<=size(vector)-1; i++){
	
		normalized.push_back(vector[i]/maximum(vector));
		
	}
	
	return normalized;	
	
}

double interpolation(vector <double> vectory, vector <double> vectorx, int i){

	double A= (vectorx[i]-vectorx[i-1])/(vectorx[i+1]-vectorx[i]);
	double missing=(A*vectory[i+1]+vectory[i-1])/(A+1);

	return missing;
}

