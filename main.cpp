#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <limits.h>
#include <algorithm>
#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>
#include <time.h>

#include "Algorithms.h"

//g++ -std=c++11 -o main.o main.cpp Algorithms.cpp -lgmp

using namespace std;

int main(int argc, char* argv[]) {

    int i = 0;

    int limit = (argc == 2 ? atoi(argv[1]) : INT_MAX );

    mpz_t number;

    while(++i <= limit){

        mpz_init(number);
        if (gmp_scanf("%Zd", number) <= 0){
            mpz_clear(number);
            break;
        }
        gmp_printf("%s is an mpz %Zd\n", "here",number);
    }

    return 0;
}
