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
   // n is the number of 500 computations done
   // Generator to check linear insertion and search asymptomtic runtime
   for(int i = 0; i < n ; i++){
      int j;
      for (j = 500*(i)+1; j <= 500*(i+1); j++)
	 cout << "I " << j << endl;

      for (j = 500*(i)+1; j <= 500*(i+1); j++)
	 cout << "F " << j << endl;
   }
   return 0;

}

