package asg_3;

import java.util.*;

public class Main 
{
	public static void main(String[] args)
	{
		char ch = 'y';
		Scanner sc = new Scanner(System.in);
		while(ch=='y')
		{
			System.out.print("Enter the sequence of brackets: ");
			
			String str=sc.next();
			
			
			Stack s= new Stack(100);
			int f=0;
			for (int i=0; i<str.length(); i++)
	        {
	            
	            if(str.charAt(i)=='}')
	            {
	                if(s.empty()||s.top()!='{')
	                {
	                    f=1;
	                    break;
	                }
	                else
	                {
	                    s.pop();
	                }
	                
	            }
	            else if(str.charAt(i)==']')
	            {
	                if(s.empty()||s.top()!='[')
	                {
	                    f=1;
	                    break;
	                }
	                else
	                {
	                    s.pop();
	                }
	                
	            }
	            else if(str.charAt(i)==')')
	            {
	                if(s.empty()||s.top()!='(')
	                {
	                    f=1;
	                    break;
	                }
	                else
	                {
	                    s.pop();
	                }
	                
	            }
	            else
	            {
	                s.push(str.charAt(i));
	            }
	        }
	        if(f==0&&s.empty())
	            System.out.println("True");
	        else
	        	 System.out.println("False");
	        
	        System.out.println("Want to enter more?");
	        ch=sc.next().charAt(0);
	        
        
		}
		sc.close();
		
	}
	
	
}
