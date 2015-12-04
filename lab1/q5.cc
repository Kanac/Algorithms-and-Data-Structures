#include <cstdlib>
#include <iostream>
#include <ctime>

int main(void){
   srand(time(NULL));
   int number = rand() % 100 + 1;
   int input;

   std::cout << "Guess a number from 1 to 100!" << std::endl << "Enter -1 to quit." << std::endl;
   std::cout << number << std::endl;
   do{
      std::cout << "Guess a number: " << std::endl;
      std::cin >> input;
      if (input != number && input != -1){
         std::cout << "Try again!" << std::endl;
      }
      else if (input == number) {
         std::cout << "You got it right!" << std::endl;
      }

   }while (input != -1 && input != number);

   std::cout << "Thanks for playing!" << std::endl;
   return 0;
}
