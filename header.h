#ifndef __HEADER_H__
#define __HEADER_H__
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **tokens(char *str, const char *delimitador);
char *eliminar_salto(char *str);

#endif
