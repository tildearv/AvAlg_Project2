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
#include "factor_list.h"

//g++ -std=c++11 -o main.o main.cpp Algorithms.cpp -lgmp
//./main.o < "./samples/factoring.in"

using namespace std;

int main(int argc, char* argv[]) {

    int i = 0;

    int limit = INT_MAX ;
    mpz_t number;
    mpz_init(number);

    while(++i <= limit){

        if (gmp_scanf("%Zd", number) <= 0){
            mpz_clear(number);
            break;
        }

        //gmp_printf("%s is an mpz %Zd\n", "here",number);
        int prob = is_prime(number, 20);

        if(prob > 0){
            gmp_printf("%Zd \n", number);
            cout<<endl;
        }else{
 
            factor_list * factors = (factor_list*)malloc(sizeof(factor_list));
            factors->value = NULL;
            factors->next = NULL;

            mpz_t temp_number;
            mpz_init_set(temp_number, number);

            factors = divide_by_first_primes(&factors, temp_number);

            floyd(&factors, temp_number, 59, 59);

            factor_list *f = (factor_list*)malloc(sizeof(factor_list));

            *f = *factors;

            mpz_t prod;
            mpz_init_set_ui(prod, 1);

            mpz_t rest;
            mpz_init (rest);
            mpz_set(rest, number);

            while(*(f->value) != NULL){
                mpz_mul(prod,prod,*(f->value));
                mpz_divexact(rest, number, prod);
                f = f->next;
            }
            //gmp_printf("%s number is %Zd\n", "The", number);
            //gmp_printf("%s rest is %Zd\n", "The", rest);
            int comp = mpz_cmp(number, prod);

            if(comp==0){
                factors_print(factors);
                cout<<endl;
            }else if(is_prime(rest, 5) > 0){ //WHY NOT WORKING???
                //add(&factors, &rest);
                //factors_print(factors);
                //gmp_printf("%Zd\n", rest);
                cout<<"fail"<<endl;
                cout<<endl;
            }else{cout<<"fail"<<endl;
                cout<<endl;
            }


            //vector<int> factors = naive_factoring(number);

            //gmp_printf("%d \n", prob);

            /*unsigned long int prod = 1;
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
            else if(prob_rest > 0){
                for(int v = 0; v < factors.size(); ++v){
                    cout<<factors[v]<<endl;
                }
                gmp_printf("%Zd \n", rest);
            }
            else{cout<<"fail"<<endl;}*/
            
        }
    }
    cout<<endl;
    return 0;
}