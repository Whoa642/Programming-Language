<h3>회원정보를 보여주는 JSP 페이지 (info.jsp)</h3>

```jsp
<%@page import="java.sql.Timestamp"%>
<%@page import="com.itwillbs.member.db.MemberDTO"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.sql.DriverManager"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/member/info.jsp</h1>
    <h2>회원정보 출력</h2>
    <%
        // 로그인 한 회원의 모든 정보를 출력 페이지 
 
        // 로그인 세션 제어
        String id = (String)session.getAttribute("id");
        
        if(id == null){
            response.sendRedirect("./MemberLogin.me");
        }    
        
        // request 영역에 저장된 정보를 화면에 출력
        MemberDTO mDTO = (MemberDTO)request.getAttribute("mDTO");
    %>
    
    <h2>JSP 표현식</h2>
    <h3>아이디:<%=mDTO.getId() %></h3>        
    <h3>비밀번호:<%=mDTO.getPass() %></h3>                        
    <h3>이름:<%=mDTO.getName() %></h3>            
    <h3>나이:<%=mDTO.getAge() %></h3>        
    <h3>성별:<%=mDTO.getGender() %></h3>        
    <h3>이메일:<%=mDTO.getEmail() %></h3>        
    <h3>회원가입일:<%=mDTO.getReg_date() %></h3>        
    
    <hr>
    
    <h2>EL 표현식</h2>
    <h3>아이디:${mDTO.id }</h3>
    <h3>비밀번호:${mDTO.pass }</h3>
    <h3>이름:${mDTO.name }</h3>
    <h3>나이:${mDTO.age }</h3>
    <h3>성별:${mDTO.gender }</h3>
    <h3>이메일:${mDTO.email }</h3>
    <h3>회원가입일:${mDTO.reg_date }</h3>
                                            
   <a href="./MemberLogin.me"> 메인페이지로 이동하기 ...  </a>
</body>
</html>
```

<h3>회원정보를 출력을 처리하는 MemberInfoAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.io.PrintWriter;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberInfoAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
         
        System.out.println("M: MemberInfoAction_execute() 호출");
        
        // 세션 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;
        }
        
        // DAO 객체 - getMember(id);
        MemberDAO mDAO = new MemberDAO();
        // id에 해당하는 회원정보 반환
        MemberDTO mDTO = mDAO.getMember(id);
 
        System.out.println("M: "+mDTO);
        
        // request 영역에 전달 정보를 저장
        request.setAttribute("mDTO", mDTO);
        
        // 페이지 이동 (./member/info.jsp)
        forward.setPath("./member/info.jsp");
        forward.setRedirect(false);
        return forward;
    }
}
```

<h3>회원정보를 수정하는 JSP 페이지 (updateForm.jsp)</h3>

```jsp
<%@page import="com.itwillbs.member.db.MemberDTO"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.Connection"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
 
    <h1>WebContent/member/updateForm.jsp</h1>
    <h2>회원정보 수정</h2>
    <%
        // 세션 제어
        String id = (String) session.getAttribute("id");
        if (id == null) {
            response.sendRedirect("./MemberLogin.me");
        }
        
        // 회원정보 (request 영역)
        // request.setAttribute("mDTO",mDTO);
        MemberDTO mDTO = (MemberDTO)request.getAttribute("mDTO");
        
        // 성별 정보가 없으면 기본값 하나를 설정
        if(mDTO.getGender() == null){
            mDTO.setGender("남자");
        }
        
    %>
 
    <fieldset>
        <form action="./MemberUpdateProAction.me" method="post">
               아이디: <input type="text" name="id" value="<%=mDTO.getId()%>" readonly><br>
             비밀번호: <input    type="password" name="pass" 
                       placeholder="수정전 비밀번호를 입력하시오."
             ><br>
                 이름: <input type="text" name="name" value="<%=mDTO.getPass()%>"><br>
                 나이: <input type="text" name="age" value="<%=mDTO.getAge()%>"><br>
                 성별: <input type="radio" name="gender"    value="남자"
                   <%if(mDTO.getGender().equals("남자")){ %>
                           checked
                   <%} %>
                   > 남
                  <input type="radio" name="gender" value="여자" 
                   <%if(mDTO.getGender().equals("여자")){ %>
                           checked
                   <%} %>
                  > 여 <br> 
            이메일: <input type="text" name="email" value="<%=mDTO.getEmail()%>"><br>
            <hr>
            <input type="submit" value="수정하기">
        </form>
    </fieldset>
 
