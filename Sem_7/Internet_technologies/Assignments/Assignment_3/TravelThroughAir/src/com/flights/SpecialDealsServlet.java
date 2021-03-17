package com.flights;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class SpecialDealsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private ArrayList<SpecialDeal> getData() {
		ArrayList<SpecialDeal> special_deals = new ArrayList<>();
		
		special_deals.add(new SpecialDeal("Delhi", "Kolkata", 3400));
		special_deals.add(new SpecialDeal("Kolkata", "Delhi", 7890));
		special_deals.add(new SpecialDeal("Hyderabad", "Kolkata", 2890));
		special_deals.add(new SpecialDeal("Delhi", "Shimla", 3000));
		special_deals.add(new SpecialDeal("Delhi", "Hyderabad", 3550));
		special_deals.add(new SpecialDeal("Patna", "Agra", 2560));
		special_deals.add(new SpecialDeal("Kolkata", "Agra", 7800));
		special_deals.add(new SpecialDeal("Kolkata", "Jaipur", 7800));
		special_deals.add(new SpecialDeal("Bhopal", "Jaipur", 2800));
		special_deals.add(new SpecialDeal("Shimla", "Delhi", 3000));
		special_deals.add(new SpecialDeal("Kolkata", "Hyderabad", 3550));
		special_deals.add(new SpecialDeal("Patna", "Delhi", 2560));
        return special_deals;
    } 
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		ArrayList<SpecialDeal> special_deals = getData();
		
		request.setAttribute("sd", special_deals);
		RequestDispatcher rd = request.getRequestDispatcher("home.jsp");
		rd.forward(request, response);
	}

}
