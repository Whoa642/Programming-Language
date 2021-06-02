<h2>영역 객체</h2>

<b>영역(scope)</b>:내장 객체 중에서 데이터를 서로 공유할 수 있는 영역 객체의 공유 범위<br>
<b>속성(attribute)</b>:영역 객체가 공유하는 데이터(값)
		
영역&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;		영역 객체&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	속성의 유효 범위<br>
page	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;	pageContext    &nbsp;&nbsp;해당 페이지<br>
request&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    request	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;        페이지 요청이 처리되는 페이지(주소창)<br>
session	  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    session	    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    세션이 유지되는 동안 모든 페이지(브라우저 당 1개 생성)<br>
application   &nbsp;   application      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;서버가 실행되는 동안 모든 페이지<br>


<h2>속성 정보를 생성하고 사용하는 메서드</h2>

생성 메서드:<b>[영역 객체].setAttribute("이름", 값);</b>
<br>
  사용 메서드:<b>[영역 객체].getAttribute("이름");</b>

<hr>


<h2>데이터를 가지고 페이지를 이동하는 방법</h2>
<b><i>JavaScript, JSP, action 태그 방식은 서로 같이 사용할 수 없다.</i></b>

```jsp
<body>
  
  <h1>WebContent/jsp2/scopeForm.jsp</h1>
  
  <form action="scopePro.jsp" method="get">
       아이디: <input type="text" name="id">
       <input type="submit" value="입력">
  </form>   
 
   
  <h1>WebContent/jsp2/scopePro.jsp</h1>
  <h2>영역 객체 정보 생성</h2>
  <%
   // 영역 객체를 생성(데이터-속성을 생성)
   pageContext.setAttribute("pc", "페이지 영역 정보 저장");
   request.setAttribute("rq", "request 영역 정보 저장");
   session.setAttribute("se", "session 영역 정보 저장");
   application.setAttribute("ap", "application 영역 정보 저장");
  %>
 
  <%
    String ID = request.getParameter("id");
  %>
    아이디: <%=ID%><br>
  
  <h2>영역 객체 정보 출력</h2>
  pageContext 객체 정보 (pc 속성값을 출력): <%=pageContext.getAttribute("pc")%><br>
  request 객체 정보: <%=request.getAttribute("rq")%><br>
  session 객체 정보: <%=session.getAttribute("se")%><br>
  application 객체 정보: <%=application.getAttribute("ap")%><br>
  
  <h2>데이터를 가지고 페이지 이동하는 4가지 방법</h2>
  
  <h3>1) a 태그를 사용해서 이동 (매개변수, session, application 정보 사용 가능)</h3>
   // get 방식으로 매개변수의 값 저장, 전달 가능하며 표현식을 사용
   <a href="scopeProAction.jsp?id=<%=ID%>&pw=1234"> scopeProAction.jsp 페이지 이동</a>
  
  <h3>2) JavaScript를 사용해서 이동 (매개변수, session, application 정보 사용 가능)</h3>
   
   <script type="text/javascript">
      // get 방식으로 매개변수의 값 저장, 전달 가능하며 표현식을 사용
      alert("자바스크립트 사용 페이지 이동");
      location.href = 'scopeProAction.jsp?id=<%=ID%>&pw=1234'; 
   </script>  
  
  <h3>3) JSP를 사용해서 이동 (매개변수, session, application 정보 사용 가능)</h3>
  <%
    // get 방식으로 매개변수의 값 저장, 전달 가능. 이미 자바 코드라서 표현식 필요 없다.
    response.sendRedirect("scopeProAction.jsp?id="+ID+"&pw=1234");  
  %>
  
  <h3>4) action 태그를 사용해서 이동 (매개변수, request, session, application 정보 사용 가능)</h3>
  <!-- 
     HTML 태그지만 JSP 동작을 가능하게 하는 특수한 기능을 가지고 있다.
     ☆forward 방식 이동(포워딩): 페이지 이동시 request, response 객체 정보를 저장하고 이동한다.
     페이지 이동 시 주소를 변경하지 않으며 화면만 변경한다.☆ 
             
     scopePro.jsp -> scopeProAction.jsp    
     주소:scopePro.jsp  
     화면:scopeProAction.jsp 
   -->
  <jsp:forward page='scopeProAction.jsp'>
       <jsp:param value="0000" name="pw"/>
  </jsp:forward>
 
  <h1>WebContent/jsp2/scopeProAction.jsp</h1>
   
    <h2>매개변수 정보</h2>
        아이디: <%=request.getParameter("id")%><br>
         비밀번호: <%=request.getParameter("pw")%><br>
    <h2>영역 객체 정보</h2>
      pageContext 객체 정보 (pc 속성값을 출력): <%=pageContext.getAttribute("pc")%><br>
      request 객체 정보: <%=request.getAttribute("rq")%><br>
      session 객체 정보: <%=session.getAttribute("se")%><br>
      application 객체 정보: <%=application.getAttribute("ap")%><br>
   
</body>
```
