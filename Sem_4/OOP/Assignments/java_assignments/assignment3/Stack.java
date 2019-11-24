package asg_3;


class Stack
{
	private char arr[];
	private int top;
	private int capacity;

	Stack(int size)
	{
		arr = new char[size];
		capacity = size;
		top = -1;
	}

	public void push(char x)
	{
		
		arr[++top] = x;
	}

	public void pop()
	{
		
		top--;
	}

	public char top()
	{
		return arr[top];
	}
	
	public int size()
	{
		return top + 1;
	}

	public Boolean empty()
	{
		return top == -1;	
	}

	public Boolean full()
	{
		return top == capacity - 1;	
	}
}