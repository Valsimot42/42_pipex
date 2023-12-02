# Pipex
<p align="center"><img src="https://cdn-images-1.medium.com/v2/resize:fit:1200/1*mb0KkzYAZDDSvdYC2MM5hg.jpeg" width="150" height="150" />

#
<h3><b>¤ Table of contents ¤</b></h3>

1) <b>How to use</b>
2) <b>Introduction</b>
3) <b>Instructions</b>
4) <b>Part 1: Parameters</b>
5) <b>Part 2: Example</b>

---
<h3><b>¤ How to use ¤</b></h3>

* Clone the git repository.
* Add two new files in the `pipex` directory: `file1` and `file2`.
* Execute `make` in terminal.
* Execute the following command in the terminal: `./pipex file1 "ls -l" "wc -l" file2`
* Change the shell commands and add more for testing if you wish.

---
<h3><b>¤ Introduction ¤</b></h3>
<p align="center">In "pipex", we are delving deeper into the concept of pipes of UNIX mechanisms. In short, we are tasked to accurately recreate the behavior of pipes and understand how the input is handled and how the output.

---
<h3><b>¤ Instructions ¤</b></h3>

* Project must be written in C.

* Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors.

* All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and Makefile must not relink.

* Makefile must at least contain the rules $(NAME), all, clean, fclean and re.


---
<h3><b>¤ Part 1: Parameters ¤</b></h3>

<p align="left̨">

* Your program will be executed as follows: `./pipex file1 cmd1 cmd2 file2`
* It must behave exactly the same as the shell command: `$> < file1 cmd1 | cmd2 > file2`

