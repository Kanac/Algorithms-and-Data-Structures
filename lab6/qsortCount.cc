#include <iostream>
#include <ctime>
#include <cstdlib>

int comps = 0;
int * x;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;		
		if (x[i] < x[a])
			swap(x[++m], x[i]);
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

int qc(int n){
	// Initialize bounds 
	int a = 0;
	int b = n;
	if (a >= b) return 0;

	int cSum = 0;
	int p = randint(a , b);
	for (int i = a + 1; i <= b; i++){
		cSum++;
	}
	
	cSum += qc(p-1);
	cSum += qc(b-p-1);
	return cSum; 

}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));
	int compsSum = 0;

	// change the following code
	for (int j = 0; j < 100; j++){
		x = new int[NN];
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
	
		quicksort(0, NN-1);
		for (int i=0; i<NN; ++i) {
			std::cout << x[i] << " ";
		}

		int comps2 = qc(NN);
		std::cout << std::endl;
		std::cout << "Comparisons: " << comps <<" Comparisons 2: " << comps2 <<  std::endl;
		
		compsSum+= comps;
		comps = 0;
		delete[] x;
	}
	std::cout << "Average comparisons: " << compsSum/100 << std::endl;
	return 0;
}

