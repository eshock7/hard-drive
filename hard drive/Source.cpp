#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
string largestvolumeday(string path)
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
	cout <<"Largest volume "<< biggestnum<<endl;
	stockdata.close();
	return "cat";
}
int main()
{
	string path = "AMZN.csv";
	largestvolumeday(path);
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
