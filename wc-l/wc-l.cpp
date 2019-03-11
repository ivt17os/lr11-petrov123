#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq, g = 0;
	string str;
	
	if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
		char * s = new char [3000];
	//ifstream f("a.txt");
	FILE* f;
	f= fopen("a.txt","rb");
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек


	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла

	while ( ! feof(f) ) {
		fgets(s,3000,f);
		g++;
	}
	

	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	fclose(f);
	cout << g << str << "\n Time spent:" << setprecision(3) << (t2-t1)/(1.*freq)<< " sec " << "\n File a.txt has " << g << " lines .";
	return 0;
}