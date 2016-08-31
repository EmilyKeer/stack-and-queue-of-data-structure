/*假设一个输入字符串中包含圆括号、方括号和花括号三种类型的括号，以及其它一些任意字符。编写程序，判别串中的括号是否正确匹配，即：
1. 各种左、右括号的个数要一致；
2. 要符合正确的嵌套规则。
*/
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
int main()
{
	int num, flag;   //definition first 
	char s[200];
	STACK stack;
	PSTACK ps = &stack; //definition first 
	FILE *fp, *fp1;
	if ((fp=fopen("input.txt","r"))==NULL) //the file should be placed in the folder(same name),the same root with C source
	{
		exit(0);
	}
	fscanf(fp,"%d",&num); //get the number
	fseek(fp, 2L, 1);  //move forward 2L bytes (/r/n)
	if (fgets(s,201,fp)==NULL) //get the string,200+1
	{
		exit(0);
	}
	//printf("%d %s",num, s);
	if((fp1=fopen("output.txt","w"))==NULL)//oepn output file
	{
		exit(0);
	}
	if (num>200)
	{
		output_false(fp1);
		exit(0);
	}
	init(ps);
	flag = init(ps); //flag: build a stack sucessfully?
	if (flag==0)
	{
		output_error(fp1);
		exit(0);
	}
	
	if(decide_s (s, fp1, ps))
		{
			output_true(fp1);
	};
	fcloseall();  //close all files
	return 0;
}

void output_true(FILE *p)
{
	fprintf(p, "%s", "True\r"); //"Enter"
	fcloseall();  //close all files
}
void output_false(FILE *p)
{
	fprintf(p, "%s", "False\r"); //"Enter"
	fcloseall();  //close all files
}
void output_error(FILE *p)
{
	fprintf(p, "%s", "Error\r"); //"Enter"
	fcloseall();  //close all files
}

int decide_s (char s[], FILE *p, PSTACK ps )
{
	int i, j, large=0, mid=0, small=0, temp=0;
	char ch;
	for (i=0; s[i]!='\0';i++) //no space(check)
	{
		if(s[i]==' ')
		{
			output_error(p);
			exit(0);
		}
	}
	for(i=0; s[i]!='\0'; i++)
	{
		switch(s[i])
		{
		case('{'):
			if(mid>0 || small>0)
			{
				output_false(p);
				exit(0);
			}
			else 
			{large++;
	          if (push (ps,s[i])==0)
	       {
		   output_error(p);
		    exit(0);
	             }
			}
		break;
		case('['):
			if(small>0)
			{
				output_false(p);
				exit(0);
			}
			else
			{
				mid++;
				 if (push (ps,s[i])==0)
	       {
		   output_error(p);
		    exit(0);
	             }
			}
		break;
		case('('):
			small++;
			if (push (ps,s[i])==0)
	       {
		   output_error(p);
		    exit(0);
	             }
		break;

		case(']'):////////////////////////////////////
			for(j=temp; j<=i; j++)
			{
				switch(s[j])
				{
				case(')'):
					pop(ps,&ch);
					if(ch != '(')
					{
						output_false(p);
						exit(0);
					}
					else small--;
						break;

				case(']'):
					pop(ps,&ch);
					if(ch != '[')
					{
						output_false(p);
						exit(0);
					}
					else mid--;
						break;
				

				default: ;
				}
			}
			temp = i+1;
			break;

			case ('}')://///////////////////////////////
				for(j=temp; j<=i; j++)
			{
				switch(s[j])
				{
				case(')'):
					pop(ps,&ch);
					if(ch != '(')
					{
						output_false(p);
						exit(0);
					}
					else small--;
						break;

				case(']'):
					pop(ps,&ch);
					if(ch != '[')
					{
						output_false(p);
						exit(0);
					}
					else mid--; 
						break;
				

				default: ; //attention to ';'
				}
			}
				pop(ps,&ch);
				if (ch != '{')
				{
					output_false(p);
					exit(0);
				}
				else {large--; temp = i+1;}
				break;

			case(')'): ///////////////////////////////////////////////////////////
					pop(ps,&ch); 
					if(ch != '(')
					{
						output_false(p);
						exit(0);
					}
					else {small--; temp = i+1;}
					break;

				default: ;
		}
	}
	if (!empty(ps))
	{
		output_error(p);
		exit(0);
	}
	return 1; //nothing is wrong
}

int init(PSTACK ps)
{
	int flag=1;
	ps->pTop = (PNODE)malloc(sizeof(NODE));
	if (ps->pTop==NULL)
	{
		flag=0;
	}
	else 
	{
		ps->pBottom = ps->pTop;
		ps->pTop->pNext = NULL;
	}
	return flag;
}

int push (PSTACK ps, char ch)
{
	int flag=1;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		flag = 0;
	}
	else
	{
		pNew->pNext = ps->pTop;
		pNew->sign = ch;
		ps->pTop = pNew;
	}
	return flag;
}

int pop(PSTACK ps, char*psign)  //sign->pointer
{
	int flag=1;
	if (empty(ps))
	{
		flag=0;
	}
	else
	{
		PNODE r=ps->pTop;
		ps->pTop=r->pNext;
		*psign=r->sign;
		free(r);
		r=NULL;
	}
return flag;
}

int empty(PSTACK ps)
{
	int flag;
	if (ps->pTop == ps->pBottom)
		flag = 1;
	else flag = 0;
	return flag;
}