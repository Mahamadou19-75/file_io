#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit - affiche un message d'erreur et quitte avec le code donné
 * @code: code de sortie
 * @msg: message d'erreur
 * @file: nom du fichier ou valeur de fd à afficher
 */
void error_exit(int code, const char *msg, const char *file)
{
	dprintf(2, msg, file);
	exit(code);
}

/**
 * main - copie le contenu d'un fichier vers un autre
 * @ac: nombre d'arguments
 * @av: tableau des arguments
 *
 * Return: 0 en succès
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

	if (ac != 3)
	error_exit(97, "Usage: cp %s file_to\n", av[0]);

	/* ouvrir le fichier source */
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	error_exit(98, "Error: Can't read from file %s\n", av[1]);

    /* ouvrir/créer le fichier destination */
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
	if (close(fd_from) == -1)
	dprintf(2, "Error: Can't close fd %d\n", fd_from);
	error_exit(99, "Error: Can't write to %s\n", av[2]);
	}

    /* lecture et écriture par blocs de 1024 octets */
	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
	w = write(fd_to, buffer, r);
	if (w != r)
	{
	if (close(fd_from) == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
	dprintf(2, "Error: Can't close fd %d\n", fd_to);
	error_exit(99, "Error: Can't write to %s\n", av[2]);
	}
	}

	if (r == -1)
	{
	if (close(fd_from) == -1)
	dprintf(2, "Error: Can't close fd %d\n", fd_from);
	if (close(fd_to) == -1)
	dprintf(2, "Error: Can't close fd %d\n", fd_to);
	error_exit(98, "Error: Can't read from file %s\n", av[1]);
	}

    /* fermeture des fichiers */
	if (close(fd_from) == -1)
	error_exit(100, "Error: Can't close fd %d\n", "fd_from");
	if (close(fd_to) == -1)
	error_exit(100, "Error: Can't close fd %d\n", "fd_to");

	return (0);
}

