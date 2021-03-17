package com.flights;

import java.io.IOException;
import java.util.regex.*;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class FlightServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	private ArrayList<Flight> getData() {
		ArrayList<Flight> flights = new ArrayList<>();
		flights.add(new Flight("Delhi", "Agra", 4000, "10:30", "11:44", 1));
		flights.add(new Flight("Delhi", "Agra", 4600, "10:30", "11:49", 3));
		flights.add(new Flight("Delhi", "Agra", 4050, "10:30", "11:44", 2));
		flights.add(new Flight("Kolkata", "Shimla", 4000, "12:30", "15:30", 1));
		flights.add(new Flight("Kolkata", "Shimla", 6400, "12:30", "15:30", 1));
		flights.add(new Flight("Kolkata", "Shimla", 7800, "12:30", "16:36", 2));
		flights.add(new Flight("Hyderabad", "Delhi", 2300, "10:35", "11:44", 1));
		flights.add(new Flight("Hyderabad", "Delhi", 4500, "10:35", "13:48", 3));
		flights.add(new Flight("Hyderabad", "Delhi", 8800, "10:35", "12:09", 1));
		flights.add(new Flight("Patna", "Jaipur", 8100, "11:20", "12:54", 1));
		flights.add(new Flight("Patna", "Agra", 4600, "10:30", "11:49", 3));
		flights.add(new Flight("Delhi", "Bhopal", 4050, "10:30", "11:44", 2));
        return flights;
    } 
	private boolean isValid(String time) {
        String regex = "([01]?[0-9]|2[0-3]):[0-5][0-9]";  
        Pattern p = Pattern.compile(regex); 

        if (time == null) { 
            return false; 
        } 
        Matcher m = p.matcher(time); 
        return m.matches(); 
	}
	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ArrayList<Flight> flights = getData();
		
		String departureCity = request.getParameter("departureCity");
		String arrivalCity = request.getParameter("arrivalCity");
		String departureTime = request.getParameter("departureTime");
		
		//If both departure and arrival city are same
		if(departureCity.equals(arrivalCity)) {
			request.setAttribute("error", "⚠️ Departure and arrival city cannot be same!");
			RequestDispatcher rd = request.getRequestDispatcher("error.jsp");
			rd.forward(request, response);
		}
		
		//If both departure and arrival city are same
		if(!isValid(departureTime)) {
			request.setAttribute("error", "⚠️ Departure time is invalid!");
			RequestDispatcher rd = request.getRequestDispatcher("error.jsp");
			rd.forward(request, response);
		}
		
		
		ArrayList<Flight> filteredFlights = new ArrayList<Flight>();
		for(Flight f: flights) {
			if(f.getDepartureCity().equals(departureCity) 
				&& f.getArrivalCity().equals(arrivalCity)
				&& f.getDepartureTime().equals(departureTime)) {
				filteredFlights.add(f);
			}		
		}
		
		//If no flights with the given input are available
		if(filteredFlights.size() == 0) {
			request.setAttribute("error", "No such flights found!!");
			RequestDispatcher rd = request.getRequestDispatcher("error.jsp");
			rd.forward(request, response);
		}
		
		request.setAttribute("flights", filteredFlights);
		RequestDispatcher rd = request.getRequestDispatcher("flights.jsp");
		rd.forward(request, response);
	}

}
