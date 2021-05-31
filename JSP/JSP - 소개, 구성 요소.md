<b>JSP</b>는 동적인 데이터를 처리할 수 없는 HTML의 한계를 극복하기 위해서 개발된 기술들 중 하나이다. <b><i>Java와 HTML 코드를 한 번에 사용할 수 있다.</i></b>

.jsp 파일을 생성하면 컴파일러는 .java 파일을 자동적으로 생성하고 .class 파일을 실행한다. 여기서 .java를 <b>서블릿 파일</b>이라고 한다.<br>

<h2>JSP 구성 요소</h2>
<ol>
<li>JSP 지시어(Directive):JSP 페이지가 실행될 때 필요한 정보를 지정하며 필요한 정보를 웹 컨테이너(tomcat)에게 알려서 처리하는 지시 부분이다.(형식:<b><%@ %></b>)</li>
  <ul>
    <li type="disc"><%@ page ~ %>:JSP 페이지에 대한 속성을 지정하는 지시어</li>
    <li type="disc"><%@ include ~ %>:특정 JSP 파일 or HTML 파일을 해당 JSP 페이지에 삽입할 수 있도록 하는 기능을 제공한다. 공통되는 부분을 따로 파일로 만들어 삽입한다.</li>
    <li type="disc"> <%@ taglib ~ %>:JSTL이나 커스텀 태그 등 라이브러리를 JSP에서 사용할 때 접두사를 지정하기 위해 사용된다.</li>
  </ul>
  <li>JSP 선언문(Declaration):전역 변수, 메서드를 선언하는 영역(형식:<b><%! 변수, 메서드 %></b>)</li>
  <li>스크립틀릿:Java 코드를 실행하는 영역(지역 변수, 메서드 호출, 형식:<b><% Java 코드 %></b></li> 
  <li>표현식:HTML 화면에 Java 코드의 결과를 출력한다.(형식:<b><%=변수, 수식, 반환값 있는 메서드 호출(Java 코드) %></b>)</li>
</ol>

<h2>주석</h2>
<ul>
  <li>HTML 주석:브라우저에 아무런 영향을 주지 않는다.(형식:<b>&lt;!--  --&gt;</b>)</li>
  <li>JSP 주석:내부적으로 무시하지만 브라우저에 영향을 줄 가능성이 있다.(형식:<b>&lt;%--  --%&gt;</b>)</li>
</ul>

<hr>

<h2>표현식과 스크립틀릿을 사용해서 Java 코드를 HTML 화면에 출력</h2>

```jsp
<body>

  <%
    String[] arr = new String[4];
    arr[0] = "Java";
    arr[1] = "JSP";
    arr[2] = "HTML";
    arr[3] = "JavaScript";
    
    // 콘솔에 출력한다.
    for(int i = 0; i < arr.length; i++)
        System.out.println(arr[i]);
    
    // 자바 코드를 사용해서 HTML 화면에 출력한다.
    for(int i = 0; i < arr.length; i++)
        out.println("<h2>"+arr[i]+"</h2>");
    
    // % 태그로 만들어진 자바 코드는 연결되어 있다.
    for(int i = 0; i < arr.length; i++){
  %>
      HTML 코드: <%=arr[i]%><br>        
  <% 
     }
  %>
  
  <hr>
  <!-- JSP 코드를 사용해서 번호와 이름을 출력한다. -->
  <table border="1">
   <tr>
     <td>번호</td>
     <td>이름</td>
   </tr>
   <%
   for(int i = 0; i < arr.length; i++){
   %>
       <tr>
         <td><%=i+1%></td>
         <td><%=arr[i]%></td>
       </tr>
   <% 
   }
   %>
 
  </table>
</body>
```
