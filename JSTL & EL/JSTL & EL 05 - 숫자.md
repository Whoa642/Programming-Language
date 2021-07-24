```jsp
<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!--FORMATTING 라이브러리 추가-->
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>   
<!--CORE 라이브러리 추가--> 
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/fmt/setNumber.jsp</h1>
    <c:set var="today" value="<%=new Date() %>"/>
       기본값: ${today } <br>
    
    <h2>대한민국</h2>
    <fmt:setLocale value="ko_kr"/>
    날짜: <fmt:formatDate value="${today }" dateStyle="full"/><br>
    단위: <fmt:formatNumber value="10000000000" type="currency" /> 
    
    <h2>미국</h2>
    <fmt:setLocale value="en_us"/>
    날짜: <fmt:formatDate value="${today }" dateStyle="full"/><br>
    단위: <fmt:formatNumber value="10000000000" type="currency" />   
    
    <h2>일본</h2>
    <fmt:setLocale value="ja_jp"/>
    날짜: <fmt:formatDate value="${today }" dateStyle="full"/><br>
    단위: <fmt:formatNumber value="10000000000" type="currency" />   
    
 <hr>
  숫자: 100000<br>
 
  <fmt:formatNumber value="100000000" /><br>
  <fmt:formatNumber value="100000000" groupingUsed="false" /><br>
  <fmt:formatNumber value="100000000" groupingUsed="true" /><br>
    
  <h3>소수점 처리 3.12315464</h3>   
  <fmt:formatNumber value="3.12315464" pattern="#.#" /> <br>
  <fmt:formatNumber value="3.12315464" pattern="#.#####" /> <br>
  
  <h3>소수점 처리 3.1 -> 3.10</h3>
  <fmt:formatNumber value="3.1" pattern="#.##"/><br>  
  <fmt:formatNumber value="3.1" pattern="#.0000"/><br>  
    
  
  <fmt:formatNumber value="0.5" type="percent"/><br>
  <fmt:formatNumber value="${6/8}" type="percent"/><br>
   
  <fmt:formatNumber value="100000000" groupingUsed="true"  type="currency" /><br>  
  <fmt:formatNumber value="100000000" 
                    groupingUsed="true" 
                    type="currency"
                    currencySymbol="@"                    
                     /><br>  
    
</body>
</html>
```