</body>
</html>
```

<h3>수정 전 회원정보를 반환하는 MemberUpdateAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberUpdateAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: MemberUpdateAction_execute() 호출");
 
        // 세션 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;
        }
                
        // DAO 객체 - getMember(id);
        MemberDAO mDAO = new MemberDAO();
        // id에 해당하는 회원정보 반환
        MemberDTO mDTO = mDAO.getMember(id);
 
        System.out.println("M: "+mDTO);
                
        // request 영역에 전달 정보를 저장
        request.setAttribute("mDTO", mDTO);
                
        // 페이지 이동 (./member/updateForm.jsp)
        forward.setPath("./member/updateForm.jsp");
        forward.setRedirect(false);
        return forward;        
    }
}
```

<h3>회원정보 수정을 처리하는 MemberUpdateProAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.io.PrintWriter;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberUpdateProAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request,
            HttpServletResponse response) throws Exception {
 
        System.out.println(" M : MemberUpdateProAction_execute() 호출");
        
        // 세션 제어
        HttpSession session = request.getSession();
        String id = (String)request.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;
        }
    
 
        // 한글 처리 (post 방식)
        request.setCharacterEncoding("UTF-8");
 
        // 전달받은 정보 저장 (submit 정보)
        // DTO 객체 생성 후 저장
        MemberDTO mDTO = new MemberDTO();
        mDTO.setAge(Integer.parseInt(request.getParameter("age")));
        mDTO.setEmail(request.getParameter("email"));
        mDTO.setGender(request.getParameter("gender"));
        mDTO.setId(request.getParameter(id));
        mDTO.setName(request.getParameter("name"));
        mDTO.setPass(request.getParameter("pass"));
        
        // DAO 객체 생성 - updateMember();        
        MemberDAO mDAO = new MemberDAO();
        int flag = mDAO.updateMember(mDTO);
    
        
        // flag 값 -1,0,1 -> JS 페이지 이동
        
        response.setContentType("text/html; charset=UTF-8");
        PrintWriter out = response.getWriter();
        
        if(flag == 0){
            out.println("<script>");
            out.println("alert('비밀번호 불일치: 수정 X');");
            out.println("history.back();");
            out.println("</script>");
            out.close();
            return null;
            
        }
        
        if(flag == -1){
            out.println("<script>");
            out.println("alert('비회원: 수정 X')");
            out.println("history.back();");
            out.println("</script>");
            out.close();
            return null;
            
        }
        
        out.println("<script>");
        out.println("alert('회원정보 수정 완료')");
        out.println("location.href='./Main.me';");
        out.println("</script>");
        out.close();
        return null;
    }
}
```

<h3>회원탈퇴 비밀번호를 받는 JSP 페이지 (deleteForm.jsp)</h3>

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
 
    <h1>WebContent/member/deleteForm.jsp</h1>
    <h2>회원탈퇴 (Model2)</h2>
 
    <%
        String id = (String) session.getAttribute("id");
        if (id == null) {
           response.sendRedirect("./MemberLogin.me");
        }
    %>
 
    <form action="./MemberDeleteAction.me" method="post">
        <input type="hidden" name="id" value="<%=id %>" >
         비밀번호: <input type="password" name="pass">
          <input type="submit" value="탈퇴하기">
    </form>
 
</body>
</html>
```

