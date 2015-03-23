#include "ProductSequence.h"

int main (void) {
	int a[5] = { 10, 20, 50, 1, 100 };
	ProductSequence s(a, 5);

	cout << s.findSequenceByDiags() << endl;
	cout << s.findSequenceByRows() << endl;
	cout << s.findSequenceByCols() << endl;
	cout << s.getSequence() << endl;
	system("pause");
}