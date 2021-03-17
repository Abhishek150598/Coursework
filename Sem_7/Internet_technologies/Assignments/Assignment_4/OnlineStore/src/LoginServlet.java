

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		
		// Getting con object from Servlet Context
		Connection con=(Connection)getServletContext().getAttribute("conn");
		Boolean success = LoginDAO.login(username, password, con);
		
		if(success) {
			// Setting username in session
			HttpSession session = request.getSession();
			session.setAttribute("username", username);
			session.setAttribute("netClicks", 0);
			System.out.println("Login successful");
			response.sendRedirect("itemsList");
			
		}
		else {
			System.out.println("Login failed");
			PrintWriter out = response.getWriter();
			out.println("<h1>Invalid username or password</h1>");
			
		}
	}

}
