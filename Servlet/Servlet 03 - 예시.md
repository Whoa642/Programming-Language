<h2>회원의 정보를 저장하는 자바빈 객체</h2>

```java
package com.itwillbs.bean;
 
public class MemberBean {
    
    private String id;
    private String pw;
    private String name;
    private int age;
    
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getPw() {
        return pw;
    }
    public void setPw(String pw) {
        this.pw = pw;
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
    
    // alt shift s + s
    @Override
    public String toString() {
        return "MemberBean [id=" + id + ", pw=" + pw + ", name=" + name + ", age=" + age + "]";
    }
}
```

<h2>서블릿 (forward 방식으로 페이지 이동)</h2>

```java
package com.itwillbs.bean;
 
import java.io.IOException;
import java.util.Vector;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import org.eclipse.jdt.internal.compiler.codegen.VerificationTypeInfo;
 
@WebServlet("/test1.do")
public class ServletTest extends HttpServlet{
 
    @Override
    protected void doGet(HttpServletRequest request,
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("doGet() 호출");
        
        // request 영역에 데이터 저장
        request.setAttribute("name", "컴퓨터");
        
        // reqeust 영역에 객체 데이터 저장
        // MemberBean 객체 생성 -> set2.jsp 출력
        MemberBean mb = new MemberBean();
        mb.setId("admin");
        mb.setPw("1234");
        mb.setName("홍길동");
        mb.setAge(20);
        
        // request 영역에 저장
        request.setAttribute("mb", mb);
        
        MemberBean kim = new MemberBean();
        kim.setId("itwill");
        kim.setPw("1q2w3e");
        kim.setAge(20);
        kim.setName("김학생");
        
        // request 영역에 저장
        request.setAttribute("MemberBean", kim);
        
        // 리스트(가변길이 배열)에  위 2개의 정보를 모두 저장해서 처리
        Vector<MemberBean> v = new Vector<MemberBean>();
        
        v.add(mb);
        v.add(kim);
        
        // request 영역에 저장
        request.setAttribute("memberList", v);
        
        // 페이지 이동 (forward)
        RequestDispatcher dis 
          = request.getRequestDispatcher("/core/set2.jsp");
        dis.forward(request, response);        
    }
}
```

<h2>이동한 페이지에서 전달받은 정보를 출력</h2>

```jsp
<%@ page import="com.itwillbs.bean.MemberBean"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!--CORE 라이브러리 추가-->
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
  <h1>WebContent/core/set2.jsp</h1>
 
  <h2>서블릿을 사용하여 정보 전달</h2>
  
  <h4>아이디: ${requestScope.mb.id }</h4>
  <h4>비밀번호:
   <%
     MemberBean mb = (MemberBean)request.getAttribute("mb");
    %>
    <%=mb.getPw() %>
  </h4>
  <h4>이름: ${mb.name }</h4>
  <c:set var="m" value="${requestScope.mb}"/>
  <h4>나이: ${m.age }</h4>
  
  <hr>
  <!--"itwill/1q2w3e/김학생/20" 학생의 정보를 생성후 (ServletTest)
       set2.jsp 페이지에서 정보 출력
   -->
  <hr>
   이름: ${requestScope.MemberBean.name }<br>
   나이: ${MemberBean.age }<br>
  <c:set var="mb1" value="${requestScope.MemberBean }"/> 
   아이디: ${mb1.id }<br>
   비밀번호: ${mb1.pw }<br>  
   
   <hr> 
   <h3> 서블릿에서 전달되는 리스트 정보를 출력 </h3>
   <!-- 리스트 첫번째 요소만 출력 -->
   
   아이디: ${requestScope.memberList[0].id }<br>  
   비밀번호: ${memberList[0].pw }<br>
   이름: ${memberList[0].name }<br>
   나이: ${memberList[0].age }<br>
 
</body>
</html>
```
