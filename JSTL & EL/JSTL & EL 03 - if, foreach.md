```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>    
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
   <h1>WebContent/core/if.jsp</h1>
   
   <c:set var="i" value="test" />
   
   <c:if test="${i == 'test' }">
       <h2>동일한 값</h2>
   </c:if>
   
   <%
     if(true){
        %>
         <h2>동일한 값</h2>
        <% 
     }   
   %>
   
   <hr>
   <!--변수 2개를 사용해서 더 큰 값을 출력하는 코드-->
   
   <c:set value="-10" var="num1"></c:set>
   <c:set value="200" var="num2"></c:set>
   
   <c:if test="${num1 > num2}">
        <h2>${num1 }가 더 크다</h2>
   </c:if>
   
   <c:if test="${num1 < num2}">
        <h2>${num2 }가 더 크다</h2>
   </c:if>
   
   <c:if test="${num1 lt num2}">
        <h2>${num2 }가 더 크다</h2>
   </c:if>
   
   <h2>switch-case문과 유사한 구문</h2>
   <!--num1 값이 50 보다 큰지 100 보다 큰지 판단/그외 범위-->
   <c:choose>
     <c:when test="${num1 > 50}">
        <h3>50 보다 큰 값</h3>
     </c:when>
     <c:when test="${num1 > 100 }">
        <h3>100 보다 큰 값</h3>
     </c:when>     
     <c:otherwise>
        <h3> 그 외 나머지 데이터</h3>
        <c:if test="${num1 < 0 }">
          <h3>음수</h3>
        </c:if>
     </c:otherwise>  
   </c:choose>
</body>
</html>
```

```jsp
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
  <h1>WebContent/core/foreach.jsp</h1>
  <%
   for(int i = 0; i < 5; i++){
  %>
      <h2>Hello~</h2>
  <%
   }
  %>
  <hr>
   JSTL - foreach 구문<br>
   
  <c:forEach begin="1" end="5" step="1">
     <h2>itwill !</h2>
  </c:forEach>
  
  <hr>
  1 ~ 10 까지 수 중에서 홀수만 출력(foreach)<br>
  <!-- forEach 문에서 반복에 사용되는 값은 var 변수를 사용해서 저장가능
       값을 사용할때는 EL 표현식을 사용 해야한다. (HTML)
    -->
  <c:forEach  begin="1" end="10" step="2" var="i">
      ${i }<br>
  </c:forEach>
  
  <%
    ArrayList arr = new ArrayList();
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    
    for(int i = 0; i < arr.size(); i++){
        out.println(arr.get(i)+"<br>");
    }
  %>
  <hr>
  <%
    //자바 foreach
    for(Object a:arr){
        System.out.println(a);
    }
  
    // 영역 객체에 저장
    pageContext.setAttribute("arr", arr);    
  %>
  <hr><hr>
   EL 표현식  ${arr }
  <hr>
  <c:forEach var="a" items="${arr }" >
       ${a}<br>
  </c:forEach>
  
  <hr><hr>
  
  <c:set var="arr2" value="a,b,c,d,e,f" scope="page" />
  
  <c:forTokens var="test" items="${arr2}" delims=",">
        ${test}<br>
  </c:forTokens>
  
  <!-- 
     ["Itwill Busan 교육 센터 5 강의장 홍 길 동"]
     => 문자열 파싱 (공백)후 출력
   -->
   <c:set value="Itwill Busan 교육 센터 5 강의장 홍 길 동" var="str"></c:set>
  
  <c:forTokens items="${str }" delims=" " var="s">
     ${s }<br>
  </c:forTokens>
  
</body>
</html>

```
