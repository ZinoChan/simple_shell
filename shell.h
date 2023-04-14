#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


char *my_strcpy(char *dest, const char *src);
char **split_string(char *str, const char *str_separator, int *num_of_words);
char *read_input();
size_t get_strlen(const char *str);
void free_words(char **words, int num_of_words);

/*forking*/
void execute_by_forking(char **arr_of_words);
char *get_full_path(const char *cmd);
void execute_cmd_with_execve(char *cmd, char **arr_of_words);
void wait_kid_process(pid_t pid, int *status);

#endif
