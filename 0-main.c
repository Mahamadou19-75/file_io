#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - vérifie la fonction read_textfile
 *
 * @ac: nombre d’arguments
 * @av: tableau des arguments
 *
 * Return: toujours 0
 */
int main(int ac, char **av)
{
	ssize_t n;

	if (ac != 2)
	{
	dprintf(2, "Usage: %s filename\n", av[0]);
	exit(1);
	}

    /* lecture et affichage du fichier : 114 caractères */
	n = read_textfile(av[1], 114);
	printf("\n(printed chars: %li)\n", n);

    /* lecture et affichage du fichier : 1024 caractères */
	n = read_textfile(av[1], 1024);
	printf("\n(printed chars: %li)\n", n);

	return (0);
}

