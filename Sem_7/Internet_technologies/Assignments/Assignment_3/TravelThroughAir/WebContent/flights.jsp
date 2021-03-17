<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Flights</title>
<link rel="stylesheet" href="styles.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script> 
</head>
<body>
	<div class="homepage">
	<div class="header">
		<h1>Travel thru Air</h1>
	</div>
	<div class="contents">
	<div class="deals">
		<h2>Available flights</h2><br>
		<table class="table table-striped">
		<tr>
			<th>Departure city</th>
			<th>Arrival city</th>
			<th>Cost</th>
			<th>Departure time</th>
			<th>Arrival time</th>
			<th>Number of legs</th>	
		</tr>
		<c:forEach items="${flights}" var="flight">
			<tr>
				<td><c:out value="${flight.departureCity}"/></td>
				<td><c:out value="${flight.arrivalCity}"/></td>
				<td><c:out value="₹ ${flight.cost}"/></td>
				<td><c:out value="${flight.departureTime}"/></td>
				<td><c:out value="${flight.arrivalTime}"/></td>
				<td><c:out value="${flight.numberOfLegs}"/></td>
			</tr>
		</c:forEach>
		</table>
	</div>
	<%@ include file="static.html" %>
	</div>
	</div>
</body>
</html>