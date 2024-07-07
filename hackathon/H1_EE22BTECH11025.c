#include <stdio.h>
#include <math.h>

#define Q 1.602e-19
#define E 1.053626e-10
#define Nd 1e20
#define EB 7.209795e-20
#define m 9.1e-31
#define Hcut 1.054e-34
#define W 2.43447e-6

double energy(double x) {
    if (x >= W || x < 0) {
        return 0;
    } else {
        double u = (-Q * ((Q * Nd) / E) * ((W * x) - ((x * x) / 2))) + EB;
        return u;
    }
}

double tunnelingProbability(double J, double X) {
    return sqrt(2 * m * (energy(X) - J));
}

int main() {
    double dX = 1e-10;
    double dE = 1e-24;
    double integrand;
    double result = 0;
    double i = 0;

    while (i < EB) {
        integrand = 0;
        double j = 0;

        while (j < W) {
            if (energy(j) > i) {
                integrand += tunnelingProbability(i, j) * dX;
            } else {
                break;
            }
            j += dX;
        }

        result += exp((-2 / Hcut) * integrand) * dE;
        i += dE;
    }

    printf("%e\n", result);
    return 0;
}

