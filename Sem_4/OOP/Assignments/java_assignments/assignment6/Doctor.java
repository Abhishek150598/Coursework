package asg_6;

import java.util.Scanner;

public class Doctor 
{
	static int count;
	public String name;
	private String doctor_id;
	private int age;
	private String gender;
	public int patient_count;
	
	Doctor(String name, int age, String gender)
	{
		count++;
		this.name=name;
		this.age=age;
		this.gender=gender;
		doctor_id=name.substring(0,3).toUpperCase()+String.format("%05d", count);
		patient_count=0;
	}
	
	Doctor()
	{
		count++;
		patient_count=0;
	}
	
	public void add_doctor(Scanner sc)
	{
		System.out.println("Enter doctor name: ");
		name=sc.next();
		System.out.println("Enter doctor's age: ");
		age=sc.nextInt();
		System.out.println("Enter gender of doctor");
		gender=sc.next();
		doctor_id=name.substring(0,3).toUpperCase()+String.format("%05d", count);
		System.out.println("Doctor successfully registered with Doctor ID "+ doctor_id);
		
	}
	
	public void show_list()
	{
		System.out.println(name+"\t\t\t\t"+patient_count);
	}
}
