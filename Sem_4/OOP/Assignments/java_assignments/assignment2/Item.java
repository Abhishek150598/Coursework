package asg_2;

import java.util.Scanner;

public class Item 
{
	static int count;
	private String item_code;
	private String item_name;
	private float rate;
	private int quantity;
	
	public void set_data(Scanner sc, String item_name)
	{
		count++;
		this.item_name=item_name;
		item_code=item_name.substring(0,3).toUpperCase()+String.format("%03d", count);
		System.out.println("Item code is: "+item_code);
		System.out.println("Enter item price: ");
		rate = sc.nextFloat();
		System.out.println("Enter item quantity: ");
		quantity = sc.nextInt();
	}
	
	public void get_data()
	{
		System.out.println("Item name: "+item_name);
		System.out.println("Item code: "+item_code);
		System.out.println("Price: "+rate);
		System.out.println("Quantity: "+quantity);
	}
	public void change_rate(Scanner sc)
	{
		System.out.println("Enter the new price: ");
		rate=sc.nextFloat();
		System.out.println("Price has been successfully updated");
	}
	public void issue_item(Scanner sc)
	{
		System.out.println("Enter quantity to be issued:");
		int q=sc.nextInt();
		if(q>quantity)
		{
			System.out.println("Cannot be issued");
		}
		else
		{
			quantity-=q;
			System.out.println("Issue successful");
		}
		
	}
	
	public void receive_item(Scanner sc)
	{
		System.out.println("Enter quantity to be received:");
		int q=sc.nextInt();
		quantity+=q;
		System.out.println("Reception successful");	
	}
	
	public float get_price()
	{
		return rate;
	}
	
	public String get_name()
	{
		return item_name;
	}
	
	public String get_code()
	{
		return item_code;
	}
	
	public void get_row()
	{
		System.out.println(item_name+"\t\t"+item_code+"\t\t"+rate+"\t\t"+quantity);
	}
}
