# Introduction to Threads
Let's first cover some terminologies before moving on to creating threads.
###Programming Constructs
Uptill know you have been used to sequential programs. Programs that executed code sequentially i.e instructions were executed line after line.
This way of programming dosen't help us reach the full potential of the CPU power & memory alloted to us. 
In order to utilize these multiple-core processors we have concurrent & parralell programming . For now we'll look into concurrent programming.
Unlike sequential programs that execute step by step a concurrent program is one in which multiple tasks can be in progress at any instant.
Let's take the example of a restaurant. 
In case of sequential execution 
the waiter takes an order gives it to the cook. The cook prepares it & the waiter waits. Once the food is prepared the waiter serves it the meal & than takes the next order
  
  

- sample_main.c             ( where are main function resides )

- sample_header.h           ( function prototypes )

- sample_functions.c        ( implementation of function prototypes )

**sample_main.c**

```c
#include <stdio.h>
#include "sample_header.h"

int main(int argc, char *argv[])
{
        print_hello();
}
```

**sample_header.h**

```c
void print_hello();
```
**sample_functions.c**

```c
#include <stdio.h>
#include "sample_header.h"


void print_hello()
{
    printf("Hello AKLSALKA\n");
}
```

The trivial way to compile the files and obtain an executable, is by running the command −

```bash
gcc -o sample sample_main.c sample_functions.c
```

This command generates a program or binary by the name `sample`. In this example we have only two source(.c) files and we know the sequence of the function calls. Hence, it is feasible to type the above command and prepare a final program.

However, for a large project where we have thousands of source code files, it becomes difficult to maintain the program builds. Infact just imagine the length of the command as the no of source files increases. 

The `make` command allows you to manage large programs or groups of programs. As you begin to write large programs, you notice that re-compiling large programs takes longer time than re-compiling short programs. Moreover, you notice that you usually only work on a small section of the program ( such as a single function ), and much of the remaining program is unchanged.

In this section, we see how to prepare a `makefile` for our project.

To first understand makefiles, let's recall the basic steps our source code goes through before we get a program, 

### Compiling :

Recall that we write our source code in C, but need to compile it to machine code, i.e binary, before our computers can run it.

`Compiling` source code into machine code is actually made up of smaller steps:

1. preprocessing
2. compiling
3. assembling
4. linking

`Preprocessing` involves looking at lines that start with a '#', like #include, before everything else. For example, #include "sample_functions.h" will tell gcc to look for that header file first, since it contains content that we want to include in our program. Then, gcc will essentially replace the contents of those header files into our program.
You can check the preprocessing by using the following command :
```bash
$gcc -E file.c
```

`Compiling` takes our source code, in C, and converts it to assembly code.These instructions are lower-level and can be understood by the CPU more directly, and generally operate on bytes themselves, as opposed to abstractions like variable names.
You can generate the assembly code by using the following command :
```bash
$gcc -S file.c
```
`Assembling` The next step is to take the assembly code and translate it to instructions in binary by assembling it.
You can generate the binary or object file by using the following command :
```bash
$gcc -c file.c
```
`Linking` Now, the final step is linking, where the contents of linked libraries, like sample_functions.c , are actually included in our program as binary.
You can link the final program using the following command :
```bash
$gcc -o program file_1.o file_2.o
```
Since now we've cleared what compiling is let's move on to the next step.

### Creating Makefiles

Creating a makefile is as simple as following : 
```bash
$touch makefile
```
the term "makefile" typically refers to a file named `makefile`, which is used to build source code into an executable program. This type of file does not have a file extension.

A makefile includes targets & dependencies sepearted by a `:`.Dependencies are important because they let the 'make' cmd know about the source for any target.

Consider the following example −
```bash
sample: sample_main.o sample_functions.o
	gcc -o sample sample_main.o sample_functions.o
```
Here, we tell 'make' that the target 'sample' is dependent on sample_main.o, sample_functions.o files. Hence, whenever there is a change in any of these object files, make will take action.

At the same time, we need to tell 'make' how to prepare sample_main.o sample_functions.o (object or binary) files. Hence we need to define those dependencies also as follows −	
```bash
sample_main.o: sample_main.c sample_header.h
	gcc -c sample_main.c
```

```bash
sample_functions.o: sample_functions.c sample_header.h
	gcc -c sample_functions.c
```
The '-c' argument after 'gcc' simply tells the compiler to generate binary(.o extension) files or in other words to simply not link external libraries or files.
The argument is there to simply break the compiling steps , because if you just typed '$gcc sample_main.c' it won't compile as we call a function that is declared in a seperate file 'sample_functions.c', & to compile sample_main.c we need
that file already in binary form, & thus the need for breaking the compile process.

And thus the final makefile looks like this :
```bash
all: sample

sample: sample_main.o sample_functions.o
	gcc -o sample sample_main.o sample_functions.o
	
sample_main.o: sample_main.c sample_header.h
	gcc -c sample_main.c
	
sample_functions.o: sample_functions.c sample_header.h
	gcc -c sample_functions.c
	
clean : 
	rm ./*.o sample
```
The last line simply cleans the the directory if you want a completely fresh build .

So now in order to compile we simply need to place this makefile in the project folder . 
On the terminal simply run the command to compile :	

```bash
$make all
```



