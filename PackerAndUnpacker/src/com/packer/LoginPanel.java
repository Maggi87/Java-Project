package com.packer;
import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class LoginPanel 
{
	static JFrame f;
	static JButton b;
	static JLabel user,pass,error1,error2,attempt,date,time;
	static JTextField usename;
	static JPasswordField password;
	static DateFormat df, ts;
	public static void main(String arg[])
	{
		df = new SimpleDateFormat("dd/MM/yyyy");
		ts = new SimpleDateFormat("HH:mm:ss");
		Date dateobj = new Date();
		
		f = new JFrame("Packer and Unpacker");
		b = new JButton("Login");
		
		user = new JLabel("Username");
		pass = new JLabel("Password");
		error1 = new JLabel();
		error2 = new JLabel();
		attempt = new JLabel();
		date = new JLabel("Date : "+df.format(dateobj));
		time = new JLabel("Time : "+ts.format(dateobj));
		
		usename =new JTextField();
		password =new JPasswordField();
		
		user.setForeground(Color.white);
		pass.setForeground(Color.white);
		error1.setForeground(Color.red);
		error2.setForeground(Color.red);
		attempt.setForeground(Color.white);
		date.setForeground(Color.white);
		time.setForeground(Color.white);
		
		f.getContentPane().setBackground(new Color(0, 51, 128));
		
		date.setBounds   (400,5,100,40);
		time.setBounds   (400,25,150,40);
		
		user.setBounds   (100,150,100,40);
	    usename.setBounds(170,160,200,25);
	    error1.setBounds (375,160,100,10);
	    
		pass.setBounds    (100,210,100,40);
		password.setBounds(170,210,200,25);
		error2.setBounds  (375,210,100,10);
		
		b.setBounds(170,265,100,30);
		attempt.setBounds(170,230,100,30);
		
		f.add(attempt);	
		f.add(date);
		f.add(time);
		f.add(b);
		f.add(user);
		f.add(pass);
		f.add(error1);
		f.add(error2);
		f.add(usename);
		f.add(password);
		f.setSize(600,500);
		f.setLayout(null);
		f.setVisible(true);
		
		b.addActionListener(new Login());
	}
}

class Login implements ActionListener
{
	String username = "Admin";
	String password = "Admin";
	static int i = 0;
	
	LoginPanel lp;
	public Login() {
	}
	
	public Login(LoginPanel obj)
	{
		this.lp = obj;
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		if((lp.usename.getText().isEmpty())&&(lp.password.getText().isEmpty()))
		{
			lp.error1.setText("*");
			lp.error2.setText("*");
		}
		else
		{
			if((lp.usename.getText().equals("Admin")) && (lp.password.getText().equals("Admin")))
			{
				Home h = new Home();
				lp.f.dispose();
			}
			else
			{
				i++;
				lp.attempt.setText("Attempt : "+i+"/3");
				lp.error1.setText("");
				lp.error2.setText("");
				if(i == 3)
				{
					JOptionPane.showMessageDialog(null, "You Have Already Attemp Three Time.. Please Try again letter.");
					lp.f.dispose();
				}
			}
		}
	}
}
