#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - lit un fichier texte et l'affiche sur la sortie standard
 * @filename: nom du fichier à lire
 * @letters: nombre maximum de lettres à lire et afficher
 * 
 * Return: nombre réel de lettres lues et écrites, 0 en cas d'erreur
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w;
	char *buffer;

	if (filename == NULL)
	return (0);

    /* ouverture du fichier en lecture seule */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

    /* allocation d'un buffer pour stocker les lettres */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
	close(fd);
	return (0);
	}

    /* lecture du fichier */
	r = read(fd, buffer, letters);
	if (r == -1)
	{
	free(buffer);
	close(fd);
	return (0);
	}

    /* écriture sur la sortie standard */
	w = write(STDOUT_FILENO, buffer, r);
	if (w != r)
	{
	free(buffer);
	close(fd);
	return (0);
	}

	free(buffer);
	close(fd);
	return (r);
}
