<b>Model 2</b> 구조는 <b>MVC</b> 패턴을 사용해서 개발하며 디자인, 비즈니스 로직(개발)을 구분하기 위해서 생성한다. (즉, 대규모 프로젝트에서 개발하는 속도 및 유지 보수를 위해서 사용한다.)

<pre>
M(Model): <b>자바</b> 코드를 사용하며 <b>처리(process) 페이지와 DB 동작</b>을 담당한다. 
V(View): <b>JSP</b> 코드를 사용하며 <b>형식(form) 페이지와 정보 입출력 동작</b>을 담당한다.
C(Controller): <b>Servlet</b> 코드를 사용하며 <b>Model과 View를 연결하는 동작</b>을 담당한다.
</pre>

<b><i>Model2 실행은 JSP 코드를 사용하지 않으며 오로지 index.jsp만 실행할 수 있다. 또한, Model2 구조는 가상 주소를 사용하기 때문에 주소에 .jsp가 있으면 잘못된 접근이다.</i></b>

<h3>Model 2 방식의 페이지 이동</h3>
<ol>
  <li>response: redirect 방식 (response.sendRedirect(주소))</li>
  <ul>
    <li>페이지 이동 시 주소와 화면 둘 다 변한다. (e.g. 가상 주소 A.me -> 가상 주소 B.me)</li>
  </ul>
  
  <li>request: forward 방식 (RequestDispatcher dis = request.getRequestDispatcher(주소), dis.forward(request, response);</li>
  <ul>
    <li>페이지 이동 시 화면만 변한다. (e.g. 가상 주소 A.me -> 실제 주소 B.jsp)</li>
  </ul>
</ol>
