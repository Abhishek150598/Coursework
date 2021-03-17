<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
   

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
		<br><br>
		<div class="error">
		<h4><%= request.getAttribute("error").toString() %></h4><br>
		</div>
	</div>
	 <%@ include file="static.html" %>
	</div>
	</div>
</body>
</html>