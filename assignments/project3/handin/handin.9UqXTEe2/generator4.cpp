#include <iostream>
#include <cstdlib> // for atoi
using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 2) // remember, argv[0] is the program name
   {
       cerr << "Wrong number of arguments!" << endl;
       return 1;
   }

   int n = atoi(argv[1]);
   // Generator to check removal asymptomtic runtime
   // Calls n/2 linear increasing insertions then n/2 linear decreasing removals
   int j;
   for (j = 1; j <= n; j++)
      cout << "I " << j << endl;

   for (int k = j; k >= 1; k--)
      cout << "R " << k << endl; 
   
   return 0;

}

