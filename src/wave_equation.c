#include "wave_equation.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Résolution de l'équation d'onde en 1D
 *
 * Fonction principale pour résoudre l'équation d'onde en 1D.
 *
 * @param x Position initiale de la fonction initiale
 * @param t Temps de simulation
 * @param L Longueur de la simulation
 * @param T Temps de fin de simulation
 * @param n Nombre de points de simulation
 * @param u Fonction initiale
 *
 * @return Fonction solution de l'équation d'onde
 */
double *wave_equation(double x, double t, double L, double T, int n, double (*u)(double)) {
    // Vérification des paramètres
    if (x < 0 || t < 0 || L <= 0 || T <= 0 || n <= 0) {
        fprintf(stderr, "Paramètres invalides\n");
        return NULL;
    }

    // Allouation de la mémoire pour la fonction solution
    double *u_sol = malloc(n * sizeof(double));
    if (u_sol == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return NULL;
    }

    // Résolution de l'équation d'onde
    for (int i = 0; i < n; i++) {
        // Position initiale de la simulation
        double xi = x + (i - n / 2) * L / (n - 1);

        // Fonction initiale
        double ui = u(xi);

        // Résolution de l'équation d'onde
        u_sol[i] = ui * cos(sqrt(1 - ui * ui) * t);
    }

    return u_sol;
}

/**
 * Fonction initiale
 *
 * Fonction qui définit la fonction initiale de l'équation d'onde.
 *
 * @param x Position initiale
 *
 * @return Valeur de la fonction initiale
 */
double initial_function(double x) {
    // Fonction initiale simple
    return sin(2 * M_PI * x);
}

/**
 * Fonction de test
 *
 * Fonction qui vérifie la résolution de l'équation d'onde.
 *
 * @param x Position initiale
 * @param t Temps de simulation
 * @param L Longueur de la simulation
 * @param T Temps de fin de simulation
 * @param n Nombre de points de simulation
 *
 * @return Valeur attendue de la fonction solution
 */
double test_function(double x, double t, double L, double T, int n) {
    // Fonction initiale simple
    double u = initial_function(x);

    // Fonction solution attendue
    double u_sol = sin(2 * M_PI * x) * cos(sqrt(1 - sin(2 * M_PI * x) * sin(2 * M_PI * x)) * t);

    return u_sol;
}