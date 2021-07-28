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

<h3>Model과 Veiw를 연결하는 AdminGoodsFrontController 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import java.io.IOException;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
public class AdminGoodsFrontController extends HttpServlet {
 
    protected void doProcess(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("AdminGoodsFrontController_doProcess()");
        
        // --------------------1. 가상주소 계산-------------------------
        System.out.println();
        System.out.println("C: 가상주소 계산 시작");
        
        String requestURI = request.getRequestURI();
        System.out.println("C: requestURI = "+requestURI);
        
        String ctxPath = request.getContextPath();
        System.out.println("C: ctxPath = "+ctxPath);
        
        String command = requestURI.substring(ctxPath.length());
        System.out.println("C: command = "+command);
        
        System.out.println("C: 가상주소 계산 끝");
        // --------------------1. 가상주소 계산-------------------------
        
        
        // --------------------2. 가상주소 매핑-------------------------
        Action action = null;
        ActionForward forward = null;
        
        System.out.println();
        System.out.println("C: 가상주소 매핑 시작");
        
        if(command.equals("/GoodsAdd.ag")){
            //http://localhost:8088/Model2JSP/GoodsAdd.ag
            System.out.println("C: /GoodsAdd.ag 호출");
            System.out.println("C: 관리자의 상품 정보를 전달받아서 DB에 저장");
        
            // 정보 입력 받는 view 페이지로 이동
            forward = new ActionForward();
            forward.setPath("./admin_goods/admin_goods_add.jsp");
            forward.setRedirect(false);
        }else if(command.equals("/GoodsAddAction.ag")){
            System.out.println("C: /GoodsAddAction.ag 호출");
            System.out.println("C: 전달받은 정보 DB에 저장 (file)");
            
            // GoodsAddAction() 객체 생성
            action = new GoodsAddAction();
            
            try{
                forward = action.execute(request, response);
            }catch (Exception e){
                e.printStackTrace();
            }
        }else if(command.equals("/AdminGoodsList.ag")){
            System.out.println("C: /AdminGoodsList.ag 호출");
            System.out.println("C: DB 정보를 view 페이지에 출력");
            
            // AdminGoodsListAction() 객체
            action = new AdminGoodsListAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        }else if(command.equals("/AdminGoodsModify")){
            System.out.println("C: /AdminGoodsModify.ag 호출");
            System.out.println("C: DB 정보를 view 페이지에 출력");
            
            // AdminGoodsModifyAction() 객체
            //action = new AdminGoodsModifyAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();;
            }
        }
        
        System.out.println("C: 가상주소 매핑 끝");
        // --------------------2. 가상주소 매핑-------------------------
        
        
        
        // --------------------3. 페이지 이동-------------------------
        System.out.println();
        System.out.println("C: 페이지 이동 시작");
        
        if(forward != null){
            if(forward.isRedirect()){
            // true
                System.out.println("C: 방식 = sendRedirect, 주소 = "+forward.getPath());
                response.sendRedirect(forward.getPath());
            }else{
            // false
                System.out.println("C: 방식 = forward, 주소 = "+forward.getPath());
                RequestDispatcher dis = 
                        request.getRequestDispatcher(forward.getPath());
                dis.forward(request, response);
            }
        }
        System.out.println("C: 페이지 이동 끝\n\n\n\n");
        // --------------------3. 페이지 이동-------------------------    
                
    }
    
    @Override
    protected void doGet(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("AdminGoodsFrontController_doGet()");
        doProcess(request,response);
    }
 
    @Override
    protected void doPost(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("AdminGoodsFrontController_doPost()");
        doProcess(request,response);
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
  
  <!--쇼핑몰 - 관리자 상품 등록-->
  <servlet>
    <servlet-name>AdminGoodsFrontController</servlet-name>
    <servlet-class>com.itwillbs.admin.goods.action.AdminGoodsFrontController</servlet-class>
  </servlet>
  
  <servlet-mapping>
    <servlet-name>AdminGoodsFrontController</servlet-name>
    <url-pattern>*.ag</url-pattern>
  </servlet-mapping>  
  <!--쇼핑몰 - 관리자 상품 등록--> 
</web-app>
```
