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


void solve_pollard (mpz_t number, unsigned long int y, int cycle_size, unsigned long int x) {

    mpz_t x2;
    mpz_init (x2);
    mpz_set_ui(x2, x);

    mpz_t y2;
    mpz_init (y2);

    mpz_t factor;
    mpz_init (factor);
    mpz_set_ui(factor, 1);
    int comp = mpz_cmp_ui(factor, 1); //factor == 1

    int iter = 2;
    int i = 0;

    gmp_printf("%s is an mpz %Zd\n", "here",number);

    while ( (i < iter) && (mpz_cmp_ui(number, 1) > 0) ) {
        //for (int count=1; count <= cycle_size && comp <= 0; ++count) {

            func(y2, x2, number);

            mpz_t x_res;
            mpz_init (x_res);

            mpz_sub(x_res, y2, x2);//x_res =  y - x;
            //gmp_printf("%s res is %Zd\n", "The", x_res);
            mpz_gcd(factor, number, x_res); //factor = gcd(y - x, number);
            //gmp_printf("%s factor is %Zd\n", "The", factor);
            if(mpz_cmp_ui(factor, 1) > 0){
                gmp_printf("%s factor is %Zd\n", "The", factor);

            }
        //}
        i += 1;

        //cycle_size *= 2;
        mpz_set(x2, y2);//x = y;
        mpz_divexact (number, number, factor);
        gmp_printf("%s number is %Zd\n", "The", number);
        //comp = mpz_cmp_ui(factor, 1);
    }
}

void func(mpz_t y, mpz_t x, mpz_t number){//y = (x^2+a)%number;

    unsigned long int a = 2;

    mpz_mul(y,x,x);
    mpz_add_ui(y, y, a);
    mpz_mod (y, y, number);

}

factor_list ** floyd(mpz_t number, unsigned long int a_in, unsigned long int b_in) {

    factor_list ** f;

    mpz_t a;
    mpz_init (a);
    mpz_set_ui(a, a_in);

    mpz_t b;
    mpz_init (b);
    mpz_set_ui(b, b_in);

    mpz_t factor;
    mpz_init (factor);
    mpz_set_ui(factor, 1);

    int comp = mpz_cmp(a, b); //a == b

    bool first = true;
    int i = 0;
    int iter = 1000000;

    //gmp_printf("%s is an mpz %Zd\n", "here",number);

    while ( ((comp != 0) || (first == true)) && i < iter) {

        first = false;

        mpz_t tmp;
        mpz_init (tmp);

        func(a, a, number);
        func(tmp, b, number);
        func(b, tmp, number);
        mpz_t res;
        mpz_init (res);
        mpz_sub(res, b, a);
            //gmp_printf("%s res is %Zd\n", "The", x_res);
        mpz_gcd(factor, number, res);

        if(mpz_cmp_ui(factor, 1) > 0){
            //gmp_printf("%s factor is %Zd\n", "The", factor);//Check if factor is prime!
            int p = is_prime(factor, 15);
            mpz_divexact(number, number, factor);

            if(p == 0){
                vector<int> fac = divide_by_first_primes(factor);
                add_list(f, fac);
                //f.insert(std::end(f), std::begin(fac), std::end(fac));
            }else{
                //gmp_printf("%Zd\n", factor);
                //f.push_back(mpz_get_ui(factor));} //probably this that make "wrong answer in kattis"
                add(f, &factor);
            }
        }
        ++i;
        comp = mpz_cmp(a, b);
    }
    factor_list_print(* f);
    return f;
}
