package asg_2b;

public class Student 
{
	static int count;
	public String rollno;
	public String name;
	private String dept_name;
	private int m1,m2,m3;
	private int sum;
	private float percent;
	
	Student(String name, String dept_name, int m1, int m2, int m3)
	{
		count++;
		this.name=name;
		this.dept_name=dept_name;
		this.m1=m1;
		this.m2=m2;
		this.m3=m3;
		this.rollno=dept_name.substring(0,3).toUpperCase()+String.format("%03d", count);
		this.sum=m1+m2+m3;
		this.percent=sum/3;
	}
}
