#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - teste la fonction de copie de fichier
 * @ac: nombre d'arguments
 * @av: tableau des arguments
 *
 * Return: 0 en succès
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
	dprintf(2, "Usage: %s file_from file_to\n", av[0]);
	exit(97);
	}

    /* Appel du programme de copie */
	if (cp(av[1], av[2]) == -1)
	{
	dprintf(2, "Erreur lors de la copie\n");
	return (1);
	}

	printf("Fichier '%s' copié vers '%s' avec succès.\n", av[1], av[2]);
	return (0);
}
