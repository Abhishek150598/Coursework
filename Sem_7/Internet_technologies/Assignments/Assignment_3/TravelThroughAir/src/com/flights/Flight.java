package com.flights;

public class Flight {
	private String departureCity;
	private String arrivalCity;
	private int cost;
	private String departureTime;
	private String arrivalTime;
	private int numberOfLegs;
	
	public Flight(String departureCity, String arrivalCity, int cost, String departureTime, String arrivalTime,
			int numberOfLegs) {
		super();
		this.departureCity = departureCity;
		this.arrivalCity = arrivalCity;
		this.cost = cost;
		this.departureTime = departureTime;
		this.arrivalTime = arrivalTime;
		this.numberOfLegs = numberOfLegs;
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
	public String getDepartureTime() {
		return departureTime;
	}
	public void setDepartureTime(String departureTime) {
		this.departureTime = departureTime;
	}
	public String getArrivalTime() {
		return arrivalTime;
	}
	public void setArrivalTime(String arrivalTime) {
		this.arrivalTime = arrivalTime;
	}
	public int getNumberOfLegs() {
		return numberOfLegs;
	}
	public void setNumberOfLegs(int numberOfLegs) {
		this.numberOfLegs = numberOfLegs;
	}
	
	
}
