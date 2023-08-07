#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "header.h"


vector <double> A1;
vector <double> B1;
vector <double> C1;
vector <double> bessel;
vector <double> neumann;
vector <double> zeros;
vector <double> is;

vector <double> shift;	

double finalx=finale();
int t;
	

double phaseshift(vector<double> vector, int kq){

	//int kq=9;
	
	//cout<<"in"<<endl;
	
	//double l =xmaxbessel(0);

	//vector <double> xqo=xaxis(); 
	//double x2=xmaxbessel(0);
	
	
	for(int i=0; i<size(x); i++){
	
		if(round(x[i]/finalx, 10)==1){
		
			t=i;
			break;
		}
	
	}
	
	for(int i=0; i<size(vector); i++){
	
		bessel.push_back(fastbessel(kq, sqrt(k)*x[i])*sqrt(k)*x[i]);
		
		//neumann.push_back(fastneumann(kq, sqrt(k)*x[i]));
	
	}
	
	//vector <double> tau;
	
	for(int i=0; i<size(bessel); i++){

		shift.push_back(bessel[i]/maximum(bessel));	
	
	}
	//printtofile("bessel.txt", shift);
	
	for(int i=0; i<size(x); i++){
	
		if(size(is)==1 or x[i]>=x[t]){
		
		
			break;
		}
	
		if((vector[i+1]<0 and vector[i-1]>0)){
		
			//zeros.push_back((x[i]+x[i-1])/2);
			is.push_back(x[i]);
			//cout<<i<<endl;
			
			
		}
		
		
	}
	
	for(int i=0; i<size(x); i++){
	
		if(size(zeros)==1 or x[i]>=x[t]){
		
			break;
		}
	
		if((shift[i+1]<0 and shift[i-1]>0)){
		
			zeros.push_back(x[i]);
			//is.push_back((int)(2*i-1)/2);
			//cout<<i<<endl;
			
		}
	
	}
	//cout<<size(zeros)<<endl;
	A1.clear();
	B1.clear();
	C1.clear();
	//is.clear();
	bessel.clear();
	neumann.clear();
	//zeros.clear();
	shift.clear();
	//cout<<abs(atan(beta/gamma))<<endl;
	
	//cout<<"--------------"<<endl;
	//printvector(is);
	//cout<<"--------------"<<endl;
	//printvector(zeros);
	//cout<<"--------------"<<endl;
	
	
	return (((zeros[0]-is[0])));

	
	//return is[0];
}


vector <double> shiftfinder(){

	vector <double> psh={phaseshift(schrodinger(0, 1, 0), 0)*sqrt(k)};
	cout<<0<<"		"<<psh[size(psh)-1]<<endl;
	vector <double> kl={0};
	vector <double> dshift;
	int i=1;
	double ps;
	
	while (true){
	
		zeros.clear();
		is.clear();
		
		vector <double> ai=coeff(i, 20);
		ps=phaseshift(schrodinger(i, ai[0], (ai[1]-ai[0])/h), i);
		
		if (ps==psh[i-1]/sqrt(k)){break;}
		
		if(ps<0 or psh[size(psh)-1]==ps*sqrt(k)){
		
			break;
			psh.push_back((2*pi/sqrt(k)-abs(ps))*sqrt(k));
			cout<<i<<"		"<<psh[size(psh)-1]<<endl;}
		
		else if(ps>0 and ps<psh[0]){
		
			psh.push_back(ps*sqrt(k));
			//kl.push_back(i);
			cout<<i<<"		"<<psh[size(psh)-1]<<endl;
		}
		
		
		
		
			
		
		i++;
		
	}
	/*
	for(int i=0; i<=size(psh)-1; i++){
	
		double val;
	
		if(psh[i]<0){
		
			val=interpolation(psh, kl, i);
			//val=(psh[i])-pi*(1/sqrt(k));
		
		}else{ val=psh[i];}
		
		dshift.push_back(val);
	
	}
	
	printvector(dshift);
	printtofile("shift.txt",dshift);*/
	
	return psh;
	
	//phaseshift(schrodinger(0,1,0),0);

}

