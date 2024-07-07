#include <stdio.h>
#include <math.h>

#define Kb 1.3806452e-23
#define Ni 1.05e16
#define Nd 1e24

double poisson(double x, double T) {
    return Nd + Ni * exp(-x / (Kb * T)) - Ni * exp(x / (Kb * T));
}

double find_root(double T) {
    double p = 0.0, b = 1e-19, d, e;

    while (1) {
        d = (p + b) / 2;

        if (poisson(p, T) * poisson(d, T) < 0)
            b = d;
        else
            p = d;

        e = (p + b) / 2;

        if (fabs(d - e) < 1e-24)
            break;
    }

    return e;
}

int main() {
    double T = 300.0;

    FILE *ptr = fopen("output.txt", "w");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (double i = 1e-20; i <= 8e-20; i += 1e-22) {
        fprintf(ptr, "%0.50lf %0.50lf\n", i, poisson(i, T));
    }

    double root = find_root(T);
    printf("%e\n", root);

    return 0;
}
