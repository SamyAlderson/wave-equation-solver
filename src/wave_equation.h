/**
 * @file wave_equation.h
 * @brief En-tête pour les fonctions de résolution de l'équation d'onde
 */

#ifndef WAVE_EQUATION_H
#define WAVE_EQUATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @enum Direction
 * @brief Définition des directions possibles
 */
typedef enum {
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

/**
 * @typedef WaveEquationParams
 * @brief Structure pour les paramètres de l'équation d'onde
 */
typedef struct {
    double c; /**< Vitesse de propagation */
    double L; /**< Longueur de l'intervalle */
} WaveEquationParams;

/**
 * @brief Résolution de l'équation d'onde en 1D
 * @param params Paramètres de l'équation d'onde
 * @param u Initialisation de la solution
 * @param u_final Solution finale
 * @return ERREUR_SUCCESS si la résolution est réussie, ERREUR_EQUATION_DONDE_AUTREMENT si une erreur se produit
 */
int wave_equation_solve(WaveEquationParams *params, double *u, double *u_final);

/**
 * @brief Gestion de la frontière
 * @param params Paramètres de l'équation d'onde
 * @param u Initialisation de la solution
 * @param direction Direction de propagation
 * @return ERREUR_SUCCESS si la gestion est réussie, ERREUR_FRONTIERE_AUTREMENT si une erreur se produit
 */
int manage_border(WaveEquationParams *params, double *u, Direction direction);

/**
 * @def ERREUR_SUCCESS
 * @brief Code d'erreur pour une résolution réussie
 */
#define ERREUR_SUCCESS 0

/**
 * @def ERREUR_EQUATION_DONDE_AUTREMENT
 * @brief Code d'erreur pour une résolution impossible
 */
#define ERREUR_EQUATION_DONDE_AUTREMENT 1

/**
 * @def ERREUR_FRONTIERE_AUTREMENT
 * @brief Code d'erreur pour une gestion de frontière impossible
 */
#define ERREUR_FRONTIERE_AUTREMENT 2

#endif  // WAVE_EQUATION_H