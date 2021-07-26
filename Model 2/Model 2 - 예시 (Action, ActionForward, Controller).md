<h3>페이지 이동 정보를 저장하는 ActionForward 객체(이동할 페이지 주소, 이동할 방식)</h3>

```java
package com.itwillbs.member.action;
 
public class ActionForward {
    // 페이지 이동정보를 저장하는 객체
    // 이동할 페이지 주소, 이동할 방식
    
    private String path;
    private boolean isRedirect;
    // 임의로 설정
    // 1) redirect 방식 - true
    // 2) forward 방식 - false    
    
    
    //alt shift s + r
    public String getPath() {
        return path;
    }
    public void setPath(String path) {
        this.path = path;
    }
    public boolean isRedirect() {
        return isRedirect;
    }
    public void setRedirect(boolean isRedirect) {
        this.isRedirect = isRedirect;
    }
}
```

<h3>처리 동작의 Action 인터페이스</h3>

```java
package com.itwillbs.member.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
public interface Action {
 
    public ActionForward execute(HttpServletRequest request,
            HttpServletResponse response) throws Exception;
    
    // => 처리 동작이 필요한 객체의 경우 해당 인터페이스를 상속해서
    // 반드시 execute()메서드를 구현(오버라이딩)하도록 하는 설계
    // => 강제적으로 구현하게 만들어서 다형성을 구현
    
    // public abstract ActionForward execute();
    // ActionForward execute(); 
}
```

<h3>Servlet으로 Controller 구현</h3>

