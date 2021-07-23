<b>JSTL</b>이란 자카르타 회사에서 개발된 자주 사용되는 기능을 모아놓은 <b>커스텀 태그</b>이다. 

<b>CORE</b> 라이브러리는 기본적 기능을 제공하는 라이브러리로 변수 선언, 조건문, 페이지 이동 기능을 가지고 있다.

<b>Formatting</b> 라이브러리는 다국어 처리, 날짜와 숫자 데이터를 형식화하는 기능을 가지고 있다.

<b>EL</b>(Expression Laguage) 표현식은 JSP 표현식(<b><%= %></b>)을 대신해서 출력하는 표현(<b>${ }</b>)으로 JSP 표현식에 비해서 기본적인 코드의 복잡성이 감소한다. 

${변수명}
${객체명.변수명}
${객체명['변수명']}
${객체명["변수명"]}
${연산식}

<h3>EL 내장객체</h3>
<ul>
  <li>pageScope/requestScope/sessionScope/applicationScope: JSP 영역(내장 객체)를  사용하는 객체</li>
  <li>param/paramValues: 매개변수/배열을 가져올 때 사용</li>
  <li>header/headerValues: 페이지 header의 정보 값/배열을 가져올 때 사용</li>
  <li>cookie</li>
  <li>pageContext: JSP PageContext 객체를 사용</li>
  <li>initParam</li>
</ul>

영역 객체의 범위는 page < request < session < application이며 <b>EL 표현식에서 영역 객체의 접근 부분을 생략할 수 있다</b>. (e.g. ${pageScope.test}  => ${test})
   
<b><i>영역 객체의 정보가 없을 경우 영역의 범위가 좁은 곳에서 넓은 곳으로 가면서 순차적으로 해당 대상을 검색, 이때 동일한 속성 명이 있을 경우 먼저 만난 속성을 사용한다.</i></b>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!-- 
    JSTL의 CORE 라이브러리를 사용하기위해서 속성을 추가
    ☆반드시 JSTL을 사용할때 선언
 -->
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/core/out.jsp</h1>
    <%--<i:out value="i: 출력"></i:out>--%>
    
    <!--화면에 데이터 출력하기-->
    1. HTML 코드 사용<br>
    <%
       out.print("2. out.print() 사용<br>");    
    %>
    3. <%="JSP 표현식 사용" %><br>
    4. JSTL 사용<br>
    <c:out value="JSTL!!"></c:out>
    <%--<c:out value=""/>--%>
    <%--<jsp:include page=""></jsp:include>--%>
    
    <hr>
    <h2>JSTL + EL표현식</h2>
    <c:out value="${'Hello~' }"/>
    <c:out value="100*200"/>
    <c:out value="${100*200 }"/><br>
    <%=100*200 %><br>
 
    JSTL 안에 EL 표현식은 null 값을 공백으로 처리     
    <c:out value="${member.id }"/> <br>
    <c:out value="${member.id }" default="null값 입니다.@@"/><br>
    <%--<%=member.id %>--%>
    
    <hr><hr>
    
    <abc>는 abc입니다. <br>
    
    &lt;abc>는 abc입니다. <br>
    
    <c:out value="<abc>는 abc입니다."/> <br>
    
</body>
</html>
```
