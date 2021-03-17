

import java.io.IOException;
import java.sql.Connection;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


public class ItemDetailsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String category = request.getParameter("category");
		int item_id = Integer.parseInt(request.getParameter("item_id"));
		
		HttpSession session = request.getSession();
		int clicks = (Integer) session.getAttribute("netClicks");
		if(category.equals("new")) {
			session.setAttribute("netClicks", clicks + 1);
		}
		else {
			session.setAttribute("netClicks", clicks - 1);
		}
		
		Connection con=(Connection)getServletContext().getAttribute("conn");
		Item item = ItemDetailsDAO.getItemDetails(item_id, con);
		
		request.setAttribute("item", item);
		RequestDispatcher rd = request.getRequestDispatcher("itemDetails.jsp");
		rd.forward(request, response);
		
	}

}
