<h3>회원 정보를 저장하는 MemberDTO 객체</h3>

```java
package com.itwillbs.member.db;
 
import java.sql.Timestamp;
 
public class MemberDTO {
    // model2 - itwill_member 테이블 참고
    
    private String id;
    private String pass;
    private String name;
    private int age;
    private String gender;
    private String email;
    private Timestamp reg_date; 
    // => lombok 라이브러리
    
    // getter/setter
    // alt shift s + r
    public String getId() {
        return id;
    }
    
    public void setId(String id) {
        this.id = id;
    }
    
    public String getPass() {
        return pass;
    }
    
    public void setPass(String pass) {
        this.pass = pass;
    }
    
    public String getName() {
        return name;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String getGender() {
        return gender;
    }
    
    public void setGender(String gender) {
        this.gender = gender;
    }
    
    public String getEmail() {
        return email;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
 
    public Timestamp getReg_date() {
        return reg_date;
    }
 
    public void setReg_date(Timestamp reg_date) {
        this.reg_date = reg_date;
    }
 
    @Override
    public String toString() {
        return "MemberDTO [id=" + id + ", pass=" + pass + ", name=" + name + ", age=" + age + ", gender=" + gender
                + ", email=" + email + ", reg_date=" + reg_date + "]";
    }
}
```

<h3>DB의 회원 정보를 처리하는 MemberDAO 객체</h3>

```java
package com.itwillbs.member.db;
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;
 
public class MemberDAO {
    
 
    // 공통의 멤버 변수 (전역 변수, 인스턴스 변수)
    Connection conn = null;
    PreparedStatement pstmt = null;
    String sql = "";
    ResultSet rs = null;
    
 
    // 공통의 멤버 메서드
    // DB 연결 (Connection pool)
    private Connection getConn() throws Exception{
        // 프로젝트 정보를 초기화
        Context init = new InitialContext();
        init.lookup("java:comp/env/jdbc/model2");
        
        // 프로젝트에 있는 DB 연결 정보(이름) 가져오기
        DataSource ds = (DataSource)init.lookup("java:comp/env/jdbc/model2");
        
        // DB 연결
        return ds.getConnection();    
    }
    
    
    // 자원 해제
    public void closeDB(){
        try{
            if(rs != null)
                rs.close();
            if(pstmt != null)
                pstmt.close();
            if(conn != null)
                conn.close();
        }catch(SQLException e){
            e.printStackTrace();
        }
    }    
    // 자원 해제
    
    
    // 회원 추가
    public void insertMember(MemberDTO mDTO){
        
        try{
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체 생성
            sql = "insert into itwill_member (id,pass,name,age,gender,email,reg_date) "
                    + "values(?,?,?,?,?,?,?)";
            pstmt = conn.prepareStatement(sql);
            
            // 3-1. ? 처리
            pstmt.setString(1,mDTO.getId());
            pstmt.setString(2,mDTO.getPass());
            pstmt.setString(3,mDTO.getName());
            pstmt.setInt(4,mDTO.getAge());
            pstmt.setString(5,mDTO.getGender());
            pstmt.setString(6,mDTO.getEmail());
            pstmt.setTimestamp(7,mDTO.getReg_date());
            
            // 4. SQL 실행
            pstmt.executeUpdate();
            
            System.out.println("mDAO: 회원가입 성공");
        
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            closeDB();
        }
    }
    // 회원 추가
    
    
    // 로그인 체크
    public int loginCheck(String id,String pass){
        int flag = -1;
        
        try{
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            sql = "select pass from itwill_member where id=?";
            pstmt = conn.prepareStatement(sql);
            
            // 3-1. ?
            pstmt.setString(1, id);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
            
            // 5. 데이터 처리
            if(rs.next()){ // SQL 결과 O
                // 회원
                if(pass.equals(rs.getString("pass"))){
                    // 본인
                    System.out.println("mDAO: 로그인 성공");
                    flag = 1;
                }else{ 
                    // 비밀번호 오류 
                    System.out.println("mDAO: 비밀번호 오류");
                    flag = 0;
                }
            }else{ // SQL 결과 X
                // 비회원
                System.out.println("mDAO: 비회원");
                flag = -1;
            }
            
            System.out.println("mDAO: 로그인 체크 성공 "+flag);
            
        }catch(Exception e){
            e.printStackTrace();
        }
        
        return flag;
    }
    // 로그인 체크    
}
```

<h3>실행 가능한 유일한 JSP 페이지 index.jsp</h3>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <!--  WebContent/index.jsp  -->
    <%
      // model2 프로젝트의 시작페이지
      // *실행 가능한 유일한 jsp 페이지
      
      // 회원가입 페이지 호출
      // http://localhost:8088/Model2JSP/MemberJoin.me
      //response.sendRedirect("./MemberJoin.me");
        response.sendRedirect("./MemberLogin.me");
    %>
</body>
</html>
```
