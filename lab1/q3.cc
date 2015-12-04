#include <iostream>
void fill_array(int, int);

int array[10];

int main(void){
   int init, inc;

   std::cout << "Enter initial number:" << std::endl;
   std::cin >> init;
   std::cout << "Enter increment:" << std::endl; 
   std::cin >> inc;
   std:: cout << std::endl;

   fill_array(init, inc);
   for(int i = 0; i < 10; i++){
      std::cout << array[i] << std::endl;
   }
   return 0;
}

void fill_array(int init, int inc){
   for (int i = 0; i < 10; i++){
      array[i] = i*inc + init;
   }
}
