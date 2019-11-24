package asg_2b;

import java.applet.Applet;
import java.awt.event.*;
import java.awt.*;
import java.util.*;

public class LinkedListApplet extends Applet 
{
	LinkedList <String> ll;
	Button b1,b2,b3,b4;
	TextField search,t1,t2,t3,t4,t5;
	Label l1,l2,l3,l4,l5,message;
	
	public void init()
	{
		ll = new LinkedList <String>();
		b1 = new Button("Insert front");
		b2 = new Button("Delete front");
		b3 = new Button("Insert rear");
		b4 = new Button("Search");
		l1 = new Label("Enter name");
		l2 = new Label("Enter department");
		l3 = new Label("Marks in subject 1");
		l4 = new Label("Marks in subject 2");
		l5 = new Label("Marks in subject 3");
		search = new TextField();
		message = new Label("");
		t1 = new TextField();
		t2 = new TextField();
		t3 = new TextField();
		t4 = new TextField();
		t5 = new TextField();
		setLayout(null);
		b1.setBounds(50,30,80,20);
		b2.setBounds(150,30,80,20);
		b3.setBounds(250,30,80,20);
		b4.setBounds(350,30,80,20);
		search.setBounds(450,30,140,20);
		l1.setBounds(50,80,120,20);
		l2.setBounds(50,110,120,20);
		l3.setBounds(50,140,120,20);
		l4.setBounds(50,170,120,20);
		l5.setBounds(50,200,120,20);
		t1.setBounds(190,80,160,20);
		t2.setBounds(190,110,160,20);
		t3.setBounds(190,140,160,20);
		t4.setBounds(190,170,160,20);
		t5.setBounds(190,200,160,20);
		message.setBounds(100,270,200,20);
		add(b1);
		add(b2);
		add(b3);
		add(b4);
		add(search);
		add(l1);
		add(l2);
		add(l3);
		add(l4);
		add(l5);
		add(t1);
		add(t2);
		add(t3);
		add(t4);
		add(t5);
		
		//INSERT FRONT
		class ins_f implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				String name=t1.getText();
				String dept_name=t2.getText();
				int m1=Integer.parseInt(t3.getText());
				int m2=Integer.parseInt(t4.getText());
				int m3=Integer.parseInt(t5.getText());
				Student s = new Student(name,dept_name,m1,m2,m3);
				ll.addFirst(s.rollno);	
				repaint();
				
			}
			
		}
		
		b1.addActionListener(new ins_f());
		//INSERT REAR
		class ins_r implements ActionListener
		{
			public void actionPerformed(ActionEvent e)
			{
				String name=t1.getText();
				String dept_name=t2.getText();
				int m1=Integer.parseInt(t3.getText());
				int m2=Integer.parseInt(t4.getText());
				int m3=Integer.parseInt(t5.getText());
				Student s = new Student(name,dept_name,m1,m2,m3);
				ll.addLast(s.rollno);	
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
				int j=0;
				while(i.hasNext())  
				{ 
					 if(s.equalsIgnoreCase(i.next().toString()))
					 {
						 message.setText("Roll number found at position "+j+"!");
						 add(message);
					 }
					 j++;
				}
				
			}
		}
		
		b4.addActionListener(new search());
		
	}
	
	public void paint(Graphics g)
	{
		Iterator i=ll.listIterator();  
		int j=0;
		while(i.hasNext())  
		{ 
			 g.drawRect(50+120*j,230,100,30);
			 g.drawString(i.next().toString(),70+120*j, 250);
			 j++;
		}
				
		
		
	}
	
	
}
