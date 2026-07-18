#ifndef WAVE_EQUATION_SOLVER_UTILS_H
#define WAVE_EQUATION_SOLVER_UTILS_H

/**
 * @file utils.h
 * @brief En-tête pour les fonctions d'aide
 */

/**
 * @defgroup utils Fonctions d'aide
 * @{
 */

/**
 * @brief Vérifie que la valeur est comprise entre les limites inférieure et supérieure incluses.
 * @param val Valeur à vérifier
 * @param min Limite inférieure
 * @param max Limite supérieure
 * @return 1 si la valeur est comprise, 0 sinon
 */
int is_in_range(double val, double min, double max);

/**
 * @brief Renvoie l'erreur de type d'exception correspondant à l'erreur système spécifiée.
 * @param err État d'erreur système
 * @return État d'erreur correspondant
 */
int get_errno(int err);

/**
 * @brief Verrouille l'accès multi-thread à une ressource partagée.
 * @param mutex Verrou de mutex
 */
void lock_mutex(pthread_mutex_t *mutex);

/**
 * @brief Déverrouille l'accès multi-thread à une ressource partagée.
 * @param mutex Verrou de mutex
 */
void unlock_mutex(pthread_mutex_t *mutex);

/**
 * @}
 */

#endif  // WAVE_EQUATION_SOLVER_UTILS_H