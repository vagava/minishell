#include "header.h"

char *eliminar_salto(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++)
	{
		if (str [i] == 10)
			str[i] = '\0';
	}
	return(str);
}