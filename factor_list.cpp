#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <vector>

#include "factor_list.h"

using namespace std;

factor_list * add(factor_list ** f, mpz_t * v){

    //gmp_printf("%s\n", "add");
    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));
    new_list->value = v;
    new_list->next = *f;
    *f=new_list;
    return new_list;
}
factor_list * add_list(factor_list ** f, vector<int> v){

    //gmp_printf("%s\n", "list");
    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));
    mpz_t * tmp = (mpz_t *) malloc(sizeof(mpz_t));
    //mpz_init (* tmp);
    //gmp_printf("%s\n", "return");

    for(int i = 0; i < v.size(); ++i){
        gmp_printf("%d\n", v[i]);
        mpz_init_set_ui(*tmp, v[i]);
        add(f, tmp);
    }

    *f=new_list;
    return new_list;
}

bool exact_factors(factor_list * f, mpz_t number){ //See if factorization is exact
    mpz_t prod;
    mpz_init_set_ui(prod, 1);
    //gmp_printf("%s product is %Zd\n", "The", prod);
    while(*(f->value) != NULL){
        mpz_mul(prod,prod,*(f->value));
        //gmp_printf("%Zd\n", f->value);
        //gmp_printf("%s product is %Zd\n", "The", prod);
        f = f->next;
    }
    //gmp_printf("%s number is %Zd\n", "The", number);
    //gmp_printf("%s product is %Zd\n", "The", prod);
    int comp = mpz_cmp(number, prod);

    if(comp==0){
        return true;
    }
    return false;
}

void factors_print(factor_list * f){
    //gmp_printf("%s\n", "print");
    while(*(f->value) != NULL){
        gmp_printf("%Zd\n", *(f->value));
        f = f->next;
    }
}