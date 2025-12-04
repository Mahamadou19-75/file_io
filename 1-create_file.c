#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - crée un fichier et y écrit du texte
 * @filename: nom du fichier à créer
 * @text_content: texte à écrire dans le fichier (NULL terminated)
 *
 * Return: 1 si succès, -1 si échec
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w;
	size_t len = 0;

	if (filename == NULL)
	return (-1);

    /* calcule la longueur de text_content si non NULL */
	if (text_content != NULL)
	{
	while (text_content[len])
		len++;
	}

    /* ouverture du fichier en écriture, création s'il n'existe pas, troncature */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	return (-1);

    /* écriture du texte si présent */
	if (len > 0)
	{
	w = write(fd, text_content, len);
	if (w != (int)len)
	{
	close(fd);
	return (-1);
	}
	}

	close(fd);
	return (1);
}
