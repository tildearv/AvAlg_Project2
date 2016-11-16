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
#include "pollard.h"

//g++ -std=c++11 -o main.o main.cpp Algorithms.cpp -lgmp
//./main.o < "./samples/factoring.in"

using namespace std;

int main(int argc, char* argv[]) {

    int i = 0;

    int limit = INT_MAX ;
    mpz_t number;

    while(++i <= limit){

        mpz_init(number);
        if (gmp_scanf("%Zd", number) <= 0){
            mpz_clear(number);
            break;
        }

        //gmp_printf("%s is an mpz %Zd\n", "here",number);
        int prob = is_prime(number, 50);

        if(prob > 0){
            gmp_printf("%Zd \n", number);
        }else{

        //solve_pollard(number, 2, 2, 1); 
        vector<int> factors = floyd(number, 2, 2); 

        //vector<int> factors = naive_factoring(number);

        //gmp_printf("%d \n", prob);

        //vector<int> factors = divide_by_first_primes(number);
        unsigned long int prod = 1;
        mpz_t rest;
        mpz_init_set(rest, number);
        for(int v = 0; v < factors.size(); ++v){
            prod *= factors[v];
            mpz_divexact_ui (rest, rest, factors[v]);
        }
        int prob_rest = is_prime(rest, 50);
        if(mpz_cmp_d(number, prod) <= 0){ //if the product of the factors isn't equal to the number
            for(int v = 0; v < factors.size(); ++v){
                cout<<factors[v]<<endl;
            }
        }
        /*else if(prob_rest > 0){
            for(int v = 0; v < factors.size(); ++v){
                cout<<factors[v]<<endl;
            }
            gmp_printf("%Zd \n", rest);
        }*/
        else{cout<<"fail"<<endl;}
        cout<<endl;
        }
    }

    return 0;
}