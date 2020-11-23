#include "header.h"

/**
 * main - entry point function.
 *
 * Return: 0 for success.
 */
int main(void)
{
	char *my_prompt = "$ ";
	char *line_user = NULL;
	size_t line_size = 0;
	ssize_t length_getline = 0;

	char **process_receptor;
	int rexec = 0, fork_return;
	char *delimiter = " ";
	char *line_sin_salto;
	int proceso_terminado;

	while (length_getline != EOF)
	{
		write(STDOUT_FILENO, my_prompt, 2);
		length_getline = getline(&line_user, &line_size, stdin);
		if (*line_user == '\n')
			continue;
		else
		{
			line_sin_salto = eliminar_salto(line_user);
			process_receptor = tokens(line_sin_salto, delimiter);
			/*procesos que sevamos a hacer con el str tokenizado*/
			fork_return = fork();
			if (fork_return == 0)
			{
				sleep(3);
				printf("in del proceso actual= %d\n", getpid());
				rexec = execve(process_receptor[0], process_receptor, NULL);
				if (rexec != 0)
					printf("error de ejecucion\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				proceso_terminado = wait(NULL);
				printf("id del proceso terminado = %d", proceso_terminado);
			}
			/*fin del proceso*/
			free(process_receptor);
		}
	}
	free(line_user);
	return (0);
}
