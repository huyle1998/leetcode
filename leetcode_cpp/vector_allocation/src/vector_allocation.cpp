#include <iostream>
#include <ctime>

struct House {
    int front_bricks[10000000];
    int back_bricks[10000000];
    int left_bricks[10000000];
    int right_bricks[10000000];
    int in_bricks[10000000];
    int out_bricks[10000000];

     House() {
         for(uint64_t i(0); i < 10000000; i++) {
             front_bricks[i] = 0;
             back_bricks[i] = 0;
             left_bricks[i] = 0;
             right_bricks[i] = 0;
             in_bricks[i] = 0;
             out_bricks[i] = 0;
         }
     }

    //House() :front_bricks(), back_bricks(), left_bricks(), right_bricks(), in_bricks(), out_bricks() {}
};

int main() {
    std::clock_t start_sum = std::clock();
    float duration_sum(0.0);
    for (int i(0); i < 50; i++) {
        std::clock_t start = std::clock();
        float duration(0.0);
        House* p_house1 = new House();
        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC * 1000;
        std::cout << "Operation[" << i << "]: \t" << duration << "ms" << std::endl;
        delete p_house1;
    }
    duration_sum = (std::clock() - start_sum) / (double)CLOCKS_PER_SEC * 1000;
    std::cout << "\nOperation sum: \t" << duration_sum << "ms" << std::endl;
    return 0;
}