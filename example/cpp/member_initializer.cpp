// Online C++ compiler to run C++ program online
#include <iostream>

struct Tiger{
  Tiger() 
  {
      std::cout << "Create a tiger" << std::endl;
  }
  Tiger(int i) 
  {
      std::cout << "Create a tiger with number " << i << std::endl;
  }
};

struct Animal{
    struct Tiger T1;
    int sex;
    
    Animal(int num, int s): T1(num), sex(s)
    {

    }
};

int main() {
    struct Animal animal_1(2, 1);
    return 0;
}