#ifndef __ALGORITHMS_H_INCLUDED__
#define __ALGORITHMS_H_INCLUDED__

#include <gmp.h>
#include <vector>

int is_prime(mpz_t, int);
std::vector<int> divide_by_first_primes(mpz_t);
std::vector<int> naive_factoring(mpz_t);

#endif
