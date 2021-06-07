<h1>DB와 연동된 회원가입, 로그인 페이지</h1>

<h2>회원가입 페이지</h2>

```jsp
<body>
  <h1>WebContent/member/insertForm.jsp</h1>
   <h2>회원가입 페이지</h2>
 
    <fieldset>
      <form action="insertPro.jsp" method="post">
        아이디: <input type="text" name="ID"><br>
           비밀번호: <input type="password" name="PW"><br>
        이름: <input type="text" name="name"><br>
           나이: <input type="text" name="age"><br>
        성별: 
              <input type="radio" name="gender" value="남자"> 남 
              <input type="radio" name="gender" value="여자"> 여 <br>
        이메일: <input type="text" name="email"><br>
        <hr>
        <input type="submit" value="회원가입">        
      </form>    
    </fieldset>
   
  <h1>WebContent/member/insertPro.jsp</h1>
    <%
        request.setCharacterEncoding("UTF-8");
        String ID = request.getParameter("ID");
        String PW = request.getParameter("PW");
        String name = request.getParameter("name");
        int age = Integer.parseInt(request.getParameter("age"));
        String gender = request.getParameter("gender");
        String email = request.getParameter("email");
 
        // 날짜 정보생성 -> 현 시스템의 시간정보를 저장
        Timestamp reg_date = new Timestamp(System.currentTimeMillis());
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
 
        Class.forName(DRIVER);
        System.out.println("드라이버 로딩 성공");
        
        
        Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
        System.out.println("DB 연결 성공!");
        
        String sql = "insert into itwill_member values(?,?,?,?,?,?,?)";
        PreparedStatement pstmt = con.prepareStatement(sql);
        
        pstmt.setString(1, ID);
        pstmt.setString(2, PW);
        pstmt.setString(3, name);
        pstmt.setInt(4, age);
        pstmt.setString(5, gender);
        pstmt.setString(6, email);
        pstmt.setTimestamp(7, reg_date);
        
        pstmt.executeUpdate();
        System.out.println("회원가입 성공");
 
        // 로그인 페이지로 이동(loginForm.jsp)
    %>
    
    <script type="text/javascript">
       alert(" 회원가입 성공. 로그인 페이지로 이동");
       location.href="loginForm.jsp";    
    </script>
</body>
```

<h2>로그인 페이지</h2>

```jsp
<body>
   <h1>WebContent/member/loginForm.jsp</h1>
   
    <h2>로그인 페이지</h2>
     <form action="loginPro.jsp" method="post" >
           아이디: <input type="text" name="ID"><br>
           비밀번호: <input type="password" name="PW"><br>
       <input type="submit" value="로그인">    
     </form>
 
     <input type="button" value="회원가입" onclick="location.href='insertForm.jsp';">
    
 
  <h1>WebContent/member/loginPro.jsp</h1>
    <%
        request.setCharacterEncoding("UTF-8");
        String ID = request.getParameter("ID");
        String PW = request.getParameter("PW");
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
 
        Class.forName(DRIVER);
        System.out.println("드라이버 로딩 성공");
 
        Connection con = DriverManager.getConnection(DBURL, DBID, DBPW);
        System.out.println("DB 연결 성공");
        
        String sql ="select pass from itwill_member where id = ?";
        PreparedStatement pstmt = con.prepareStatement(sql);
        
        pstmt.setString(1, ID);
        
        ResultSet rs = pstmt.executeQuery();
        
        if(rs.next()){
            if(pass.equals(rs.getString("pass"))){
                session.setAttribute("id", ID);
                response.sendRedirect("main.jsp");
            }else{
                %>
                 <script type="text/javascript">
                    alert("비밀번호 불일치");
                    history.back();
                 </script>
                <%    
            }
            
        }else{
            %>
             <script type="text/javascript">
                var result = confirm("비회원입니다. 회원가입 하시겠습니까?");
                
                if(result){
                    location.href="insertForm.jsp";
                }else{
                    history.back();
                }
                
             </script>
            <%
        }
    %>
</body>
```
