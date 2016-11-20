#ifndef FACTOR_H
#define FACTOR_H

#include <gmp.h>
#include <vector>

typedef struct factor_list
{
    mpz_t * value;
    struct factor_list * next;
} factor_list;

factor_list * add(factor_list **, mpz_t *);
factor_list * add_list(factor_list **, std::vector<int>);
void factors_print(factor_list *);

#endif