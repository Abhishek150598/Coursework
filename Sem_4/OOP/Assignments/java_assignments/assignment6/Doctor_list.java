package asg_6;

import java.util.Scanner;
public class Doctor_list 
{
	private int dcount;
	private Doctor d[];
	
	Doctor_list()
	{
		d = new Doctor[500];
		d[0]= new Doctor("Ashutosh Khanna",34,"Male");
		d[1]= new Doctor("Rohit Chauhan",54,"Male");
		d[2]= new Doctor("Priya Dutta",45,"Female");
		d[3]= new Doctor("Akansha Purohit",49,"Female");
		d[4]= new Doctor("Dinesh Chatterjee",45,"Male");
		dcount=5;
	}
	
	public void add_doctor(Scanner sc)
	{
		
		d[dcount]=new Doctor();
		d[dcount].add_doctor(sc);		
		dcount++;
	}
	
	public String assign_doctor()
	{
		int min=1000,min_pos=0;
		for(int i=0;i<dcount;i++)
		{
			if(d[i].patient_count<min)
			{
				min=d[i].patient_count;
				min_pos=i;
			}
		}
		d[min_pos].patient_count++;
		return d[min_pos].name;
	}
	
	public void remove_patient(String doctor_name)
	{
		for(int i=0;i<dcount;i++)
		{
			if(doctor_name.equalsIgnoreCase(d[i].name))
			{
				d[i].patient_count--;
			}
		}
	}
	
	public void show_doctor_list()
	{
		System.out.println("Doctor name\t\t\t\tNo of patients");
		for(int i=0;i<dcount;i++)
		{
			d[i].show_list();
		}
	}
}
