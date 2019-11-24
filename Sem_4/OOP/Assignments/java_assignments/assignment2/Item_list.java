package asg_2;

import java.util.Scanner;

public class Item_list 
{
	private int item_count;
	private Item i[];
	
	Item_list()
	{
		i = new Item[500];
		item_count=0;
		for(int j=0;j<500;j++)
		{
			i[j]=new Item();
		}
	}
	
	public void add_item(Scanner sc)
	{
		System.out.println("Enter item name: ");
		String item_name = sc.next();
		if(check_avail(item_name)==true)
		{
			System.out.println("Item is already entered");
			return;
		}
		i[item_count].set_data(sc, item_name);
		item_count++;
		System.out.println("Item successfully added");
	}
	
	public boolean check_avail(String item_name)
	{
		for(int j=0;j<item_count;j++)
		{
			if(item_name.equalsIgnoreCase(i[j].get_name()))
					return true;

		}
		return false;
	}
	
	public void change_rate(Scanner sc)
	{
		System.out.println("Enter item code: ");
		String icode=sc.next();
		for(int j=0;j<item_count;j++)
		{
			if(icode.equalsIgnoreCase(i[j].get_code()))
			{
				i[j].change_rate(sc);
				return;
			}

		}
		System.out.println("Item does not exist");
	}
	
	public void receive_item(Scanner sc)
	{
		System.out.println("Enter item code: ");
		String icode=sc.next();
		for(int j=0;j<item_count;j++)
		{
			if(icode.equalsIgnoreCase(i[j].get_code()))
			{
				i[j].receive_item(sc);
				return;
			}

		}
		System.out.println("Item does not exist");
	}
	
	public void issue_item(Scanner sc)
	{
		System.out.println("Enter item code: ");
		String icode=sc.next();
		for(int j=0;j<item_count;j++)
		{
			if(icode.equalsIgnoreCase(i[j].get_code()))
			{
				i[j].issue_item(sc);
				return;
			}

		}
		System.out.println("Item does not exist");
	}
	
	public void get_data(Scanner sc)
	{
		System.out.println("Enter item code: ");
		String icode=sc.next();
		for(int j=0;j<item_count;j++)
		{
			if(icode.equalsIgnoreCase(i[j].get_code()))
			{
				i[j].get_data();
				return;
			}

		}
		System.out.println("Item does not exist");
	}
	
	public void show_list()
	{
		System.out.println("Name\t\tCode\t\tPrice\t\tQuantity");
		for(int j=0;j<item_count;j++)
		{
			i[j].get_row();
		}
	}
	public void show_list_price(Scanner sc)
	{
		System.out.println("Enter price: ");
		float p=sc.nextFloat();
		System.out.println("Name\t\tCode\t\tPrice\t\tQuantity");
		for(int j=0;j<item_count;j++)
		{
			if(i[j].get_price()>p)
			{
				i[j].get_row();
			}
		}
	}
}
