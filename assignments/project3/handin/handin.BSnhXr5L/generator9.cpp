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
   // Generator to check for the fixed chain dictionary (size = 10000)
      for (int j = 1; j <= n*10000/2; j+=10000)
	 cout << "I " << j << endl;

      for (int k = 1; k <= n*10000/2; k+=10000)
	 cout << "F " << k << endl;
   
   return 0;

}

