<h2>forward로 페이지 출력</h2>

```java
package com.itwillbs.bean;
 
import java.io.IOException;
import java.io.PrintWriter;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
// 에노테이션: @ 형태로 특수한 기능을 수행/상태를 표현
// @WebServlet("/ex")
// => 해당 클래스(서블릿)을 주소로 매핑하는 동작 
// => 주소 호출 시 해당 파일을 실행
 
// http://localhost:8088/JSTL_ELJSP/*.nhn
// @WebServlet(value="가상 주소")
@WebServlet("*.nhn")
public class ExServlet extends HttpServlet {
 
    // 서블릿: JSP -> Java -> Class (실행)
    // => 자바 파일을 사용하면서 동시에 웹 페이지의 기능을 활용할 수 있는 파일
    
    // alt shift s + v
    @Override
    protected void doGet(HttpServletRequest request,
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("get 방식 호출일 때 실행");
        
        // forward를 사용하여 페이지 보여주기
        /* <jsp:> (x) */
        RequestDispatcher dis
           = request.getRequestDispatcher("/core/out.jsp");
        dis.forward(request, response);
                
        /*
         * // 화면에 출력 response.setContentType("text/html; charset=UTF-8"); //
         * 데이터를 출력하는 동작(출력스트림) PrintWriter out = response.getWriter();
         * out.println("<html>"); out.println("<head>"); out.println("</head>");
         * out.println("<body>"); out.println("<h1>서블릿 웹페이지</h1>");
         * out.println("</body>"); out.println("</html>");
         * 
         * out.close();
         */
    }
 
//    @Override
//    protected void doPost(HttpServletRequest request,
//            HttpServletResponse response) throws ServletException, IOException {
//        System.out.println("post방식 호출일 때 실행");
//    }
}
```
