#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <vector>

#include "factor_list.h"

using namespace std;

factor_list * add(factor_list ** f, mpz_t * v)
{
    factor_list *new_list = (factor_list*)malloc(sizeof(factor_list));
    new_list->value = v;
    new_list->next = *f;
    *f=new_list;
    return new_list;
}
factor_list * add_list(factor_list ** f, vector<int> v)
{
    factor_list *tmp = (factor_list*)malloc(sizeof(factor_list));
    *f=tmp;
    return tmp;
}
void factor_list_print(factor_list * f)
{
    while(*(f->value) != NULL)
    {
        gmp_printf("%Zd\n", f->value);
        f = f->next;
    }
    printf("\n");
};