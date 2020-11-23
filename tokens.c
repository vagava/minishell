#include "header.h"

/**
 * tokens - function that tokenize the user instructions.
 * @str: global variable input with user line.
 * @delimitador: global variable input with string separator.
 *
 * Return: char** with array of tokens.
 */
char **tokens(char *str, const char *delimitador)
{
	char **array = NULL;
	int i, token = 0;

	/*contador de tokens*/
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] == 32 && str[i + 1] != 32) || str[i + 1] == '\0')
			token++;
	/*asignacion de memoria*/
	array = malloc((token + 1) * sizeof(char *));
	if (array == NULL)
		exit(-1);
	i = 0;
	/*primer llamado strtok*/
	array[i] = strtok(str, delimitador);
	for (i = 1; i < token ; i++)
		array[i] = strtok(NULL, delimitador);
	array[token] = NULL;
	return (array);
}
