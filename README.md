# Simple Shell

###Introduction

This is a Simple Shell project developed in the C programming language. It is a command-line interpreter that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

###Description

This project consists of the creation of a simple shell that will allow the user to interact with the system using commands. The shell handles the PATH to find the programs it will execute. It uses the execve() system call to perform the commands. The execution of the programs is done under children processes using fork().

###Compilation and Execution

To compile the Simple Shell, use the following command:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
To run the Simple Shell, use the following command:
```sh
$ ./hsh
```

###Usage

The Simple Shell has the same output as the sh. Below are some examples of how to use it:

- To list the files in the current directory, use the command ls:
```sh
ls
```
- To display the current directory address, use the command pwd:
```sh
pwd
```
- To exit the Simple Shell, type exit or press CTRL + d:
```sh
exit
```

###Files

The following is a list of the files included in the Simple Shell project:

shell.c - execute source code
shell.h - prototypes

###Authors
- ZinoChan
- emaoumaima

