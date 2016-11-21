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

void func(mpz_t y, mpz_t x, mpz_t number){//y = (x^2+a)%number;

    unsigned long int a = 1;

    mpz_mul(y,x,x);
    mpz_add_ui(y, y, a);
    mpz_mod (y, y, number);

}

factor_list * floyd(factor_list **f, mpz_t number, unsigned long int a_in, unsigned long int b_in) {

    //factor_list *f = (factor_list*)malloc(sizeof(factor_list));

    //f = *factors;

    if (mpz_cmp_ui(number, 1) <= 0){//number 1 and under
        return *f;
    }else if(is_prime(number, 5) > 0){
        mpz_t* factor = (mpz_t *) malloc(sizeof(mpz_t));
        mpz_init (*factor);
        mpz_set(*factor, number);
        add(f, factor);
        return *f;
    }

    mpz_t a;
    mpz_init (a);
    mpz_set_ui(a, a_in);

    mpz_t b;
    mpz_init (b);
    mpz_set_ui(b, b_in);

    mpz_t* factor = (mpz_t *) malloc(sizeof(mpz_t));;
    mpz_init (*factor);
    mpz_set_ui(*factor, 1);

    int comp = mpz_cmp(a, b); //a == b

    bool first = true;
    int i = 0;
    int iter = 400000;

    //gmp_printf("%s is an mpz %Zd\n", "here",number);

    while ( ((comp != 0) || (first == true)) && (i < iter)) {

        first = false;

        mpz_t tmp;
        mpz_init (tmp);

        func(a, a, number);
        func(tmp, b, number);
        func(b, tmp, number);
        mpz_t res;
        mpz_init (res); 
        mpz_sub(res, b, a); 
        mpz_abs(res, res); //|b-a|

        if (mpz_cmp_ui(res, 0) == 0){//Visited all numbers
            mpz_clear(a);
            mpz_clear(b);
            return *f;
        }
        mpz_gcd(*factor, number, res);

        mpz_clear(tmp);
        mpz_clear(res);

        if(mpz_cmp_ui(*factor, 1) > 0){
            //gmp_printf("%s factor is %Zd\n", "The", factor);
            mpz_divexact(number, number, *factor);

            mpz_t* p = (mpz_t *) malloc(sizeof(mpz_t));;
            mpz_init (*p);
            mpz_set(*p, *factor);
            add(f, p);
        }
        ++i;
        comp = mpz_cmp(a, b);
    }
    //factors_print(*f);
    mpz_clear(a);
    mpz_clear(b);
    return *f;
}
