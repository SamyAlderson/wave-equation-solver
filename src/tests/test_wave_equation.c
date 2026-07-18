/**
 * @file test_wave_equation.c
 * @brief Tests unitaires pour la résolution de l'équation d'onde
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wave_equation.h"
#include "utils.h"

/**
 * @brief Test de la fonction wave_equation_solve
 */
void test_wave_equation_solve() {
    double x[] = {0, 1, 2};
    double t[] = {0, 1, 2};
    double u[3] = {0, 1, 2};
    double expected[3] = {0, 1, 4};

    int ret = wave_equation_solve(x, t, u, 3);
    if (ret != 0) {
        printf("Erreur lors de l'appel à wave_equation_solve\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (abs(u[i] - expected[i]) > 1e-6) {
            printf("Erreur dans la résolution de l'équation d'onde : u[%d] = %f, attendu %f\n", i, u[i], expected[i]);
            exit(1);
        }
    }
}

/**
 * @brief Test de la fonction wave_equation_solve avec une erreur
 */
void test_wave_equation_solve_error() {
    double x[] = {0, 1, 2};
    double t[] = {0, 1, 2};
    double u[3] = {0, 1, 2};

    int ret = wave_equation_solve(x, t, u, 4);
    if (ret == 0) {
        printf("Erreur : wave_equation_solve a renvoyé un code de succès alors qu'il devrait y avoir une erreur\n");
        exit(1);
    }
}

int main() {
    printf("Test de la fonction wave_equation_solve...\n");
    test_wave_equation_solve();

    printf("Test de la fonction wave_equation_solve avec une erreur...\n");
    test_wave_equation_solve_error();

    printf("Tests terminés avec succès\n");
    return 0;
}
```

Et le fichier Makefile associé :

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
LDFLAGS =

TESTS = test_wave_equation

$(TESTS):
	$(CC) $(CFLAGS) -c test_wave_equation.c
	$(CC) $(CFLAGS) -c wave_equation.c
	$(CC) $(CFLAGS) test_wave_equation.o wave_equation.o -o $(TESTS)

clean:
	rm -f $(TESTS) test_wave_equation.o wave_equation.o

run:
	./test_wave_equation