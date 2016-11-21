#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <vector>

#include "factor_list.h"

using namespace std;

factor_list * add(factor_list ** f, mpz_t * v){

    if(mpz_cmp_ui(*v, 1) == 0){
        return *f;
    }
    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));
    new_list->value = v;
    new_list->next = *f;
    *f=new_list;
    return new_list;
}
factor_list * add_list(factor_list ** f, vector<int> v){

    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));
    mpz_t * tmp = (mpz_t *) malloc(sizeof(mpz_t));
    //mpz_init (* tmp);
    //gmp_printf("%s\n", "return");

    for(int i = 0; i < v.size(); ++i){
        //gmp_printf("%d\n", v[i]);
        mpz_init_set_ui(*tmp, v[i]);
        add(f, tmp);
    }

    *f=new_list;
    return new_list;
}

void factors_print(factor_list * f){
    while(*(f->value) != NULL){
        gmp_printf("%Zd\n", *(f->value));
        f = f->next;
    }
}