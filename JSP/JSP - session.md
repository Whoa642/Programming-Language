<b>세션(session)</b>이란 서버와 클라이언트의 연결 상태를 유지하기 위해서 웹 서버의 컨테이너 상태를 유지하기 위한 정보를 저장하는 객체이다.
<b>(서버와 클라이언트의 연결 상태는 페이지 요청 후 바로 끊어진다.)</b>
<ul>
  <li>웹 브라우저 당 1개의 세션이 생성되며 서버의 상태가 유지되기 때문에 안정적이고 보안에 우수하다.</li>
  <li>응답 시 세션 객체가 쿠키 영역에 저장된다.</li>
</ul>

<h2>세션 생성, 삭제, 사용, 초기화</h2>

```jsp
<%
 세션 생성
 session.setAttribute("이름", "값");
 
 세션 삭제
 session.removeAttribute("이름");
 
 세션 사용
 session.getAttribute("이름");
 
 세션 초기화
 session.invalidate();
%>
```

<h2>이름과 전화번호를 속성 값으로 가지는 세션을 생성, 삭제, 사용, 초기화</h2>

```jsp
<body>
 
  <h1>WebContent/jsp3/sessionTest.jsp</h1>
  <%
 
   //세션 속성값 가져오기, getAttribute() 메서드는 Object 타입을 반환하기 때문에 명시적 형변환이 필요하다.
   String name = (String)session.getAttribute("name");
   String tel =(String)session.getAttribute("tel");
   
   // 만약에 세션 속성값이 없을 경우
  if(name == null){
      name="세션값 X";
  }
  if(tel == null){
      tel = "세션값 X";
  }
  %>
 
  <h2>세션값: <%=name%></h2>
  <h2>세션값: <%=tel%></h2>
 
  <input type="button" value="세션 생성" onclick="location.href='sessionSet.jsp';"><br>
  <input type="button" value="세션 삭제" onclick="location.href='sessionDel.jsp';"><br>
  <input type="button" value="세션 초기화" onclick="location.href='sessionInval.jsp';"><br>  
 
  <h1>WebContent/jsp3/sessionSet.jsp</h1>
  <%
     // 세션 생성
     session.setAttribute("name", "ITWILL");
     session.setAttribute("tel", "010-1234-5678");
     
     // 페이지 이동(sessionTest.jsp)
   %>
 
   <script type="text/javascript">
      alert("세션 생성 완료 후 페이지 이동");
      location.href = 'sessionTest.jsp';
   </script>
    
 
   <h1>WebContent/jsp3/sessionDel.jsp</h1>
   <%
     // 세션 삭제 
     session.removeAttribute("name");
   %>
 
   <script type="text/javascript">
      alert("세션 삭제 후 페이지 이동");
      location.href = 'sessionTest.jsp';   
   </script>
 
   <h1>WebContent/jsp3/sessionInval.jsp</h1>  
   <%
     // 세션을 초기화
     session.invalidate();
   %>
   
   <script type="text/javascript">
      alert("세션 초기화 후 페이지 이동");
      location.href = "sessionTest.jsp";  
   </script>
     
 
</body>
```

<h2>입력 받은 사용자의 아이디와 비밀번호를 가지고 로그인 성공 여부를 판별</h2>

```jsp
<body>
 
    <h1>WebContent/jsp3/sessionLogin.jsp</h1>
     <form action="sessionLoginPro.jsp" method="post">
        아이디: <input type="text" name="ID"><br>
        비밀번호: <input type="password" name="PW"><br>
        <input type="submit" value="로그인">
    </form>    
    
 
    <h1>WebContent/jsp3/sessionLoginPro.jsp</h1>
    <%
        String uID = "admin";
        String uPW = "123";
 
        String ID = request.getAttribute("ID");
        String PW = request.getAttribute("PW");
 
        if(uID.equals(ID)){
          if(uPW.equals(PW)){
             out.println("잠시만 기다려주세요.");
             session.setAttribute("ID", ID);
             response.sendRedirect("sessionMain.jsp");
          }else{
            out.println("비밀번호가 일치하지 않습니다.");
          }
        }else{
            out.println("회원이 아닙니다.");
        }
    %>
 
 
   <h1>WebContent/jsp3/sessionLoginMain.jsp</h1>
   <%
       String ID = (String)session.getAttribute("ID");
       
       if(ID == null){
            response.sendRedirect("sessionLogin.jsp");
       }
   %>
 
   <%=ID%> 님 로그인 성공
   <input type="button" value="로그아웃" onclick="location.href='sessionLogout.jsp';">   
   
 
   <h1>WebContent/jsp3/sessionLogout.jsp</h1>
   <%
       session.invalidate();
   %>
 
  <script type="text/javascript">
     alert("로그아웃 성공");
     location.href = "sessionMain.jsp";
  </script>
 
</body>
```
