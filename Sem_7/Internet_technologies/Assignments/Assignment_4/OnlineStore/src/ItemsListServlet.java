

import java.io.IOException;
import java.sql.Connection;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ItemsListServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession();
		String username = (String) session.getAttribute("username");
		int netClicks = (Integer) session.getAttribute("netClicks");
		
		Connection con=(Connection)getServletContext().getAttribute("conn");
		ArrayList<Item> newItems = ItemsListDAO.getItemsList(username, "new", netClicks, con);
		ArrayList<Item> discItems = ItemsListDAO.getItemsList(username, "discount", netClicks, con);
		
		request.setAttribute("newItems", newItems);
		request.setAttribute("discItems", discItems);
		RequestDispatcher rd = request.getRequestDispatcher("itemsList.jsp");
		rd.forward(request, response);
		
	}
}
