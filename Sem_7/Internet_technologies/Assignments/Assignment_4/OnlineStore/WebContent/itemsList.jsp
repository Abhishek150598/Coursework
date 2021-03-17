<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>
<body>
	<h1>Welcome to items page, <%= session.getAttribute("username") %> !</h1>
	<h3>New Arrivals</h3>
	<table class="table table-striped">
		<tr>
			<th>Item name</th>
			<th>Brand</th>
			<th>Price</th>	
			<th>Details</th>
		</tr>
		<c:forEach items="${newItems}" var="item">
			<tr>
				<td><c:out value="${item.item_name}"/></td>
				<td><c:out value="${item.brand}"/></td>
				<td><c:out value="₹ ${item.price}"/></td>
				<td><a href="itemDetails?item_id=${item.item_id}&category=new">Show details</a></td>
			</tr>
		</c:forEach>
	</table>
	<h3>Discounted Items</h3>
	<table class="table table-striped">
		<tr>
			<th>Item name</th>
			<th>Brand</th>
			<th>Price</th>	
			<th>Details</th>
		</tr>
		<c:forEach items="${discItems}" var="item">
			<tr>
				<td><c:out value="${item.item_name}"/></td>
				<td><c:out value="${item.brand}"/></td>
				<td><c:out value="₹ ${item.price}"/></td>
				<td><a href="itemDetails?item_id=${item.item_id}&category=discount">Show details</a></td>
			</tr>
		</c:forEach>
	</table>
</body>
</html>