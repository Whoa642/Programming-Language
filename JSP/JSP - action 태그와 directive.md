<h1>include</h1>
<ol>
  <li>action 태그 include &lt;<b>jsp:include page="~"</b>&gt;</li>
    <ul>
      <li type="disc">HTML 태그</li>
      <li type="disc">명시된 페이지를 해당 페이지에 추가한다.</li>
      <li type="disc">해당 JSP 페이지를 Java 파일로 컴파일 한 후에 파일을 추가한다.(즉 JSP 페이지를 서블릿 파일로 컴파일 처리 후 파일을 추가한다.)</li>
    </ul>
  <li>지시어(directive) include &lt;<b>%@ include ~ %</b>&gt;</li>
    <ul>
      <li type="disc">JSP 지시어</li>
      <li type="disc">공통적으로 사용해야 하는 페이지를 추가할 때 사용한다.</li>
      <li type="disc">해당 JSP 페이지가 컴파일 되기 전에 소스코드를 include한 후 컴파일한다.</li>
    </ul>
</ol>

<b>JSPF(Java Servlet Page Fragment)</b>:JSP 변수를 저장할 수 있는 파일
```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ include file="myColor.jspf"%>   <!-- 지시어(directive) include --> 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body bgcolor="<%=myCol2%>">
   <h1>WebContent/jsp2/main.jsp</h1>
   <h2>웹 페이지 템플릿</h2>
  
   <table border="1" width="600" height="600">
    <tr>
     <td colspan="2" height="100"> 
       <jsp:include page="top.jsp"> <!-- action 태그 include -->
         <jsp:param value="Green12" name="ID"/>
       </jsp:include>
     </td>
    </tr>
    <tr>
     <td width="100"> 
       <jsp:include page="left.jsp"></jsp:include>
     </td>
     <td>Center</td>
    </tr>
    <tr>
     <td colspan="2" height="100"> 
       <jsp:include page="bottom.jsp"></jsp:include>
     </td>
    </tr>
   </table>
 
   <h1>LEFT.jsp</h1>
 
   <h1>BOTTOM.jsp</h1>
 
   <h1>TOP.jsp(include)</h1>
   <h2>페이지 메뉴/로그인 창</h2>
   <%=request.getParameter("ID")%>
  
</body>
</html>
```

```jspf
<%
 // myColor.jspf
 String col1 = "red";
 String col2 = "yellow";
 String col3 = "green";
 String col4 = "blue";
%>
```
