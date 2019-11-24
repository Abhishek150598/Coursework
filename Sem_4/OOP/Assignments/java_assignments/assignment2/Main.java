package asg_2;
import java.util.Scanner;

public class Main 
{
	static void SEO(Scanner sc, Item_list il)
	{
		char ch='y';
		while(ch=='y')
		{
			System.out.println("Enter choice: ");
			System.out.println("1. Add new item");
			System.out.println("2. Change price ");
			System.out.println("3. Receive item");
			System.out.println("4. Issue item");
			System.out.println("5. Check price for a given item");
			System.out.println("6. Display item list");
			System.out.println("7. Display items costing above a given price");
			int c = sc.nextInt();
			switch(c)
			{
				case 1: il.add_item(sc);
						break;
				case 2: il.change_rate(sc);
						break;
				case 3: il.receive_item(sc);
						break;
				case 4: il.issue_item(sc);
						break;
				case 5: il.get_data(sc);
						break;
				case 6: il.show_list();
						break;
				case 7: il.show_list_price(sc);
						break;
				
			}
			System.out.println("Want more choices?");
			ch=sc.next().charAt(0);
		}
	}
	
	static void SK(Scanner sc, Item_list il)
	{
		char ch='y';
		while(ch=='y')
		{
			System.out.println("Enter choice: ");
			System.out.println("1. Receive item");
			System.out.println("2. Issue item");
			System.out.println("3. Check price for a given item");
			System.out.println("4. Display item list");
			System.out.println("5. Display items costing above a given price");
			int c = sc.nextInt();
			switch(c)
			{
				case 1: il.receive_item(sc);
						break;
				case 2: il.issue_item(sc);
						break;
				case 3: il.get_data(sc);
						break;
				case 4: il.show_list();
						break;
				case 5: il.show_list_price(sc);
						break;
				
			}
			System.out.println("Want more choices?");
			ch=sc.next().charAt(0);
		}
	}
		
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Item_list il = new Item_list();
		int user=1;
		while(user>0&&user<3)
		{	
			System.out.println("Enter User type");
			System.out.println("1. Stock entry operator");
			System.out.println("2. Shopkeeper");
			user = sc.nextInt();
			switch(user)
			{
				case 1: SEO(sc,il);
						break;
				case 2: SK(sc,il);
						break;
			}
		}
		sc.close();
	}
}
