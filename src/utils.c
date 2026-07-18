/**
 * @file utils.c
 * @brief Fonctions d'aide pour le projet wave-equation-solver
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"

/**
 * @brief Fonction pour afficher un message d'erreur
 * @param message Le message d'erreur à afficher
 */
void afficher_erreur(const char* message) {
    fprintf(stderr, "Erreur : %s\n", message);
    exit(EXIT_FAILURE);
}

/**
 * @brief Fonction pour vérifier si un nombre est positif
 * @param nombre Le nombre à vérifier
 * @return 1 si le nombre est positif, 0 sinon
 */
int est_positif(double nombre) {
    return nombre > 0.0;
}

/**
 * @brief Fonction pour calculer la valeur absolue d'un nombre
 * @param nombre Le nombre pour lequel calculer la valeur absolue
 * @return La valeur absolue du nombre
 */
double abs_value(double nombre) {
    return fabs(nombre);
}

/**
 * @brief Fonction pour calculer la moyenne d'un tableau de nombres
 * @param tableau Le tableau de nombres
 * @param taille La taille du tableau
 * @return La moyenne des nombres du tableau
 */
double calcul_moyenne(double* tableau, size_t taille) {
    double somme = 0.0;
    for (size_t i = 0; i < taille; i++) {
        somme += tableau[i];
    }
    return somme / taille;
}

/**
 * @brief Fonction pour trier un tableau de nombres en ordre croissant
 * @param tableau Le tableau de nombres à trier
 * @param taille La taille du tableau
 */
void tri_tableau(double* tableau, size_t taille) {
    for (size_t i = 0; i < taille - 1; i++) {
        for (size_t j = i + 1; j < taille; j++) {
            if (tableau[i] > tableau[j]) {
                double temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
}