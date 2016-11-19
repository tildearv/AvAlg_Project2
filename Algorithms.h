#ifndef __ALGORITHMS_H_INCLUDED__
#define __ALGORITHMS_H_INCLUDED__

#include <gmp.h>
#include <vector>
#include "factor_list.h"

int is_prime(mpz_t, int);
factor_list * divide_by_first_primes(factor_list**, mpz_t);
std::vector<int> naive_factoring(mpz_t);

#endif
