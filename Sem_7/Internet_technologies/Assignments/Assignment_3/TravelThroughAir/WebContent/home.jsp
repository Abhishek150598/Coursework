<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Travel thru Air</title>
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
		<h2>List of special deals</h2><br>
		<table class="table table-striped">
		<tr>
			<th>Departure city</th>
			<th>Arrival city</th>
			<th>Cost</th>	
		</tr>
		<c:forEach items="${sd}" var="deal">
			<tr>
				<td><c:out value="${deal.departureCity}"/></td>
				<td><c:out value="${deal.arrivalCity}"/></td>
				<td><c:out value="₹ ${deal.cost}"/></td>
			</tr>
		</c:forEach>
		</table>
	</div>
	 <%@ include file="static.html" %>
	</div>
	</div>
</body>
</html>