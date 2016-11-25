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
factor_list * add_list(factor_list ** f, factor_list * f2){

    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));

    while(*(f2->value) != NULL){
        //gmp_printf("%Zd\n", *(f2->value));
        add(f, (f2->value));
        f2 = f2->next;
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