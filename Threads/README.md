# Introduction to Threads
Let's first cover some terminologies before moving on to creating threads.
### 1.1 Programming Constructs
Uptill know you have been used to sequential programs. Programs that executed code sequentially i.e instructions were executed line after line.
This way of programming dosen't help us reach the full potential of the CPU power & memory alloted to us. 
In order to utilize these multiple-core processors we have concurrent & parrallel programming . For now we'll look into concurrent programming.
Unlike sequential programs that execute step by step a concurrent program is one in which multiple tasks can be in progress at any instant.
Let's take the example of a restaurant. 
In case of sequential execution : 
- the waiter takes an order gives it to the cook. 
- the cook prepares it & the waiter waits 
- Once the food is prepared the waiter serves the meal & than takes the next order
In case of concurrent execution : 
- the waiter takes an order gives it to the cook. - 
- the cook prepares it & the waiter takes the next order
- Once the food is prepared the waiter serves the meal .

The key diffrence here is that the waiter dosn't wait for the preparation of the food but carries on taking orders i.e perfoming other tasks while one task is being performed. This is possible in our programs as well where we can break one task(A Single Thread) into smaller tasks(Multiple Threads) for better performance.
  
When were dealing with concurrent programs we also need to enforce : 
- Serialization 	: Event A better happen before an Event B .
- Mutual Exclusion 	: Event A & B must not happen at the same time .

### 1.2 THREADS
A thread is a basic unit of execution of a process. When we say a program is running, it typically means that a process is loaded in memory & a single task is being performed by that process. That single task(unit of execution) is known as a thread.Threads are a way for a program to divide (termed "split") itself into two or more simultaneously (or pseudo-simultaneously) running tasks.
Threads and processes differ from one operating system to another but, in general, a thread is contained inside a process and different threads in the same process share the same resources while different processes in the same multitasking operating system do not. Threads are lightweight, in terms of the system resources they consume, as compared with processes.

A thread consists of the information necessary to represent an execution context
within a process. This includes a thread ID that identifies the thread within a process, a
set of register values, a stack, a scheduling priority and policy, a signal mask, an errno
variable, and thread-specific data. 
Everything within a process is sharable among the threads in a process, including the text of the executable
program, the program’s global and heap memory, the stacks, and the file descriptors.
The threads interfaces we’re about to see are from POSIX.1-2001. The threads interfaces, also known as ‘‘pthreads’’ for ‘‘POSIX threads. 


**Thread Creation**

With pthreads, when a program runs, it also starts out as a single
process with a single thread of control also known as the main-thread. As the program runs, its behavior should be
indistinguishable from the traditional process, until it creates more threads of control.
Additional threads can be created by calling the pthread_create function.

```c
#include <pthread.h>

int pthread_create(thread_id,
		   thread_attributes,
		   thread_function, 
		   thread_arg);

```
```c
	pthread_t thread_id;
```
- thread_id		: When pthread_create returns successfully this variable will have all the newly created thread's 			    id.
```c
	NULL
```
- thread_attributes	: This attr argument is used to customize various thread attributes. We’ll cover thread attributes 			     later. For now, we’ll set this to NULL to create a thread with the default attributes.
```c
	void *thread_function(void* no)
	{
        	int *no1 = (int*)no;
        	*no1 = *no1 + 1;
        
	}
```
- thread_function 	: The newly created thread runs this function when it starts. 
```c
	int thread_arg = 55;
```
- thread_arg		: The function takes only a single argument for now . If you need to
			  pass more than one argument to thread_function, then you need to store them in a
			  structure and pass the address of the structure as thread_arg.

**NOTE**
When a thread is created, there is no guarantee which will run first: the newly
created thread or the calling thread. The newly created thread has access to the process
address space.

Just like in the case of process creation if you want all threads to complete before the program finishes the main-thread has to wait(join) for all the threads it created before terminating because if the main-thread exists before the other threads the other threads will be killed by the OS. 

**THREAD JOIN**
```c
pthread_join(thread_id,NULL);
```
The final code now looks like this : 
**thread.c**
```c
#include <stdio.h>
#include <pthread.h>
void *thread_function(void* no)
{
        int *no1 = (int*)no;
        *no1 = *no1 + 1;
        
}
int main(int argc, char *argv[])
{
            pthread_t thread_id;
            
            int thread_arg = 55;
            
            printf("The value was %d \n",thread_arg);
            
            pthread_create(&thread_id, NULL, thread_function, &thread_arg);
            
            pthread_join(thread_id,NULL);
            
            printf("The value is %d \n",thread_arg);
}
```
```bash
$gcc thread.c -lphthread
`



