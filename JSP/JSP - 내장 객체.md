<h2>javax.servlet 패키지에 있는 8개의 내장 객체</h2>
<ul>
  <li>request: http 요청 정보를 저장하는 객체</li>
  <li>response: http 응답 정보를 저장하는 객체</li>
  <li>session: 클라이언트 세션 정보를 저장하는 객체</li>
  <li>page: 해당 페이지의 정보를 저장하는 객체(서블릿 객체)</li>
  <li>pageContext: 페이지에 필요한 실행 정보를 저장하는 객체(프로젝트 안에 있는 페이지)</li>
  <li>out: 응답 페이지를 출력하는 객체</li>
  <li>application: 애플리케이션의 컨텍스트(프로젝트) 정보를 저장하는 객체</li>
  <li>config: 페이지에 필요한 서블릿 정보를 저장하는 객체(초기화 정보)</li>
</ul>

<h2>java.lang 패키지에 있는 1개의 내장 객체</h2>
<ul><li>exception: 예외 처리 객체</li></ul>

<hr>

```jsp
<body>
  <h2>request 객체</h2>
  서버 도메인명: <%=request.getServerName()%><br>
  서버 포트번호: <%=request.getServerPort()%><br>
  URL: <%=request.getRequestURL()%><br> 
  URI: <%=request.getRequestURI()%><br> 
  프로토콜: <%=request.getProtocol()%><br>
  클라이언트 호스트명: <%=request.getRemoteHost()%><br>
  클라이언트 IP주소: <%=request.getRemoteAddr()%><br>
  
  페이지 요청 방식(전송방식): <%=request.getMethod()%><br>
  컨텍스트 정보(프로젝트 정보): <%=request.getContextPath()%><br>
  // 하드 디스크에 저장된 위치
  물리적 경로: <%=request.getRealPath("/")%><br>
  
  // 사용자가 사용하는 웹 페이지의 정보
  http 헤더 정보(user-agent): <%=request.getHeader("user-agent")%><br>
  http 헤더 정보(accept-language): <%=request.getHeader("accept-language")%><br>
  http 헤더 정보(host): <%=request.getHeader("host")%><br>
  http 헤더 정보(connection): <%=request.getHeader("connection")%><br>
  
  <hr>
  <h2>response 객체</h2>
  <%
     response: 서버 -> 클라이언트 응답 정보 저장
     response.addHeader("Refresh", "3;url=/StudyJSP/jsp1/test2.jsp");
     response.setHeader("헤더 속성", 값)
     response.addCookie("쿠키값");
     response.setContentType("속성");
     response.sendRedirect("페이지");  
  %>
  
  <h2>session 객체</h2>
  session ID값: <%=session.getId() %><br>
  세션 생성 시간: <%=session.getCreationTime()%><br>
  최종 접속 시간: <%=session.getLastAccessedTime()%><br>
  세션 유지 시간(1800초, 30분): <%=session.getMaxInactiveInterval()%><br> // 기본값은 1800초, 즉 30분  
 <%
   // 세션 유지 시간 60분으로 변경
   session.setMaxInactiveInterval(3600); 
 %>
  세션 유지시간(3600초, 60분): <%=session.getMaxInactiveInterval() %><br>
 
  <h2>application 객체</h2>
  서버 정보: <%=application.getServerInfo()%><br>
  서버의 물리 경로: <%=application.getRealPath("/")%><br> 
  
  버퍼 사이즈: <%=out.getBufferSize()%><br>
  사용후 남은 버퍼 사이즈: <%=out.getRemaining()%><br> 
  
</body>
```
