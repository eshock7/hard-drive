#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
void largestandsmallestvolumeday(string path, ofstream& out)
{
	ifstream stockdata;
	stockdata.open(path);
	if (!stockdata.is_open()) {
		cout << "Unable to open file!" << endl;
		return;
	}
	string columnheadings;
	getline(stockdata, columnheadings);
	int biggestnum = 0;
	int smallestnum = LONG_MAX;
	string biggestdate;
	string smallestdate;
	while (!stockdata.eof())
	{
		string line;
		getline(stockdata, line);
		if (line == "")
			continue;
		int firstspot = line.find_first_of(',');
		string date = line.substr(0, firstspot);
		int lastspot = line.find_last_of(',');
		string volume = line.substr(lastspot + 1);
		int volumeI = atol(volume.c_str());
		if (volumeI > biggestnum){
			biggestnum = volumeI;
			biggestdate = date;
		}
		if (volumeI < smallestnum){
			smallestnum = volumeI;
			smallestdate = date;
		}
	}
	out << "Largest volume " << biggestnum <<" on "<<biggestdate<< endl;
	out << "Smallest volume " << smallestnum<<" on "<<smallestdate << endl;
	stockdata.close();
}
void averageprice(string path, ofstream& out)
{
	ifstream stockdata;
	stockdata.open(path);
	if (!stockdata.is_open()) {
		return;
	}
	string columnheadings;
	getline(stockdata, columnheadings);
	int win = 0;
	int lose = 0;
	int biggestwin = 0;
	int biggestlose = 0;
	string biggestwindate;
	string biggestlosedate;
	double lastnum = 0;
	double sumofnum = 0;
	int countofnum = 0;
	while (!stockdata.eof())
	{
		string line;
		getline(stockdata, line);
		int firstspot = line.find_first_of(',');
		string date = line.substr(0, firstspot);
		int lastspot = line.find_last_of(',');
		int sectolast = line.find_last_of(',', lastspot - 1);
		string price = line.substr(sectolast + 1,lastspot-1);
		double priceD = atof(price.c_str());
		sumofnum += priceD;
		countofnum++;

		if (priceD > lastnum){
			win++;
			lose = 0;
			if (win > biggestwin){
				biggestwin = win;
				biggestwindate = date;
			}
		}
		if (priceD < lastnum){
			lose++;
			win = 0;
			if (lose > biggestlose){
				biggestlose = lose;
				biggestlosedate = date;
			}
		}
		lastnum = priceD;

	}
	out << "Average closing price " << sumofnum/countofnum << endl;
	out << "Largest win streak " << biggestwin << " on " << biggestwindate << endl;
	out << "Largest lose streak " << biggestlose << " on " << biggestlosedate << endl;
	stockdata.close();
}

int main(){
	string again = "yes";
	while (toupper(again.at(0)) == 'Y') {
		string inpath, outpath;
		cout << endl << "What is the name of the file you want to read? ";
		getline(cin, inpath);
		if (inpath == "") {
			cout << "You need to type a filename." << endl;
		}
		else{
			cout << endl << "What is the name of the file you want to write? ";
			getline(cin, outpath);
			if (outpath == "") {
				cout << "You need to type a filename." << endl;
			}
			else if (inpath == outpath) {
				cout << "Error! Input and output files cannot have the same name." << endl;
			}
			else{
				ofstream outfile;
				outfile.open(outpath);
				outfile << "Analysis of input file named " << inpath << ":" << endl;
				largestandsmallestvolumeday(inpath, outfile);
				averageprice(inpath, outfile);
				outfile.close();
				cout << endl << "Done!  Do you want to process another file? ";
				getline(cin, again);
				cout << endl;
			}
		}
	}
	return 0;
}
