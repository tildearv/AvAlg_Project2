#ifndef __POLLARD_H_INCLUDED__
#define __POLLARD_H_INCLUDED__

#include <gmp.h>
#include <vector>

#include "Algorithms.h"

void solve_pollard(mpz_t, unsigned long int, int, unsigned long int);
void func(mpz_t, mpz_t, mpz_t);
std::vector<int> floyd(mpz_t, unsigned long int, unsigned long int);

#endif