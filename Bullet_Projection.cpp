#include <iostream>
#include <stdio.h>
#include <math.h>
#define g 9.8;
#define PI 3.14159265
#define MJ_Timbal 11340.00
#define MJ_Udara 1.2
using namespace std;


double direction(double Co, double windspeed, double jarak, double jarijari, double Vpeluru){
	double alpha = (3/2 * Co * MJ_Udara * windspeed * jarak/2) / (MJ_Timbal * jarijari * Vpeluru * Vpeluru);
	alpha = atan(alpha) * 180/PI;
	return alpha;
}


int main(){
	double A, time, Co, Vpeluru, Direksi, WindSpeed, BulletRadius;
	double Xstart = 0, Ystart = 0, Xfinal, Yfinal;

	cout<<"This app will calculate when a bullet which was made of lead will fall into the ground\n Assumption : wind direction and the bullet goes horizontal"<<endl;
	cout<<"Massa jenis timbal adalah 11.34 g/cm^3 atau 11340 kg/m^3\n"<<endl;
	cout<<"Massa jenis udara adalah 1.2 kg/m^3\n"<<endl;

	cout<<"Please input bullet drag coeffisien : ";
	cin>>Co;

	cout<<"Please input wind speed [m/s] : ";
	cin>>WindSpeed;

	cout<<"Please input radius of the bullet [m] : ";
	cin>>BulletRadius;

	cout<<"Please input height [meter] : ";
	cin>>Yfinal;

	cout<<"Please input bullet speed [m/s] : ";
	cin>>Vpeluru;

	A = -2 * (Ystart - Yfinal)/g;
	time = sqrt(A); 

	double jarak = Vpeluru * time;

	Direksi = direction(Co, WindSpeed, jarak, BulletRadius, Vpeluru);

	cout<< "The bullet will go for about " << jarak << "m" <<endl;
	cout<<"and it will have " << Direksi << " degree of angle difference" <<endl;
	cout<<"The bullet will drop in " << time << "s" << endl;
	cin>>Ystart;

	return 0;
}
