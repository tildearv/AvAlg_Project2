#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>
#include <time.h>
#include <gmp.h>
#include <vector>

#include "Algorithms.h"

using namespace std;

//Divide by first N primes

vector<int> divide_by_first_primes(mpz_t number){

    std::vector<int> factors;

    unsigned int count = 100;
    unsigned int primes_list[100] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
                53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,
                109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
                173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
                233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
                293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359,
                367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431,
                433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491,
                499, 503, 509, 521, 523, 541
    };

    int i = 0;
    while(i < count){
        unsigned long int n = primes_list[i];
        int q = mpz_divisible_ui_p(number, n);  // check if divisable
        if(q ==0){
            ++i;
        }
        else{
            q = mpz_divisible_ui_p(number, n); //for factors with degree > 1
            //gmp_printf("%s %d\n","q: ", q);
            factors.push_back(n);
            mpz_divexact_ui (number, number, n); //result = number/n
            //gmp_printf("%s %Zd\n","reminder: ", number);
            //gmp_printf("%s %d\n","divisor: ", n);
        }
    }
    return factors;
}

int is_prime(mpz_t number, int reps){
    //returns 0 if not prime, 1 if probable prime, 2 if prime for sure
    int prob = mpz_probab_prime_p(number, reps);
    return prob;
}




vector<int> naive_factoring(mpz_t number) {
    vector<int> factors;
    int div;
    bool done = false;
    unsigned long int N = mpz_get_ui(number);
    N = (long double) N;
    double rootN = ceil(sqrt(N));
    rootN = (unsigned long int) rootN;
    for (unsigned long int p = 2; p <= rootN; p++) {
        done = false;
        while(!done) {
            div = mpz_divisible_ui_p(number, p);
            if (div == 0) {
                done = true;
            } else {
                mpz_divexact_ui (number, number, p);
                factors.push_back(p);
            }
        }
    }
    return factors;
}
