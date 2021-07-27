<h3>회원가입 형식 JSP 페이지</h3>

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
   <h1>WebContent/member/insertForm.jsp</h1>
   <h2>회원가입 페이지 (Model2)</h2>
    
    <fieldset>
      <form action="./MemberJoinAction.me" method="post">
        아이디: <input type="text" name="id"><br>
        비밀번호: <input type="password" name="pass"><br>
        이름: <input type="text" name="name"><br>
        나이: <input type="text" name="age"><br>
        성별: <input type="radio" name="gender" value="남자">남 
              <input type="radio" name="gender" value="여자">여<br>
        이메일: <input type="text" name="email"><br>
        <hr>
        <input type="submit" value="회원가입">        
      </form>    
    </fieldset>
</body>
</html>
```

<h3>회원가입 처리하는 MemberJoinAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.sql.Timestamp;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberJoinAction implements Action {
    //회원가입 처리 객체 
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        // 회원가입 처리 후 페이지 이동 정보를 생성
        System.out.println("M: MemberJoinAction_execute() 호출");
        
        // 한글 처리
        request.setCharacterEncoding("UTF-8");
            
        // 전달된 매개변수 저장 -> 자바빈 객체 생성
        // MemberDTO 
        MemberDTO mDTO = new MemberDTO();
        mDTO.setAge(Integer.parseInt(request.getParameter("age")));
        mDTO.setEmail(request.getParameter("email"));
        mDTO.setId(request.getParameter("id"));
        mDTO.setGender(request.getParameter("gender"));
        mDTO.setName(request.getParameter("name"));
        mDTO.setPass(request.getParameter("pass"));
        mDTO.setReg_date(new Timestamp(System.currentTimeMillis()));
        
        System.out.println("M: "+mDTO);
        
        // 전달된 정보를 DB에 저장
        // MemberDAO 객체 - 메서드 insertMember
        MemberDAO mDAO = new MemberDAO();
        mDAO.insertMember(mDTO);
        
        System.out.println("M: DB 처리 완료");
        
        // 페이지 이동 => 페이지 이동 정보를 생성해서 컨트롤러로 전달
        ActionForward forward = new ActionForward();
        forward.setPath("./MemberLogin.me");
        forward.setRedirect(true);
 
        return forward;
    }
}
```

<h3>로그인 형식 JSP 페이지</h3>

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
   <h1>WebContent/member/loginForm.jsp</h1>
   
   <h2>로그인 페이지 (Model2)</h2>
   <!-- 
      사용자의 ID,PASS 정보를 입력받아서 회원여부 판단 로그인 처리
      회원가입 버튼
    -->
    <form action="./MemberLoginAction.me" method="post" >
          아이디: <input type="text" name="id"><br>
          비밀번호: <input type="password" name="pass"><br>
      <input type="submit" value="로그인">    
    </form>
      <input type="button" value="회원가입"
          onclick="location.href='./MemberJoin.me';"> 
</body>
</html>
```

<h3>로그인 처리하는 MemberLoginAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.io.PrintWriter;
import java.util.Enumeration;
 
import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpSessionContext;
 
import com.itwillbs.member.db.MemberDAO;
 
public class MemberLoginAction implements Action{
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        System.out.println("M: MemberLoginAction_execute() 호출");
        
        // 전달된 정보를 저장 (id,pass)
        String id = request.getParameter("id");
        String pass = request.getParameter("pass");
        
        // mDAO 객체 생성 - loginCheck(id,pass)
        // 결과 반환: -1, 0, 1
        MemberDAO mDAO = new MemberDAO();
        int flag = mDAO.loginCheck(id, pass);
        
        System.out.println("M: 로그인 확인 완료 "+flag);
        
        // 로그인 처리 결과에 따라서 페이지 이동 (JS)
        
        // 0 - 비밀번호 오류
        if(flag == 0){
            response.setContentType("text/html; charset=UTF-8");
            PrintWriter out = response.getWriter();
            out.print("<html>");
            out.print("<head>");
            out.print("<script>");
            out.print("alert('비밀번호 오류');");
            out.print("history.back();");
            out.print("</script>");
            out.print("</head>");
            out.print("<body>");
            out.print("</body>");
            out.print("</html>");
            
            out.close();
            return null;
        }
        // -1
        if(flag == -1){
            response.setContentType("text/html; charset=UTF-8");
            PrintWriter out = response.getWriter();
            out.print("<html>");
            out.print("<head>");
            out.print("<script>");
            out.print("alert('비회원');");
            out.print("history.back();");
            out.print("</script>");
            out.print("</html>");
            
            out.close();
            return null;
        }
 
        // 1
        // 아이디 정보를 session 영역에 저장
        HttpSession session = request.getSession();
        session.setAttribute("id", id);
            
        // 로그인 성공 -> Main.me 페이지로 이동
        ActionForward forward = new ActionForward();
        forward.setPath("./Main.me");
        forward.setRedirect(true);
        
        return forward;
    } 
}
```

<h3>로그아웃 처리하는 MemberLogoutAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
public class MemberLogoutAction implements Action{
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: MemberLogoutAction_execute() 호출");
        
        // 세션 초기화
        HttpSession session = request.getSession();
        session.invalidate();
        
        // 페이지 이동 (JS)
        response.setContentType("text/html; charset=UTF-8");
        PrintWriter out = response.getWriter();
        out.println("<script>");
        out.println("alert('로그아웃')");
        out.println("location.href='./Main.me';");
        out.println("</script>");
        
        return null;
    }
}
```

<h3>로그인한 회원의 JSP 메인 페이지 (main.jsp)</h3>

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
   <h1>WebContent/member/main.jsp</h1>
   <h2>메인 페이지 (Model2)</h2>
 
   <%
     // 세션 영역에 있는 정보를 저장
     String id = (String) session.getAttribute("id");
     // 정보가 없으면 로그인 페이지로 이동   
     if(id == null){
         response.sendRedirect("./MemberLogin.me");
     }
   %>
 
   <%=id %>님 환영합니다
   <input type="button" value="로그아웃" 
          onclick="location.href='./MemberLogout.me';"><br>
   <hr>
 
   <a href="./MemberInfo.me">회원 정보 조회(select)</a><br>
   <a href="./MemberUpdate.me">회원 정보 수정(update)</a><br>
   <a href="./MemberDelete.me">회원 정보 삭제(delete)</a><br>
 
   <!--admin(관리자) 메뉴-->
   <%        
    if(id != null && id.equals("admin")){         
   %>
       <a href="./MemberListAction.me"> 회원 정보 목록(list)</a><br>
   <%
    }
   %>
</body>
</html>
```
