# Pipex

The project deals with pipe management. A pipe consists of a chain of processes connected in such a way that the **output of each element** is the **input of the next one**.

The program must be executed:
```
./pipex file1 command1 command2 file2 command2 → what we have to write by console.
```
This is equivalent in Shell to:
```
<file1 command1 | command2 >file2 → what real pipe does in Shell.
```
A pipe has two **file descriptors (fd)** one for the write end and another for the read end. Therefore a pipe is an array of two integers.

The pipe is one-way (one-way IPC mechanism).

Authorized functions that I used are:
- **pipe** → Creation of unidirectional communication channels.
- **fork** → A function used to create a new process (child) on Unix-like systems. The original process is called parent.
- **perror** → Print an appropriate error message in case of pipe() or fork() failure. It is important to use it because we are going to change stdout, and printf will not print into terminal. However, perror prints to stderr.
For example, perror can print a custom message followed by the actual error such as “Too many open files” or “Permission denied".
- **access** → It allows you to check if a file exists and if you have certain permissions on it (read, write, execute).
It is declared as *int access(const char** *pathname, int mode)*;
  - pathname --> is the path of the file or directory
  - mode --> specifies the type of access to be checked.
    - R_OK: Checks if you have read permission.
    - W_OK: Checks if you have write permission.
    - X_OK: Checks if you have execute permission.
    - F_OK: Checks if the file exists.
- **dup2** → Duplicates an existing file descriptor (fd), but allows you to specify the number of the target file descriptor. (Allows you to make a change of stdin and stdout).
*int dup2(int oldfd, int newfd)*;

Example; dup2(infile, STDIN_FILENO) → means that the input will be infile instead of stdin.
- **execve** → Runs a new program in the context of an existing process. It takes 3 arguments; the **path** to the program you want to run, an **array of command lines**, and an array of **environment variables**.
- **waitpid** → Allows the parent process to wait for the termination of a specific child process or certain groups of processes.
*pid_t waitpid(-1, int* *status, WNOHANG );*
   - -1 indicates that the parent is left waiting for any child to terminate (if we want a specific child we would write its PID)
   - status is used as a container to receive the exit status of the child process via the waitpid function.
   - WNOHANG means that we will not wait for the child to finish before executing the parent.

## Steps in the creation of the pipe
1. **Main**.

Declare an array (fd) of two positions → int fd[2].

Call the function pipe → pipe(fd). If the function returns 0 → all Ok, if it returns -1 → error.

Call fork (creation of the child) → parent = fork(). This returns a value of type pid_t (as an integer) which we will call parent.
- In case parent= 0 →we are in the child → call to parent_process.
- In case parent= -1 → error
- Other case → we have created the parent → call child_process
2. **Child_process** → *void child_process (char* *argv[], int* *fd, char* ***envp)*

We open the infile, and with dup2, set the input to be infile and the output to be fd[1]. We close the other end of fd (fd[0]) and close infile. We call **ft_exec**.

3. **Parent_process** → *void parent_process (char* *argv[], int* *fd, char* ***envp)*

We open the outfile in write mode giving permissions to the owner only. With dup2 we make the input fd[0] and the output outfile. And we close the unused end (fd[1]) and the output. We call ft_exec.

4. **get_envp** gets the path of the environment variable you are looking for (e.g. it could be PATH, USER, HOME...)

5. **get_path**, calls **find_path** and get the full path to the executable command. This requires that you have previously obtained the path from the PATH environment variable (by calling get_enp). 

It works as follows: the path obtained in get_envp is split into paths separated by : and to each one is added /command[0] to see which is the correct path of that executable. It is checked with **access**, and in positive case that path is returned, which goes into excve.

IMPORTANT: it is necessary to verify if the command itself is the **absolute route**, so that it does not give me error.

6. **ft_exec** takes the path, the commands, and the environment variables, and executes a new program using **execve**.

If the process is successful, the current process is replaced by the command executable and nothing is returned.

## Makefile
The use of Libft and ft_printf is allowed, and it is necessary to first compile the library using its Makefile, and then compile the project.

In the flags I used ***-g -fsanitize=address*** which is used a lot like valgrind but in the Makefile. ONLY SHOWS ERRORS IF THERE ARE ANY, OTHERWISE IT SHOWS NOTHING.

This option is used because using valgrind will not return anything, since the program ends (goes into excve).

## Checks to be performed
./pipex infile cat "wc -l" outfile

./pipex infile cat **nonexistingcommand** outfile

./pipex **emptyfile** cat "wc -c" outfile

--> chmod 000 infile (change permissions)

./pipex infile cat "wc -l" outfile

--> chmod 000 outfile

./pipex infile cat "wc -l" outfile

./pipex infile "grep pipex" "wc -w" outfile

./pipex **nonexistentfile** cat "wc -l" outfile

./pipex infile **"grep nonexistentword"** "wc -l" outfile

**env -i** ./pipex infile ls pwd outfile → Proves if the environment variable passed is null, it MUST NOT GIVE SEGFAULT


TO SHOW THE OUTPUT (the error number) WE USE *echo $?*
