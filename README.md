# Pipex

The project deals with pipe management. A pipe consists of a chain of processes connected in such a way that the **output of each element** of the chain is the **input of the next one**.

The program must be executed:
```
./pipex file1 command1 command2 file2 command2 → what we have to write by console.
```
This is equivalent in Shell to:
```
< file1 command1 | command2 > file2 → what real pipe do in Shell.
```
A pipe has two **file descriptors (fd)** one for the write end and the other for the read end. Therefore a pipe is an array of two integers.

The pipe is one-way (one-way IPC mechanism).

Authorized functions that I used are:
- **perror** → Print an appropriate error message in case of pipe() or fork() failure. It is important to use it because we are going to change stdout, and printf will not print to terminal. However, perror prints to stderr.
For example, perror can print a custom message followed by the actual error such as “Too many open files” or “Permission denied.
- **access** → It allows you to check if a file exists and if you have certain permissions on it (read, write, execute).

It is declared as *int access(const char* *pathname, int mode)*;
- pathname is the path of the file or directory
- mode specifies the type of access to be checked.
   - R_OK: Checks if you have read permission.
   - W_OK: Checks if you have write permission.
   - X_OK: Checks if you have execute permission.
   - F_OK: Checks if the file exists.
