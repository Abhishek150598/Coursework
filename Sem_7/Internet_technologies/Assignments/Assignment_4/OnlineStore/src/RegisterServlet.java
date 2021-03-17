

import java.io.IOException;
import java.sql.Connection;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class RegisterServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
  
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String gender = request.getParameter("gender");
		
		
		// Getting con object from Servlet Context
		Connection con=(Connection)getServletContext().getAttribute("conn");
		RegisterDAO.register(username, password, gender, con);
		
		// Setting username in session
		HttpSession session = request.getSession();
		session.setAttribute("username", username);
		session.setAttribute("netClicks", 0);
		
		response.sendRedirect("itemsList");
		
	}

}
