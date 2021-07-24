```jsp
<%@page import="java.util.Date"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!--CORE 라이브러리 추가-->
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!--FORMATTING 라이브러리 추가-->
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
     <h1>WebContent/fmt/setDate.jsp</h1>
     <c:set value="<%=new Date() %>" var="today"></c:set>
     
     ${today }<hr>
     
     <h2>기본 날짜 데이터</h2>
     <fmt:formatDate value="${today }"/><br>
 
     <h2>기본 시간 데이터</h2>
     <fmt:formatDate value="${today }" type="time"/><br>
     <fmt:formatDate value="${today }" type="both" /><br>
 
     <h2>날짜 데이터</h2>
     <fmt:formatDate value="${today }"/><br>
     <fmt:formatDate value="${today }" dateStyle="full"/><br>
     <fmt:formatDate value="${today }" dateStyle="long"/><br>
     <fmt:formatDate value="${today }" dateStyle="medium"/><br>
     <fmt:formatDate value="${today }" dateStyle="short"/><br>
     
     <h2>시간 데이터</h2>
     
     <fmt:formatDate value="${today }" type="time" timeStyle="full" /><br>
     <fmt:formatDate value="${today }" type="time" timeStyle="long" /><br>
     <fmt:formatDate value="${today }" type="time" timeStyle="medium" /><br>
     <fmt:formatDate value="${today }" type="time" timeStyle="short" /><br>
 
     <h3>
        0000년 00월 00일 (0) 오전 00시 00분 00초
     </h3>
 
     <fmt:formatDate value="${today }" dateStyle="long" type="both" timeStyle="long"/>
 
     <h3>
        날짜 정보: 0000/00/00 (0) 
     </h3>
   
     <fmt:formatDate value="${today }" pattern="yyyy/MM/dd(E)" />
 
     <h3>
        시간 정보: (오전) 00:00:00
     </h3>
 
     <fmt:formatDate value="${today }" type="time" pattern="(a)hh:mm:ss" />
 
</body>
</html>
```
