#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>

#define STORAGE_SIZE 1024
extern char **environ;


char *my_strcpy(char *dest, const char *src);
char **split_string(char *str, const char *str_separator, int *num_of_words);
char *read_input();
size_t get_strlen(const char *str);
void free_words(char **words, int num_of_words);

/* File management */
int file_exists(const char *path);
char *get_dir_path(const char *path, const char *cmd);
char *get_path_copy();

/*forking*/
int execute_by_forking(char **arr_of_words, char *user_prompt,
char *sh_name, int cnt, int n);
char *get_full_path(const char *cmd);
void exec_cmd_with_execve(char *cmd, char **arr_of_words);
void wait_kid_process(pid_t pid, int *status);
void execute_bin_ls(char **arr_of_words);

/* String manipulation */
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *s);
int my_strcmp(const char *first, const char *second);
int my_atoi(const char *string);

/*Get line*/
ssize_t my_getline(char **the_storage_ptr, size_t *size_of_storage,
FILE *read_stream);
int read_from_input(char *char_to_read);
void *my_realloc(void *old_ptr, size_t size);
void update_buff(char **buff_ptr, size_t *buff_size, char *buffer, size_t idx);
void *my_memcpy(void *destination, const void *source, size_t num_of_bytes);


/**handle exit , setenv, unsetenv*/
int handle_various_cmds(char **arr_of_words, char *user_prompt,
char *sh_name, int cnt, int n);
void handle_the_env(void);
int my_setenv(const char *env_name, const char *env_value,
		int env_overwrite_val);
int my_unsetenv(const char *env_name);

/*handle cd*/
void my_cd(char **arr_of_words);

/*cd helper functions*/
char *env_vars(const char *env_name, char **env_pointer);
void isError(const char *msg);
char *get_dir(const char *initial_path);
char *handle_cwd();
void switch_current_directory(const char *directory);

/*String comparison function*/
int my_strncmp(const char *st1, const char *st2, size_t number);

/*execute multiple commands*/
int exec_multi_cmds(char *user_prompt, char *sh_name, int cnt);

void p_the_err(char *cnt, char *sh_name, char *cmd, char *msg);
int is_valid_word(char *str);
char *intToString(int num);
void handle_sig(int sig);
void handle_exit_with_status(char **arr_of_words, char *user_prompt,
char *sh_name, int cntr, int n);
void ex_err(char **arr_of_words, int cntr, char *sh_name);
int my_isdig(int c);
#endif
