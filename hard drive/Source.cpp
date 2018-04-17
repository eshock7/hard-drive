#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void largestvolumeday(string path)
{
	ifstream stockdata;
	stockdata.open(path);
	string columnheadings;
	getline(stockdata, columnheadings);
	int biggestnum = 0;
	while (!stockdata.eof())
	{
		string line;
		getline(stockdata, line);
		int lastspot = line.find_last_of(',');
		string volume = line.substr(lastspot + 1);
		int volumeI = atol(volume.c_str());
		if (volumeI > biggestnum)
			biggestnum = volumeI;
	}
	cout << "Largest volume " << biggestnum << endl;
	stockdata.close();
}
void averageprice(string path)
{
	ifstream stockdata;
	stockdata.open(path);
	string columnheadings;
	getline(stockdata, columnheadings);
	double sumofnum = 0;
	int countofnum = 0;
	while (!stockdata.eof())
	{
		string line;
		getline(stockdata, line);
		int lastspot = line.find_last_of(',');
		int sectolast = line.find_last_of(',', lastspot - 1);
		string price = line.substr(sectolast + 1,lastspot-1);
		double priceD = atof(price.c_str());
		sumofnum += priceD;
		countofnum++;
	}
	cout << "Average price " << sumofnum/countofnum << endl;
	stockdata.close();
}
int main()
{
	string path = "AMZN.csv";
	largestvolumeday(path);
	averageprice(path);
	/*
	ifstream stockdata;
	stockdata.open(path);
	string line;
	getline(stockdata, line);
	cout << line << endl;
	getline(stockdata, line);
	cout << line << endl;
	getline(stockdata, line);
	cout << line << endl;
	*/
	system("pause");
	return 0;
}
