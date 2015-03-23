#include "ProductSequence.h"


ProductSequence::ProductSequence(int* d, int n) 
{
	n_ = n - 1;
	table_.resize(n_);
	parenTable_.resize(n_);
	for (int i = 0; i < n_; i++) {
		table_[i].resize(n_, 0);
		parenTable_[i].resize(n_, 0);
	}
	for (int i = 0; i < n; i++)
		d_.push_back(d[i]);
}


ProductSequence::ProductSequence(vector<int> d) {
	int n = d.size() - 1;

	table_.resize(n_);
	for (int i = 0; i < n_; i++) {
		table_[i].resize(n_, 0);
		parenTable_[i].resize(n_, 0);
	}
	d_ = d;
}


ProductSequence::~ProductSequence()
{
	for (int i = 0; i < table_.size(); i++)
		table_[i].clear();
	table_.clear();
}


int ProductSequence::findSequenceByDiags() {
	int i, j;
	int aux;
	int min = 9999999;
	

	for (i = 1; i < table_.size(); i++) {
		for (int j = 0; j < table_.size() - i; j++) {
			//Encontrar table_[j][j + i];
			for (int k = j; k < j + i; k++) {
				if (min >(aux = table_[j][k] + table_[k + 1][i + j] + d_[j] * d_[k + 1] * d_[i + j + 1])) {
					min = aux;
					parenTable_[j][i + j] = k;
				}
			}
			table_[j][j + i] = min;
			min = 99999999;
		}
	}

	return table_[0][n_ - 1];
	
}


int ProductSequence::findSequenceByRows() {
	int i, j;
	int aux;
	int min = 9999999;


	for (i = table_.size() - 2; i >= 0; i--) {
		for (int j = table_.size() - 1; j > i; j--) {
			//Encontrar table_[i][j];
			for (int k = i; k < j; k++) {
				if (min >(aux = table_[i][k] + table_[k + 1][j] + d_[i] * d_[k + 1] * d_[j + 1])) {
					min = aux;
					parenTable_[j][j] = k;
				}
			}
			table_[i][j] = min;
			min = 99999999;
		}
	}

	return table_[0][n_ - 1];
}


int ProductSequence::findSequenceByCols() {
	int i, j;
	int aux;
	int min = 9999999;


	for (i = 1; i < table_.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			//Encontrar table_[j][i];
			for (int k = j; k < i; k++) {
				if (min >(aux = table_[j][k] + table_[k + 1][i] + d_[j] * d_[k + 1] * d_[i + 1])) {
					min = aux;
					parenTable_[j][i] = k;
				}
			}
			table_[j][i] = min;
			min = 99999999;
		}
	}

	return table_[0][n_ - 1];

}


string ProductSequence::getSequence(){
	return getPSequence(0, n_ - 1);
}


string ProductSequence::getPSequence(int i, int j) {
	string result = "";
	string left;
	string right;

	if (i == j) {
		result.push_back((char)(i + 65));
	}

	else {
		left = getPSequence(i, parenTable_[i][j]);
		right = getPSequence(parenTable_[i][j] + 1, j);
		result = "(";
		result.append(left);
		result.append(" * ");
		result.append(right);
		result.append(")");
	}
	return result;
}