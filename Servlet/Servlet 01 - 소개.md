JSP(Java Server Page)는 클라이언트의 요청을 처리하고 결과를 동적인 페이지로 처리하는 기술이다.(HTML 코드도 컴파일이 필요해졌기 때문에 JSP 페이지가 등장하게 되었다.)

<b>서블릿(Servlet)</b>은 멀티 스레드를 사용해서 사용자의 요청을 전달 받아서 동적으로 처리하는 방법이다.


<h2>서블릿에서 HTML 페이지 출력</h2>

<pre>
response.setContentType("text/html; charset=UTF-8");
PrintWriter out = response.getWriter();
    out.println("<html>");
    out.println("<head>");
    out.println("</head>");
    out.println("<body>");
    out.println("<h1>서블릿 웹페이지</h1>");
    out.println("</body>");
    out.println("</html>");
out.close();  
</pre>

<h2><i>서블릿 사용 규칙</i></h2>
<ol>
  <li>javax.servlet.Servlet 인터페이스를 구현해야 한다.</li>
  <li>1번 인터페이스를 구현하기 어렵다면 javax.servlet.http.HttpServlet 클래스를 상속한다.</li>
  <li>doGet/doPost와 같은 메서드를 구현 (javax.servlet.http.HttpServletRequest, javax.servlet.http.HttpServletResponse), 두 개의 데이터를 매개변수로 전달 받아야한다. (순서 중요)</li>
  <li>예외처리를 해야한다. (java.io.IOException, javax.servlet.ServletException</li>
  <li>web.xml(배포서술자) 통해서 서블릿을 매핑한다. (서블릿 3.0 이상은 선택 사항이며 @WebServlet()을 활용할 수 있다.)</li>
</ol>
  
<h2>JSP -> Servlet 변환 규칙</h2>
<ol>
  <li>JSP 스크립틀릿 (<% %>): 서블릿 안에 있는 service() 메서드</li>
  <li>JSP 표현식 (<%= %>) : 서블릿 안에 있는 service() - out.print() 변환</li>
  <li>JSP 선언문 (<%! %>) : 서블릿 안에 멤버(변수, 메서드)로 생성</li>
  <li>JSP 일반 HTML : 서블릿 안에 있는 service() - out.write() 변환</li>
</ol>

<h2>서블릿</h2>

```java
package com.itwillbs.servlet;
 
import java.io.IOException;
import java.io.PrintWriter;
 
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
public class MyServlet extends HttpServlet {
 
    private int cnt = 0; 
    
    @Override
    public void init() throws ServletException {
        System.out.println("서블릿 초기화 init()");        
    }
    
//    @Override
//    public void service(ServletRequest arg0, ServletResponse arg1) throws ServletException, IOException {
//        System.out.println("서비스 동작 호출 service()");    
//    }
 
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       System.out.println("doGET() 호출");
       doPost(req, resp);
    }
 
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       System.out.println("doPOST() 호출");
       
       cnt++;
       
       resp.setContentType("text/html; charset=UTF-8");
       PrintWriter out = resp.getWriter();
       
       out.print("<html>");
       out.print("<head>");
       out.print("</head>");
       out.print("<body>");
       out.print("<h2> 홈페이지 방문자수: "+cnt+"</h2>");
       out.print("</body>");
       out.print("</html>");
       
       out.close();   
    }
 
    @Override
    public void destroy() {
        System.out.println("서블릿 소멸 destroy()");
    }
}
```

<h2>web.xml</h2>

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://java.sun.com/xml/ns/javaee" xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_3_0.xsd" id="WebApp_ID" version="3.0">
  <display-name>ServletJSP</display-name>
  <welcome-file-list>
    <welcome-file>index.html</welcome-file>
    <welcome-file>index.htm</welcome-file>
    <welcome-file>index.jsp</welcome-file>
    <welcome-file>default.html</welcome-file>
    <welcome-file>default.htm</welcome-file>
    <welcome-file>default.jsp</welcome-file>
  </welcome-file-list>
  
  <servlet>
     <servlet-name>MyServlet</servlet-name>
     <servlet-class>com.itwillbs.servlet.MyServlet</servlet-class>
  </servlet>
  
  <servlet-mapping>
    <servlet-name>MyServlet</servlet-name>
    <url-pattern>/my</url-pattern>
  </servlet-mapping>
</web-app>
```
