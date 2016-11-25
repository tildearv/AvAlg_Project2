#ifndef __POLLARD_H_INCLUDED__
#define __POLLARD_H_INCLUDED__

#include <gmp.h>
#include <vector>

#include "factor_list.h"
#include "Algorithms.h"

factor_list * solve_pollard (factor_list **, mpz_t);
void func(mpz_t, mpz_t, mpz_t, unsigned long int);
factor_list * floyd(factor_list **, mpz_t, unsigned long int, unsigned long int);

#endif