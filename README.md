# stack-and-queue-of-data-structure
## Data structure | Stack & Queue
__Deal with the orders of brackets ( ) [ ] { } with the help of the stack and queue!!__


Language: C </br>
> The repository includes:
* 1 source file
* 1 input_txt (for testing the source code)
* 1 demmand for the code (in Chinese; complete requirement for the tasks)

TASK concerning **Stack & Queue** :</br>
*   **Write an `algorithm`: **
*  __first__ input a casual string incuding brackets ( ) [ ] { } along with other characters
*  __then__　detect whether the brackets match:

>Example:  
【input format】  
Let the program read the string in "input.txt"(create one yourself in your file!). The string should not include the space.  
【output format】  
Let the program write the result into "output.txt". If the brackets match, `True` will be shown; if not, `False` will be shown.  
P.S. If the string includes the space or some errors occur in the program, `Error` will be shown.  
【input example(in __input.txt__)】  
Er45[d(d)a-fasdf[fdf{asfdf}]  
【output example(in __output.txt__)】   
False

***

### Preview:

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	char sign;
	struct Node*pNext;
}NODE, *PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void output_true(FILE *p);
void output_false(FILE *p);
void output_error(FILE *p);
int init(PSTACK ps);
int push (PSTACK ps, char ch);
int pop(PSTACK ps, char*psign);
int empty(PSTACK ps);
int decide_s (char s[],FILE *p, PSTACK ps);


```

### Say thanks to ...
This project is my assignment for the course Data Structure when I was a first-year student at :blue_book: [the Department of Electrical Engineering at South China University of Technology](http://www.scut.edu.cn/ee/). </br>
I really appreciate the guidance and help from my teacher Dr. Qin, along with my classmates.:bowtie:

## Please feel free to give suggestions and comments!
