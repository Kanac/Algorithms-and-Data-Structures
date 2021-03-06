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
   // Calls insert 20 times then find 480 times per iteration so that insertion runtime doesn't mix with find
   // Saves a number first for which all find calls will be conducted
   // Will see how the runtime changes as this number as size grows
   for(int i = 1; i <= n ; i+=5){
      for (int j = i; j <= i+5; j++)
      	 cout << "I " << i << endl;

      for (int k = 1; k <= 495; k++)
	 cout << "F " << 1 << endl; 
   }
   return 0;

}

