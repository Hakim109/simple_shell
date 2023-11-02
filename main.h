#ifndef __SHELL__
#define __SHELL__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;


int _strspn(char *s, char *ac);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);
char **split_line(char *input);
int split_commands(data_shell *datash, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
char *swap_char(char *input, int bool);
char *read_line(int *i);


#endif
