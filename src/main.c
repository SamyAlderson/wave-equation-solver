/**
 * @file src/main.c
 * @brief Fichier principal pour le projet wave-equation-solver
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"
#include "wave_equation.h"

/**
 * @brief Fonction principale
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @return Code de sortie
 */
int main(int argc, char **argv) {
    // Vérification du nombre d'arguments
    if (argc != 3) {
        fprintf(stderr, "Erreur : nombre d'arguments incorrect\n");
        printf("Usage : %s <fichier de données> <taille de la grille>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Chargement du fichier de données
    char *filename = argv[1];
    int grid_size = atoi(argv[2]);

    // Vérification de la taille de la grille
    if (grid_size <= 0) {
        fprintf(stderr, "Erreur : taille de la grille incorrecte\n");
        return EXIT_FAILURE;
    }

    // Initialisation des variables
    double *u = malloc(grid_size * sizeof(double));
    if (u == NULL) {
        fprintf(stderr, "Erreur : allocation de mémoire impossible\n");
        return EXIT_FAILURE;
    }

    // Résolution de l'équation d'onde
    if (!solve_wave_equation(u, grid_size)) {
        fprintf(stderr, "Erreur : résolution de l'équation d'onde impossible\n");
        free(u);
        return EXIT_FAILURE;
    }

    // Affichage des résultats
    printf("Résultats de la résolution de l'équation d'onde :\n");
    for (int i = 0; i < grid_size; i++) {
        printf("%f ", u[i]);
    }
    printf("\n");

    // Libération de la mémoire
    free(u);

    return EXIT_SUCCESS;
}