#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class ProductSequence
{
private:
	vector< vector<int> > table_;
	vector< vector<int> > parenTable_;	// Tabla para construir parentesis.
	vector <int> d_;					// Dimensiones de las matrices.
	int n_;								// Numero de matrices.

public:
	ProductSequence(int*, int);
	ProductSequence(vector<int>);
	string getSequence();
	int findSequenceByDiags();
	int findSequenceByRows();
	int findSequenceByCols();
	~ProductSequence();

private:
	string getPSequence(int, int);
};

