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
   int valInsert = rand()%n;
   int valFind = rand()%n;
   for (int j = 1; j <= n/2; j++){
      // If random element is already in set, re-calculate random number
      while (insertedValues.find(valInsert) != insertedValues.end())
         valInsert = rand()%n;
      cout << "I " << valInsert << endl;
      insertedValues.insert(valInsert);
   }

   for (int k = 1; k <= n/2; k++){
      while (insertedValues.find(valFind) == insertedValues.end())
         valFind = rand()%n;
      cout << "F " << valFind << endl; 
   }
   
   return 0;

}

