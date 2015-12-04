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
   // Generator to check insertion and search asymptomtic runtime
   // Calls insert once then find 499 times per iteration so that insertion runtime doesn't mix with find
   for(int i = 1; i <= n ; i++){
      cout << "I " << i << endl;

      for (int k = 1; k < 500; k++)
	 cout << "F " << rand()%i << endl; 
   }
   return 0;

}

