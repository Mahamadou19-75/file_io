#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - vérifie la fonction append_text_to_file
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

    /* ajoute du texte à la fin du fichier existant */
	res = append_text_to_file(av[1], av[2]);
	printf("-> %i)\n", res);

	return (0);
}
