<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h1>Item details</h1>
	<h3><c:out value="${item.item_name}"/></h3>
	<p><c:out value="${item.brand}"/></p>
	<p><c:out value="₹ ${item.price}"/></p>
	<p><c:out value="Discount ${item.discount}%"/></p>
	<p><c:out value="Ratings: ${item.ratings} stars"/></p>
	<a href="itemsList">Back to list</a>
</body>
</html>