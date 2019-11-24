package asg_6;
import java.util.Scanner;
public class Patient_list 
{
	private int pcount;
	private Patient p[];
	
	Patient_list()
	{
		p = new Patient[500];
		pcount=0;
		for(int i=0;i<500;i++)
		{
			p[i]= new Patient();
		}
	}
	
	public void add_patient(Scanner sc, Doctor_list dl)
	{
		p[pcount].add_patient(sc, dl);
		pcount++;
	}
	
	public void show_patient_record(Scanner sc)
	{
		System.out.println("Enter patient ID");
		String pid=sc.next();
		for(int i=0;i<pcount;i++)
		{
			if(pid.equalsIgnoreCase(p[i].patient_id))
			{
				p[i].show_patient_record();
			}
		}
	}
	
	public void add_patient_record(Scanner sc)
	{
		System.out.println("Enter patient ID");
		String pid=sc.next();
		for(int i=0;i<pcount;i++)
		{
			if(pid.equalsIgnoreCase(p[i].patient_id))
			{
				p[i].add_patient_record(sc);
			}
		}
	}
	
	public void remove_patient(Scanner sc, Doctor_list dl)
	{
		System.out.println("Enter patient ID");
		String pid=sc.next();
		for(int i=0;i<pcount;i++)
		{
			if(pid.equalsIgnoreCase(p[i].patient_id))
			{
				p[i].remove_patient(sc,dl);
			}
		}
	}
	
	public void show_patient_list()
	{
		System.out.println("Patient name\t\t\tDoctor Name");
		for(int i=0;i<pcount;i++)
		{
			if(p[i].status!=0)
			{
				p[i].show_list();
			}
		}
	}
	
}
