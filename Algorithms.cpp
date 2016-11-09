#include <algorithm>
#include <fstream> // istream I/O
#include <math.h> // pow, sqrt etc
#include <iostream> // cout
#include <string>
#include <time.h>
#include <gmp.h>

#include "Algorithms.h"

int isDivisable(int number, int n){
    if (number % n == 0){
        return number/n;
    }
    return -1;
}