```java
package com.itwillbs.member.action;
 
import java.io.IOException;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
public class MemberFrontController extends HttpServlet {
 
    // doProcess()
    protected void doProcess(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        System.out.println("\n\n\n C: MemberFrontController_doProcess() 호출");
 
        // --------------------1. 가상주소 계산-------------------------
        // System.out.println("C: URI-"+request.getRequestURI());
        // System.out.println("C: URL-"+request.getRequestURL());
 
        // URI 정보
        String requestURI = request.getRequestURI();
        System.out.println("C requestURI: "+requestURI);
        // Context 정보(프로젝트 이름)
        String ctxPath = request.getContextPath();
        System.out.println("C ctxPath: "+ctxPath);
        // URI - CTX => command
        String command = requestURI.substring(ctxPath.length());
        
        System.out.println("C command: "+command);
        System.out.println("C: 1. 가상주소 계산 완료! \n\n");        
        // --------------------1. 가상주소 계산-------------------------
 
 
        // --------------------2. 가상주소 매핑-------------------------
        Action action = null;
        ActionForward forward = null;
        
        // 회원가입
        if(command.equals("/MemberJoin.me")){
            System.out.println("C: /MemberJoin.me 호출");
            System.out.println("C: insertForm.jsp (view 페이지로 이동)");
            
            // 페이지 이동 객체 생성 후 정보만 저장
            forward = new ActionForward();
            forward.setPath("./member/insertForm.jsp");
            forward.setRedirect(false);
 
        // 회원가입 처리
        }else if(command.equals("/MemberJoinAction.me")){
            System.out.println("C: /MemberJoinAction.me 호출");
            System.out.println("C: 회원정보를 DB에 저장 처리");
            
            // DB 동작을 대신 처리하는 객체 (model)
            // MemberJoinAction() 객체 생성
            // MemberJoinAction mja = new MemberJoinAction();
            action = new MemberJoinAction();
            try {
                 forward = action.execute(request, response);
            } catch (Exception e) {
                e.printStackTrace();
            }
 
        // 로그인
        }else if(command.equals("/MemberLogin.me")){
            System.out.println("C: /MemberLogin.me 호출");
            System.out.println("C: loginForm.jsp (view 페이지로 이동)");
            
            forward = new ActionForward();
            forward.setPath("./member/loginForm.jsp");
            forward.setRedirect(false);
 
        // 로그인 처리
        }else if(command.equals("/MemberLoginAction.me")){
            System.out.println("C: /MemberLoginAction.me 호출");
            System.out.println("C: DB에 이동해서 로그인 체크 (model 이동)");
            
            // MemberLoginAction() 객체 생성
            action = new MemberLoginAction();
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        // 메인
        }else if(command.equals("/Main.me")){
            System.out.println("C: /Main.me 호출");
            System.out.println("C: main.jsp (view 페이지로 이동)");
            
            forward = new  ActionForward();
            forward.setPath("./member/main.jsp");
            forward.setRedirect(false);
        // 로그아웃
        }else if(command.equals("/MemberLogout.me")){
            System.out.println("C: /MemberLogout.me 호출");
            System.out.println("C: 로그아웃 처리 동작 (model)");
            
            // MemberLogoutAction() 객체 생성
            action = new MemberLogoutAction();
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        // 회원정보 출력
        }else if(command.equals("/MemberInfo.me")){
            System.out.println("C: /MemberInfo.me 호출");
            System.out.println("C: DB 정보를 가져와서 view 페이지 출력");            
            
            // MemberInfo() 객체 생성
            action = new MemberInfoAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }   
        // 회원정보 수정         
        }else if(command.equals("/MemberUpdate.me")){
            System.out.println("C: /MemberUpdate.me 호출");
            System.out.println("C: DB 정보를 가져와서 view 페이지 출력");
            
            // MemberUpdate() 객체 생성
            action = new MemberUpdateAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        // 회원정보 수정 처리
        }else if(command.equals("/MemberUpdateProAction.me")){
            System.out.println("C: /MemberUpdateProAction.me 호출");
            System.out.println("C: 전달 정보를 저장 -> DB에서 수정");
            
            // MemberUpdateProAction() 객체 생성
            action = new MemberUpdateProAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        }
 
        System.out.println("C: 2. 가상주소 매핑 완료");
        // --------------------2. 가상주소 매핑-------------------------
 
 
        // --------------------3. 페이지 이동---------------------------
        if(forward != null){
            //페이지 이동정보
 
            if(forward.isRedirect()){ // redirect
                System.out.println("C: "+forward.getPath()+" 경로 이동(sendRedirect)");
                response.sendRedirect(forward.getPath());
            }else{ // forward
                System.out.println("C: "+forward.getPath()+" 경로 이동(forward)");
                RequestDispatcher dis =
                        request.getRequestDispatcher(forward.getPath());
                dis.forward(request, response);        
            }
            System.out.println("C: 3. 페이지 이동 완료");
        }    
        // --------------------3. 페이지 이동---------------------------
    }
    // doProcess()
 
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        System.out.println("C: MemberFrontController_doGet() 호출");
        doProcess(request, response);
    }
 
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        System.out.println("C: MemberFrontController_doPost() 호출");
        doProcess(request, response);
    }
}
```

<h3>Context 정보</h3>

```xml
<?xml version="1.0" encoding="UTF-8"?>
 
<Context>
    <Resource 
        name="jdbc/model2"
        auth="Container"
        type="javax.sql.DataSource"
        driverClassName="com.mysql.jdbc.Driver"
        url="jdbc:mysql://localhost:3306/model2"
        username="root"
        password="1234"
        maxActive="500"
    />
</Context>
```


<h3>web.xml 서블릿 매핑</h3>

```xml 
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://java.sun.com/xml/ns/javaee" xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_3_0.xsd" id="WebApp_ID" version="3.0">
  <display-name>Model2JSP</display-name>
  <welcome-file-list>
    <welcome-file>index.html</welcome-file>
    <welcome-file>index.htm</welcome-file>
    <welcome-file>index.jsp</welcome-file>
    <welcome-file>default.html</welcome-file>
    <welcome-file>default.htm</welcome-file>
    <welcome-file>default.jsp</welcome-file>
  </welcome-file-list>

  <servlet>
    <servlet-name>MemberFrontController</servlet-name>
    <servlet-class>com.itwillbs.member.action.MemberFrontController</servlet-class>
  </servlet>

  <servlet-mapping>
    <servlet-name>MemberFrontController</servlet-name>
    <url-pattern>*.me</url-pattern>
  </servlet-mapping>
</web-app>
```
