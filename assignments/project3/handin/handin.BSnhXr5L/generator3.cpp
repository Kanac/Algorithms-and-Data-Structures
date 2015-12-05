#include <iostream>
#include <cstdlib> // for atoi
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 2) // remember, argv[0] is the program name
   {
       cerr << "Wrong number of arguments!" << endl;
       return 1;
   }

   int n = atoi(argv[1]);
   // Generator to check random insertion and random lookup asymptomtic runtime
   // Calls n/2 insertions then n/2 lookups
   // Checks if random element was already added by adding again
   // Tests the average case of insertion and lookup

   std::set<int> insertedValues;
   int valInit = n;
   insertedValues.insert(valInit);
   int valInsert = rand()%(2*n);

   for (int i = 0; i < n/10; i++){
	   for (int j = 1; j <= 10; j++){
	      while (insertedValues.find(valInsert) != insertedValues.end())
		 valInsert = rand()%(n*2);
	      cout << "I " << valInsert << endl;
	      insertedValues.insert(valInsert);
	   }

	   for (int k = 1; k <= 490; k++){
	      cout << "F " << valInit << endl; 
	   }
   }
   
   return 0;

}

