#include <string>
#include <vector>

using namespace std;


extern double z1;
extern double z2;

extern double ao;

extern int ls;

extern double pi;
extern double me;
extern double m1;
extern double m2;
extern double m;
extern double h_bar;
extern double e;
extern double range;
extern double energy;

//double energy=50/27.211;

extern double inf;
extern double ninf;

extern double k;

extern double xo;
extern double xf;
extern double h;
extern double deltak;

extern double k1;

extern vector <double> x;

vector <double> wf(int kw);

vector <double> coeff(int l, int n);

vector <double> schrodinger(int q, double yo, double zo);

double phaseshift(vector <double> vector, double kq);

vector <double> xaxis(double xo, double xf, double h);

vector <double> normalizer(vector <double> vector);

double phaseshift(vector<double> vector, int kq);

vector <double> shiftfinder();

vector <double> shifter(double lf);

double round(double n, double k);

double area (double a,double b,double deltak);

double integration(vector <double> func);

double j(int q, double x);

double n(int q, double x);

double jp(int q, double x);

double np(int q, double x);

double maximum(vector <double> vector);

double minimum(vector <double> vector);

double interpolation(vector <double> vectory, vector <double> vectorx, int i);

double fastbessel(int tt , double xi );

double fastneumann(int tt, double xi);

double xmaxbessel(int kk);

double finale();

double stepper();

double potential(double x);

double low_energy();

double high_energy();

void printvector(vector <double> vector);

void printtofile(string filename, vector <double> vector);

vector <double> phase(int l);