<h3>회원탈퇴를 처리하는 MemberDeleteAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.io.PrintWriter;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberDeleteAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
 
        System.out.println("M : MemberDeleteAction_execute() 호출");
        
        // 세션 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;
        }
        
        // 전달된 정보 저장 (id,pass)
        id = request.getParameter("id");
        String pass = request.getParameter("pass");
        
        // DAO 객체 생성 -> deleteMember(id,pass);
        // update 동작과 동일하게 처리 (-1,0,1)
        MemberDAO mDAO = new MemberDAO();
        int flag = mDAO.deleteMember(id, pass);
        
        response.setContentType("text/html; charset=UTF-8");
        PrintWriter out = response.getWriter();
        
        if(flag == 0){
            out.println("<script>");
            out.println("alert('비밀번호 불일치 - 탈퇴 X');");
            out.println("history.back();");
            out.println("</script>");
            out.close();
            return null;
        }
    
        if(flag == -1){
            out.println("<script>");
            out.println("alert('비회원 - 탈퇴 X')");
            out.println("history.back();");
            out.println("</script>");
            out.close();
            return null;
        }        
        
        // 세션 초기화 후 페이지 이동
        session.invalidate();
        out.println("<script>");
        out.println("alert('회원탈퇴 완료')");
        out.println("location.href='./Main.me';");
        out.println("</script>");
        out.close();
        return null;
    }
}
```

<h3>DB에 저장된 모든 회원을 출력하는 JSP 페이지 (list.jsp)</h3>

```jsp
<%@page import="com.itwillbs.member.db.MemberDTO"%>
<%@page import="java.util.List"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@page import="java.sql.DriverManager"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
   <h1>WebContent/member/list.jsp</h1>
   <h2>회원 전체 목록 확인</h2>
   <%
    // 세션 제어 
    String id = (String) session.getAttribute("id");
    if(id == null || !id.equals("admin")){
        response.sendRedirect("./MemberLogin.me");
    }
    
    List<MemberDTO> memberList = (List)request.getAttribute("memberList");
 
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
        
        <%for(int i = 0; i < memberList.size(); i++){
            MemberDTO mDTO = memberList.get(i);
        %>
           <tr>
            <td>아이디:<%=mDTO.getId() %></td>
            <td>비밀번호:<%=mDTO.getPass() %></td>
            <td>이름:<%=mDTO.getName() %></td>
            <td>나이:<%=mDTO.getAge() %></td>
            <td>성별:<%=mDTO.getGender() %></td>
            <td>이메일:<%=mDTO.getEmail() %></td>
            <td>가입일자:<%=mDTO.getReg_date() %></td>
        </tr>      
        <%} %>
    </table> 
    
    <hr><hr>
    <h2>EL 표현식</h2>
    
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
      
        <c:forEach var="member" items="${requestScope.memberList }">
               <tr>
                <td>아이디:${member.id }</td>
                <td>비밀번호:${member.pass }</td>
                <td>이름:${member.name }</td>
                <td>나이:${member.age }</td>
                <td>성별:${member.gender }</td>
                <td>이메일:${member.email }</td>
                <td>가입일자:${member.reg_date }</td>
            </tr>      
           </c:forEach>
 
    </table>     
    
    <h3><a href="./Main.me">메인페이지로...</a></h3>
      
</body>
</html>
```

<h3>DB에 저장된 모든 회원을 반환하는 MemberListAction 객체</h3>

```java
package com.itwillbs.member.action;
 
import java.util.ArrayList;
import java.util.List;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class MemberListAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: MemberListAction_execute() 호출");
        
        // 세션 제어 (로그인, 관리자)
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null || !id.equals("admin")){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;
        }
        
        // DAO 객체 생성 - 회원정보 목록을 가져오는 메서드 (관리자 제외)
        // getMemberList();
        MemberDAO mDAO = new MemberDAO();
        List<MemberDTO> memberList = mDAO.getMemberList();
        
        // 회원목록 저장 (request 영역) 
        request.setAttribute("memberList", mDAO.getMemberList());
        // request.setAttribute("memberList", memberList);
        
        // 페이지 이동 (JSP)
        forward.setPath("./member/list.jsp");
        forward.setRedirect(false);
        return forward;
    }
}
```
