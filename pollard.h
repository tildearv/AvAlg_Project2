#ifndef __POLLARD_H_INCLUDED__
#define __POLLARD_H_INCLUDED__

#include <gmp.h>
#include <vector>

#include "factor_list.h"
#include "Algorithms.h"

void solve_pollard(mpz_t, unsigned long int, int, unsigned long int);
void func(mpz_t, mpz_t, mpz_t);
factor_list ** floyd(factor_list **, mpz_t, unsigned long int, unsigned long int);

#endif