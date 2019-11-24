package asg_6;

import java.util.Scanner;

import asg_2.Item_list;

public class Main 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Doctor_list dl = new Doctor_list();
		Patient_list pl = new Patient_list();
		
		char ch='y';
		while(ch=='y')
		{
			System.out.println("Enter choice: ");
			System.out.println("1. Add new patient");
			System.out.println("2. Add new doctor");
			System.out.println("3. Show patient list");
			System.out.println("4. Show doctor list");
			System.out.println("5. Patient checkup");
			System.out.println("6. Show patient information");
			System.out.println("7. Patient check out");
			
			int choice=sc.nextInt();
			
			switch(choice)
			{
				case 1: pl.add_patient(sc,dl);
						break;
				case 2: dl.add_doctor(sc);
						break;
				case 3: pl.show_patient_list();
						break;
				case 4: dl.show_doctor_list();
						break;
				case 5: pl.add_patient_record(sc);
						break;
				case 6: pl.show_patient_record(sc);
						break;
				case 7: pl.remove_patient(sc,dl);
						break;	
			}
			System.out.println("Want choices again?");
			ch=sc.next().charAt(0);
		}
		
		sc.close();
		
	}
}
