// =================================================================
//
// File: main.cpp
// Author: Itzel Hernández Vargas
// Date: 06/09/22
//
// =================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  ifstream inputFile;
	ofstream outputFile;
  
	int n1, n2;
  
	inputFile.open(argv[1]);
	outputFile.open(argv[2]);
  
	inputFile >> n1;
	vector<int>vectorN(n1);
	for(int n = 0; n < n1; n++) {
		inputFile >> vectorN[n];
	}
  	
	vector<int> vector1 = vectorN;
	vector<int> vector2 = vectorN;
  
	int iS_n = insertionSort(vector1);
	int bS_n = bubbleSort(vector2);
	int sS_n = selectionSort(vectorN);
  
	outputFile << bS_n << " " << sS_n << " " << iS_n << endl << endl;
  
	inputFile >>  n2;
	pair<int,int> sS_P;
	pair<int,int> bS_P;
  
	int n3;
  
	for(int p = 0; p < n2; p++) {
		inputFile >> n3;
		sS_P = sequentialSearch(vectorN, n3);
		outputFile << sS_P.first << ' ' << sS_P.second << ' ';
		bS_P = binarySearch(vectorN, n3);
		outputFile << bS_P.second << endl;
	}
  
	inputFile.close();
	outputFile.close();
  
	return 0;
}