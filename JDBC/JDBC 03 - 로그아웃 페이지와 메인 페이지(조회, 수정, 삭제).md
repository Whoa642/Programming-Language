<h1>로그아웃 페이지와 메인 페이지(조회, 수정, 삭제)</h1>
<br>

<h2>로그아웃 페이지</h2>

```jsp
<body>
  <h1>WebContent/member/logout.jsp</h1>
  <%
    session.invalidate();
  %>
  <script type="text/javascript">
    alert('로그아웃');
    location.href="main.jsp";
  </script>
  
</body>
```

<h2>메인 페이지(조회, 수정, 삭제)</h2>

```jsp
<body>
   <h1>WebContent/member/main.jsp</h1>
   
   <h2>메인 페이지</h2>
   <%
     String ID = (String)session.getAttribute("ID");
     
     if(ID == null){
         response.sendRedirect("loginForm.jsp");
     }
   %>
 
   <input type="button" value="로그아웃" onclick="location.href='logout.jsp';"><br>
   
   <hr>
   <a href="info.jsp"> 회원 정보 조회 (select)</a> <br>
   <a href="updateForm.jsp"> 회원 정보 수정(update)</a> <br>
   <a href="deleteForm.jsp"> 회원 정보 삭제(delete)</a> <br>
   
   <!--admin(관리자) 메뉴-->
   <%
 
    if(ID != null && ID.equals("admin")){         
   %>
       <a href="list.jsp">회원 정보 목록(list)</a> <br>
   <%
    }
   %>
</body>
```

<h2>로그인한 회원의 모든 정보를 출력하는 페이지(조회)</h2>

```jsp
<body>
     <h1>WebContent/member/info.jsp</h1>
    <%
        String ID = (String)session.getAttribute("ID");
        
        if(ID == null){
            response.sendRedirect("loginForm.jsp");
        }
 
        final String DRIVER ="com.mysql.jdbc.Driver";
        final String DBURL="jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
        
        Class.forName(DRIVER);
    
        Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
    
        String sql = "select * from itwill_member where id=?";
        PreparedStatement pstmt = con.prepareStatement(sql);
        
        pstmt.setString(1, ID);
        
        ResultSet rs = pstmt.executeQuery();
    
        if(rs.next()){
            out.print("아이디:"+rs.getString("id")+"<br>");
            out.print("비밀번호:"+rs.getString("pass")+"<br>");
            out.print("이름:"+rs.getString("name")+"<br>");
            out.print("나이:"+rs.getInt("age")+"<br>");
            out.print("성별:"+rs.getString("gender")+"<br>");
            out.print("이메일:"+rs.getString("email")+"<br>");
            out.print("회원가입일:"+rs.getTimestamp("reg_date")+"<br>");
            
        }
        
        // 자원 해제: 사용한 객체의 역순으로 해제 
        rs.close();
        pstmt.close();
        con.close();        
        
    %>
   <a href="main.jsp">메인페이지로 이동하기</a>
</body>
```

<h2>로그인한 회원의 정보를 수정하는 페이지(수정)</h2>

```jsp
<body>
    <h1>WebContent/member/updateForm.jsp</h1>
    <h2>회원정보 수정</h2>
    <%
 
        String ID = (String) session.getAttribute("ID");
        
        if (ID == null) {
            response.sendRedirect("loginForm.jsp");
        }
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
 
        Class.forName(DRIVER);
    
        Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
        
        String sql = "select * from itwill_member where id=?";
        PreparedStatement pstmt = con.prepareStatement(sql);
 
        pstmt.setString(1, ID);
 
        ResultSet rs = pstmt.executeQuery();
        
        String name = "";
        int age = 0;
        String gender = "";
        String email = "";
        
        if(rs.next()){
            name = rs.getString("name");
            age = rs.getInt("age");
            gender = rs.getString("gender");
            email = rs.getString("email");
        }
        
        // 성별의 정보가 없을경우 기본값 설정
        if(gender == null){
            gender = "남자";
        }
    %>
 
    <fieldset>
        <form action="updatePro.jsp" method="post">
               아이디:<input type="text" name="id" value="<%=id%>" readonly><br>
            <%-- 아이디:<input type="text" name="id" value="<%=id%>" disabled><br> --%>
            <!-- 
                 readonly:수정 X, 읽기 전용 => input태그 사용가능
                 disabled:사용 X => input태그 사용불가능
             -->
            
             비밀번호: <input type="password" name="pass" placeholder="수정전 비밀번호를 입력하시오."><br>
                 이름: <input type="text" name="name" value="<%=name%>"><br>
                 나이: <input type="text" name="age" value="<%=age%>"><br>
                 성별: <input type="radio" name="gender" value="남자"
                   <%if(gender.equals("남자")){ %>
                           checked
                   <%} %>
                   > 남
                  <input type="radio" name="gender" value="여자" 
                   <%if(gender.equals("여자")){ %>
                           checked
                   <%} %>
                  > 여<br> 
            이메일:<input type="text" name="email" value="<%=email%>"><br>
            <hr>
            <input type="submit" value="수정하기">
        </form>
    </fieldset>
 
    <%
        <h1>WebContent/member/updatePro.jsp</h1>
 
        String ID = (String)session.getAttribute("ID");
 
        if (ID == null) {
            response.sendRedirect("loginForm.jsp");
        }
 
        request.setCharacterEncoding("UTF-8");
 
        String pass = request.getParameter("pass");
        String name = request.getParameter("name");
        int age = Integer.parseInt(request.getParameter("age"));
        String gender = request.getParameter("gender");
        String email = request.getParameter("email");
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
        
        Class.forName(DRIVER);
 
        Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
        
        String sql = "select pass from itwill_member where id=?";
        PreparedStatement pstmt = con.prepareStatement(sql);
        
        pstmt.setString(1, ID);
        
        ResultSet rs = pstmt.executeQuery();
    
        if(rs.next()){
            if(pass.equals(rs.getString("pass"))){
             sql = "update itwill_member set name=?,age=?,gender=?,email=? where id=?";
             pstmt = con.prepareStatement(sql);
             
             pstmt.setString(1, name);
             pstmt.setInt(2, age);
             pstmt.setString(3, gender);
             pstmt.setString(4, email);
             pstmt.setString(5, ID);
             
             pstmt.executeUpdate();
             
             %>
             <script type="text/javascript">
                 alert("회원정보 수정 완료");
                 location.href='main.jsp';
             </script>             
             <%              
            }else{
              %>
              <script type="text/javascript">
                 alert("비밀번호 불일치 - 수정 X");
                 history.back();
              </script>              
              <%
            }            
        }else{
             %>
              <script type="text/javascript">
                 alert("비회원 - 수정 X");
                 history.back();
              </script>              
              <%
        }
    %>
</body>
```

