#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <limits.h>

//g++ -std=c++11 -o main.o main.cpp Algorithms.cpp -lgmp

using namespace std;

int main(int argc, char* argv[]) {

    int current_input_number = 0;

    //vector<int> v;

    int limit = (argc == 2 ? atoi(argv[1]) : INT_MAX );

    mpz_t num;

    mpz_init(num);
    if (gmp_scanf("%Zd", num) <= 0){
        mpz_clear(num);
    }

    return 0;
}
