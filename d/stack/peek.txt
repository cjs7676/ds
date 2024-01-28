#include<iostream>
int MAXSIZE = 8;
int stack[8];
int top = -1;
int isfull()
{
	if(top ==MAXSIZE)
		return 1;
	else
		return 0;
}
 int peek()
 {
 	return stack[top];
 }

int push(int data)
{
	if(!isfull())
	{
		top = top + 1;
		stack[top] = data;
	}
	else
	{
		printf("could not insert data, stack is full. \n ");
	}
	return data;
}

int main()
{
	int i;
	push(44);
	push(10);
	push(15);
	printf("stack element:\n ");
	for(i=0; i<3; i++)
	{
		printf("%d", stack[i]);
	}
	printf("\n element at top of the stack: %d \n ", peek());
	printf("\n ");
	return 0;
}