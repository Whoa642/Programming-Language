<h2>JSP와 MySQL 연결</h2>
  
1.필요한 드라이버를 설치(API/라이브러리) (e.g. webcontent/WEB-INF/lib/mysql-connector-java-5.1.49.jar)

2.설치된 드라이버를 로딩

3.드라이버를 사용해서 DB를 연결

```jsp
<body>
    <h1>WebContent/jsp5/DBConnect.jsp</h1>
    <%
        Class.forName("com.mysql.jdbc.Driver");
        
        System.out.println("드라이버 로딩 성공");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jspdb", "root", "1234");
        
        System.out.println("DB 연결 성공");
        System.out.println("연결 정보:"+conn);    
    %>
</body>
```
<b>Statement 객체는 사용이 복잡하기 때문에 PreparedStatement 객체를 주로 사용한다.</b> 
<br>
<br>

<h2>사용자가 입력한 정보를 DB에 저장</h2>


```jsp
<body>
  <h1>WebContent/jsp5/insertForm.jsp</h1>
   
   <form action="insertPro.jsp" method="post">
      아이디:<input type="text" name="ID"><br>
      비밀번호:<input type="password" name="PW"><br>
      이메일:<input type="text" name="email"><br>
        <input type="submit" value="정보 전달">   
   </form>
   
   <h1>WebContent/jsp5/insertPro.jsp</h1>
   <%
    // 한글 데이터 처리 
    request.setCharacterEncoding("UTF-8");
    
     String ID = request.getParameter("ID");
     String PW = request.getParameter("PW");
     String EM = request.getParameter("EM");
   %>
 
   아이디:<%=ID%><br>
   비밀번호:<%=PW%><br>
   이메일:<%=EM%><br>
   
  <h2>JSP - MySQL 연결 (JDBC 사용) </h2>
  <%
  
   final String DRIVER= "com.mysql.jdbc.Driver";
   final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
   final String DBID = "root";
   final String DBPW = "1234";
  
   // 0) 라이브러리 설치
 
   // 1) 드라이버 로딩
   Class.forName(DRIVER);
   System.out.println("드라이버 로딩 성공");
 
   // 2) DB 연결(드라이버)   
   Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
   System.out.println("DB 연결 성공");
   System.out.println("연결 정보:"+conn);
   
   // 3. SQL 쿼리 작성 & pstmt 실행객체
   //String sql = "insert into itwill_member(id,pass,email) values('"+id+"','"+pass+"','"+email+"')";
   String sql = "insert into itwill_member(id,pass,email) values(?,?,?)";
   
   // Statement 객체:jdbc사용해서 SQL구문을 작성하고, 실행하도록 도와주는 객체 
   // Statement stmt = con.createStatement();
   // PreparedStatement 객체:Statement 객체와 같이 jdbc사용해서 SQL구문을 작성하고, 실행하도록 도와주는 객체
   PreparedStatement pstmt = con.prepareStatement(sql);
   
   // ? 값 넣기
   // DB 테이블에 있는 컬럼의 자료형에 따라서 메서드가 변경
   // pstmt.setXXXXX(? 위치, ? 입력값);
   pstmt.setString(1,ID);       
   pstmt.setString(2,PW);
   pstmt.setString(3,EM);
   
   // 4. sql 구문 실행
   // stmt.executeUpdate(sql);
   pstmt.executeUpdate(); // insert, update, delete 구문실행시 사용
   // pstmt.executeQuery(); // select 구문 실행시 사용
   System.out.println("insert 구문 실행 완료");
  %>
 
</body>
```

<h2>DB에 저장된 정보 업데이트</h2>

```jsp
<body>
  <h1>WebContent/jsp5/updateForm.jsp</h1>
 
      <form action="updatePro.jsp" method="post">
         아이디: <input type="text" name="ID"><br> 
         수정할 비밀번호: <input type="password" name="PW"> <br>
        <input type="submit" value="수정">
      </form>
  
    <h1>WebContent/jsp5/updatePro.jsp</h1>
   <%
        String ID = request.getParameter("ID");
        String PW = request.getParameter("PW"); 
 
        final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";
    
        Class.forName(DRIVER);
        System.out.println("드라이버 로딩 성공");
    
        Connection conn = DriverManager.getConnection(DBURL,DBID,DBPW);
        System.out.println("DB 연결 성공");
    
        String sql = "update itwill_member set pass=? where id=?";
        PreparedStatement pstmt = conn.prepareStatement(sql);
    
        pstmt.setString(1,PW);
        pstmt.setString(2,ID);
        
        pstmt.executeUpdate();
        System.out.println("정보 수정 완료");
   %>
 
</body>
```

<h2>select로 DB에서 일치하는 정보 출력</h2>

