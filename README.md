# Homework 1: Blazersh

We were tasked too create a simple shell in C and implement different commands,
I/O redirection and other aspects. Some of the commands needed to be implemented
were things such as CD - to change directory, List - to list current files in
directory, or Help to display implemented commands.

## Created by Robert Rummell

# Getting Started

## Prerequisities and dependencies for the shell are
- Linux
- A C compiler such as gcc
- A basic knowledge of Linux
## Instructions for building the software

1. Navigate to directory where makefile and blazersh.c are stored
2. type make
3. ...
4. Profit

## How to run test cases
To run test cases navigate to the programs folder using < cd program > then run
different test cases such as ./p1, ./p2, ./myprog < input.txt > output.txt

# Screenshots
## myprog

[myprog](docs/myprog.PNG)

## ./p1 ./p2 and ./p3

[p1](docs/p1.PNG)

## list
[lists](docs/list.png)

# Homework 2
## Added implementation for &, jobs, and piping!
implemented &, jobs, and piping in the blazersh shell.

# Test cases

## &
For & i executed the command ./timer > output.txt & which checks the arguments,
IO redirection and an ampersand and made sure it ran a simple timer that output
to output.txt and I did not have to wait for the next one to finish to execute 
another command [&](docs/&.png)

## Piping
For piping I used test cases such as the ones provided to us and ls|wc
this would take ls in as input for the wc command [LS](docs/ls.png)

## Jobs
For jobs I owuld run multiple timers and then run the jobns command to see if the 
multiple timers showed up [jobs](docs/jobs.png)

Get in touch
Email: rmr5243@uab.edu