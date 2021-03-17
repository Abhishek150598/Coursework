package com.flights;

public class SpecialDeal {
	private String departureCity;
	private String arrivalCity;
	private int cost;
	
	SpecialDeal(String departureCity, String arrivalCity, int cost) {
		this.departureCity = departureCity;
		this.arrivalCity = arrivalCity;
		this.cost = cost;
	}

	public String getDepartureCity() {
		return departureCity;
	}

	public void setDepartureCity(String departureCity) {
		this.departureCity = departureCity;
	}

	public String getArrivalCity() {
		return arrivalCity;
	}

	public void setArrivalCity(String arrivalCity) {
		this.arrivalCity = arrivalCity;
	}

	public int getCost() {
		return cost;
	}

	public void setCost(int cost) {
		this.cost = cost;
	}
	
}
