#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <limits>
#include "header.h"

using namespace std;
	

double z1=1;
double z2=18;
double A2=40;

int ls=0;

double inf = std::numeric_limits<int>::max();
double ninf = std::numeric_limits<int>::min();

double ao=5.29e-11;

double pi=3.1415;
double mp=1.67e-27;
double me=9.12e-31;
double m1=1;
double m2=A2*mp/me+z2;
double m=m1*m2/(m1+m2);
double h_bar=1;
double e=1;
double energy=50/27.211;

//double energy=1;

double k=(2*m*energy)/pow(h_bar,2);
double k1=(2*m1*energy)/pow(h_bar,2);

//int imyi = std::numeric_limits<int>::min();
int imui = std::numeric_limits<int>::max();

double xo=0.0001;
double xf=10*pi/sqrt(k);
//double xf=;
double h=(pi/(sqrt(k)*1000));

//double h=(xf-xo)/15000;

double deltak=1;

double range=xf;

vector <double> x=xaxis(xo, xf, h);