<h2>로그인한 회원을 삭제하는 페이지(삭제)</h2>

```jsp
<body>
    <h1>WebContent/member/deleteForm.jsp</h1>
    <h2>회원 삭제 (탈퇴)</h2>
    <%
        String ID = (String) session.getAttribute("ID");
 
        if(ID == null){
           response.sendRedirect("loginForm.jsp");
        }
    %>
 
    <form action="deletePro.jsp" method="post">
     <input type="hidden" name="ID" value="<%=ID %>">
     비밀번호: <input type="password" name="PW">
      <input type="submit" value="삭제(탈퇴)">
    </form>
 
    <h1>WebContent/member/deletePro.jsp</h1>
    <%
        
        String ID = (String) session.getAttribute("ID");
 
        if(id == null){
            response.sendRedirect("loginForm.jsp");
        }
    
        request.setCharacterEncoding("UTF-8");
 
        ID = request.getParameter("ID");
        String PW = request.getParameter("PW");
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
        
        Class.forName(DRIVER);
 
        Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
        
        String sql = "select pass from itwill_member where id=?";
        PreparedStatement pstmt = con.prepareStatement(sql);
        
        pstmt.setString(1, ID);
        
        ResultSet rs = pstmt.executeQuery();
    
        if(rs.next()){
            if(pass.equals(rs.getString("pass"))){ 
                sql = "delete from itwill_member where id=?";
                pstmt = con.prepareStatement(sql);
                pstmt.setString(1, ID);
 
                pstmt.executeUpdate();
                System.out.println("회원 삭제 완료");
                
                session.invalidate();
                
                %>
                  <script type="text/javascript">
                     alert("회원 삭제(탈퇴) 성공");
                     location.href='main.jsp';
                  </script>              
                 <%
                
            }else{
                %>
                  <script type="text/javascript">
                     alert("비밀번호 불일치 - 삭제 X");
                     history.back();
                  </script>              
                 <%
            }
            
        }else{
            // 비회원
             %>
              <script type="text/javascript">
                 alert("비회원 - 삭제 X");
                 history.back();
              </script>              
              <%
        }            
    %>
 
</body>
```

<h2>관리자 계정으로 모든 회원의 정보를 출력하는 페이지</h2>

```jsp
<body>
 
    <h1>WebContent/member/list.jsp</h1>
   
       <h2>회원 전체 목록 확인</h2>
   <%
    String ID = (String)session.getAttribute("ID");
     
    if(ID == null || !ID.equals("admin")){
        response.sendRedirect("loginForm.jsp");
    }
    
       final String DRIVER = "com.mysql.jdbc.Driver";
    final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
    final String DBID = "root";
    final String DBPW = "1234";    
    
    Class.forName(DRIVER);
 
    Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
 
    String sql = "select * from itwill_member where id != ?";
    PreparedStatement pstmt = con.prepareStatement(sql);
    pstmt.setString(1, ID); 
 
    ResultSet rs = pstmt.executeQuery();
   %>
     <table border="1">
      <tr>
        <td>아이디</td>
        <td>비밀번호</td>
        <td>이름</td>
        <td>나이</td>
        <td>성별</td>
        <td>이메일</td>
        <td>가입일자</td>
      </tr>
      
      <%
       while(rs.next()){
      %>
          <tr>
            <td><%=rs.getString("id")%></td>
            <td><%=rs.getString("pass")%></td>
            <td><%=rs.getString("name")%></td>
            <td><%=rs.getInt("age")%></td>
            <td><%=rs.getString("gender")%></td>
            <td><%=rs.getString("email")%></td>
            <td><%=rs.getTimestamp("reg_date")%></td>
          </tr>
      <%} %>
     </table> 
</body>
```
