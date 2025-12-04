#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - vérifie la fonction create_file
 *
 * @ac: nombre d’arguments
 * @av: tableau des arguments
 *
 * Return: toujours 0
 */
int main(int ac, char **av)
{
	int res;

	if (ac != 3)
	{
	dprintf(2, "Usage: %s filename text\n", av[0]);
	exit(1);
	}

    /* création du fichier avec le texte fourni */
	res = create_file(av[1], av[2]);
	printf("-> %i)\n", res);

	return (0);
}
