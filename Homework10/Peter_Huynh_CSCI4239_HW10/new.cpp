#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
	int n = 5000*5000;
   int N = n*n*sizeof(float);
   float* Ah = (float*)malloc(N);
   float* Bh = (float*)malloc(N);
   float* Ch = (float*)malloc(N);
   float* Dh = (float*)malloc(N);
   float* Eh = (float*)malloc(N);
   float* Rh = (float*)malloc(N);

   // Initialize A & B
   //srand(9999);
   //RandomInit(Ah,n);
   //RandomInit(Bh,n);
   string line;
   string row;
   string pitch;
   string yaw;
   float row2;
   float pitch2;
   float yaw2;
 
   ifstream gyro("gyro.txt");
   
   int i = 0;
   while(getline(gyro, line))
   {
	row   = line.substr(0, line.find(","));
	pitch = line.substr(row.length() + 1, line.find(","));
	yaw   = line.substr(row.length() + pitch.length() + 2, line.find(","));

	istringstream iss(row); 
	iss >> row2;
	Ah[i] = row2;

	istringstream iss2(pitch);
	iss2 >> pitch2;
	Bh[i] = pitch2;

	istringstream iss3(yaw);
	iss3 >> yaw2;
	Dh[i] = yaw2;

	//  CALCULATING ONE OF THREE LOCATION ORIENTATION VECTOR FILTERD BASE OFF ROLL PITCH YAW
	Eh[i] = sin(Ah[i]) * tan(Bh[i]) + cos(Dh[i]);
 
    i++;
	if(i >= n*n)
		break;
   }
   gyro.close();
   printf("\nDONE\n");
   return 0;
}