```jsp
<body>
 <h1>WebContent/jsp5/select.jsp</h1>
  <%
    // DB 회원 정보에서 회원의 정보를 출력 (개인 1명 정보 조회)
    String ID = "itwill";
    String PW = "12345";
    
    final String DRIVER="com.mysql.jdbc.Driver";
    final String DBURL ="jdbc:mysql://localhost:3306/jspdb";
    final String DBID ="root";
    final String DBPW ="1234";
    
    Class.forName(DRIVER);
    System.out.println("드라이버 로딩 성공");
    
    Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);
    System.out.println("DB 연결 성공");
    
    String sql = "select * from itwill_member where id=? and pass=?";
    PreparedStatement pstmt = con.prepareStatement(sql);
    
    pstmt.setString(1, ID);
    pstmt.setString(2, PW);
    
    ResultSet rs = pstmt.executeQuery();
    
    // 커서=>   BOF (Beginning Of File)  
    //         -----------------------
    //          DB 데이터(select문 결과)
    //         -----------------------
    //          EOF (End Of File)
    
    // select 문의 결과를 '레코드셋'이라고 부르고 해당 데이터는 java.sql.ResultSet 타입으로 사용할 수 있다. 
    
    if(rs.next()){
        // 커서를 다음으로 이동시킬때, 데이터가 있으면 true, 없으면(EOF) false
        out.println("아이디: "+rs.getString("id")+"<br>");
        out.println("비밀번호: "+rs.getString("pass")+"<br>");
        out.println("이메일: "+rs.getString("email")+"<br>");
        
        // rs.getXXXX("컬럼명"):select의 결과 중에서 "컬럼명"에 해당하는 값을 가져오며 XXXX 는 DB 데이터의 자료형에 따라서 변경할 수 있다. 
        // rs.getXXXX(컬럼 첨자):selec의 결과 중에서 첨자에 해당하는 값을 가져온다.
        // 첨자를 사용하는 방법이 이름을 사용하는 방법보다 처리 속도가 더 빠르다.
        // ★ 배열과 달리 컬럼의 첨자는 1번부터 시작한다. (왼쪽->오른쪽)
        out.println("아이디: "+rs.getString(1)+"<br>");
        out.println("비밀번호: "+rs.getString(2)+"<br>");
        out.println("이메일: "+rs.getString(6)+"<br>");
    }
    
    System.out.println("회원정보 조회 성공(select)");
    
    // select 구문을 사용해서 DB에 있는 모든 회원정보를 출력
    while(rs.next()){
        out.println("아이디: "+rs.getString("id")+"<br>");
        out.println("비밀번호: "+rs.getString("pass")+"<br>");
        out.println("이메일: "+rs.getString("email")+"<br>");
    }
  %>
  
</body>
```

<h2>DB에 저장된 정보 삭제</h2>

```jsp
<body>
   <h1>WebContent/jsp5/deleteForm.jsp</h1>
    
    <form action="deletePro.jsp" method="post">
         삭제할 아이디: <input type="text" name="ID"><br>
         삭제할 비밀번호: <input type="text" name="PW"><br>
    <input type="submit" value="삭제">
    </form>
    
    <%
   
     request.setCharacterEncoding("UTF-8");
     String delID = request.getParameter("ID");
     String delPW = request.getParameter("PW");
     
     final String DRIVER = "com.mysql.jdbc.Driver";
     final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
     final String DBID = "root";
     final String DBPW = "1234";
     
     Class.forName(DRIVER);
     System.out.println("드라이버 로딩 성공");
 
     Connection con = DriverManager.getConnection(DBURL, DBID, DBPW);
     System.out.println("DB 연결 성공");
     
     // select구문을 사용해서 삭제하려는 사람의 정보가 맞는지 확인 후 삭제
     String sql ="select pass from itwill_member where id=?";
     PreparedStatement pstmt = con.prepareStatement(sql);
     
     pstmt.setString(1,ID);
     
     ResultSet rs = pstmt.executeQuery();
     
     if(rs.next()){
         if(PW.equals(rs.getString("pass"))){
            sql = "delete from itwill_member where id=?";
            pstmt = coNN.prepareStatement(sql);
            pstmt.setString(1,ID);
            
              // sql 구문이 영향을 준 row 수를 반환
            // -> '0'일 : sql구문에 영향 X/실행 오류/DDL 구문
               int result = pstmt.executeUpdate();
            System.out.println("회원 탈퇴 성공:"+result);                     
                     
         }else{
            System.out.println("아이디 또는 비밀번호가 일치하지 않습니다.");
         }         
         
     }else{
         //비회원이다.
         System.out.println("비회원 입니다.");
     }
    %>
   
</body>
```
