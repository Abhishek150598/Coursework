package asg_6;

import java.util.Scanner;

public class Patient 
{
	static int count;
	private String name;
	public String patient_id;
	private int age;
	private String gender;
	private int blood_pressure;
	private int temp;
	private String doctor_name;
	public int status;
	
	public void add_patient(Scanner sc, Doctor_list dl)
	{
		count++;
		status=1;
		System.out.println("Enter patient name: ");
		name=sc.next();
		System.out.println("Enter patient age: ");
		age=sc.nextInt();
		System.out.println("Enter gender of patient");
		gender=sc.next();
		patient_id=name.substring(0,3).toUpperCase()+String.format("%05d", count);
		System.out.println("Patient successfully registered with Patient ID "+ patient_id);
		doctor_name=dl.assign_doctor();
		System.out.println("Patient assigned to Doctor: "+ doctor_name);
	}
	
	public void add_patient_record(Scanner sc)
	{
		System.out.println("Enter blood pressure: ");
		blood_pressure=sc.nextInt();
		System.out.println("Enter temperature: ");
		temp=sc.nextInt();
	}
	
	public void show_patient_record()
	{
		System.out.println("Patient name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Gender: "+gender);
		System.out.println("Doctor: "+doctor_name);
		System.out.println("Blood pressure: "+blood_pressure);
		System.out.println("Temperature: "+blood_pressure);
		
	}
	
	public void remove_patient(Scanner sc,Doctor_list dl)
	{
		status=0;
		dl.remove_patient(doctor_name);
	}
	
	public void show_list()
	{
		System.out.println(name+"\t\t\t"+doctor_name);
	}
	
	
	
}
