package asg_2bmodif;

import java.applet.Applet;
import java.awt.event.*;
import java.awt.*;
import java.util.*;

public class LinkedListApplet extends Applet 
{
	LinkedList <String> ll;
	Button b1,b2,b3,b4;
	TextField search;
	Label message;
	
	public void init()
	{
		ll = new LinkedList <String>();
		b1 = new Button("Insert front");
		b2 = new Button("Delete front");
		b3 = new Button("Insert rear");
		b4 = new Button("Search");
		search = new TextField();
		message = new Label();
		
		setLayout(null);
		b1.setBounds(50,30,80,20);
		b2.setBounds(150,30,80,20);
		b3.setBounds(250,30,80,20);
		b4.setBounds(350,30,80,20);
		search.setBounds(450,30,140,20);
		message.setBounds(100,270,200,20);
		add(b1);
		add(b2);
		add(b3);
		add(b4);
		add(search);
		add(message);
		
		//INSERT FRONT
		class ins_f implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				String s=search.getText();
				ll.addFirst(s);	
				repaint();
				
			}
			
		}
		
		b1.addActionListener(new ins_f());
		//INSERT REAR
		class ins_r implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				String s=search.getText();
				ll.addLast(s);	
				repaint();
				
			}
			
		}
		
		b3.addActionListener(new ins_r());
		
		//DELETE FRONT
		class del_front implements ActionListener
		{
			
			public void actionPerformed(ActionEvent e)
			{
				ll.removeFirst();
				repaint();
			}
		}
		
		b2.addActionListener(new del_front());
		
		class search implements ActionListener
		{
			
			public void actionPerformed(ActionEvent e)
			{
				String s = search.getText();
				Iterator i=ll.listIterator();  
				int j=0,f=0;
				while(i.hasNext())  
				{ 
					 if(s.equalsIgnoreCase(i.next().toString()))
					 {
						 message.setText("String found at position "+j+"!");
						 message.setVisible(true);
						 f=1;
						 break;
					 }
					 j++;
				}
				if(f==0)
				{
					message.setText("String not found!");
					message.setVisible(true);
				}
			}
		}
		
		b4.addActionListener(new search());
	}
	
	public void paint(Graphics g)
	{
		message.setVisible(false);
		Iterator i=ll.listIterator();  
		int j=0;
		while(i.hasNext())  
		{ 
			 g.drawRect(50+120*j,160,100,30);
			 g.drawString(i.next().toString(),90+120*j, 180);
			 j++;
		}
				
		
		
	}
	
	
}
