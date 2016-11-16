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

#include "pollard.h"

using namespace std;

/*The following code sample finds the factor 101 of 10403 with a starting value of x = 2*/


void solve_pollard (mpz_t number, unsigned long int x_fixed, int cycle_size, unsigned long int x) {
    //int number = 10403, x_fixed = 2, cycle_size = 2, x = 2, 

    mpz_t x2;
    mpz_init (x2);
    mpz_set_ui(x2, x);

    mpz_t x2_fixed;
    mpz_init (x2_fixed);
    mpz_set_ui(x2_fixed, x_fixed);

    mpz_t factor;
    mpz_init (factor);
    mpz_set_ui(factor, 1);
    int comp = mpz_cmp_ui(factor, 1); //factor == 1

    while (comp == 0) {
        for (int count=1; count <= cycle_size && comp <= 0; ++count) {
            mpz_mul(x2,x2,x2);
            mpz_add_ui(x2, x2, 1);
            mpz_mod (x2, x2, number);//x = (x*x+1)%number;

            mpz_t x_res;
            mpz_init (x_res);

            mpz_sub(x_res, x2, x2_fixed);//x_res =  x - x_fixed;
            mpz_gcd(factor, number, x_res); //factor = gcd(x - x_fixed, number);
        }

        cycle_size *= 2;
        mpz_set(x2_fixed, x2);//x_fixed = x;
        comp = mpz_cmp_ui(factor, 1);
    }
    gmp_printf("%s factor is %Zd\n", "The", factor);
}