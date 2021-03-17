import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import java.sql.*;

@WebListener
public class MyListener implements ServletContextListener {
	@Override
	public void contextInitialized(ServletContextEvent sce) {
		ServletContext sc = sce.getServletContext();
		String connString = sc.getInitParameter("connString");
		String connUser = sc.getInitParameter("connUser");
		String connPwd = sc.getInitParameter("connPwd");
		System.out.println("Parameters are " + connString + " " + connUser);
		try{  
			Class.forName("com.mysql.cj.jdbc.Driver");  
			Connection con = DriverManager.getConnection(  
				connString,connUser,connPwd);  
			sc.setAttribute("conn",con);
			System.out.println("Database connection successful");
		}catch(Exception e){ System.out.println(e);}
		
	}
	@Override
	public void contextDestroyed(ServletContextEvent sce) {
		System.out.println("Value deleted from context.");
	}
} 