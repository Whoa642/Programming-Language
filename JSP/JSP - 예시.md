<h2>입력 받은 정보를 다른 페이지로 전달해서 출력</h2>

```jsp
<body>
   <h1>WebContent/jsp1/form1.jsp</h1>
 
   <form action="pro1.jsp" method="get">
     숫자: <input type="text" name="num"><br>
     <input type="submit" value="전송">  
   </form>
  

   <h1>WebContent/jsp1/pro1.jsp</h1>
   <!-- 
    form1.jsp 페이지에서 전달된 매개변수 값을 저장
   -->
   <%
  
    // 데이터를 전달할 때(즉 매개변수의 값을 생성할 때) 모든 데이터는 String 타입으로 처리된다.
    // getParameter에 매개변수의 이름을 사용해서 매개변수 값을 가져온다.
    String num = request.getParameter("num");
    
    // 문자열을 숫자로 변환
    int num2 = Integer.parseInt(request.getParameter("num")); 
   %>
   
  <%=request.getParameter("num") %>
</body>
```

<h2>입력 받은 나이와 이름을  다른 페이지로 전달해서 조건에 맞추어 화면에 출력</h2>

```jsp
<body>
  <h1>WebContent/jsp1/form2.jsp</h1>
 
     <form action="testPro2.jsp" method="post">
       이름: <input type="text" name="name"><br>
       나이: <input type="text" name="age"><br>
       <input type="submit" value="입력">
     </form>  
 
  
     <h1>WebContent/jsp1/pro2.jsp</h1>
 
    <%
        // form 태그 정보를 get이 아니라 post 방식으로 전달 시 한글 데이터가 깨지는 인코딩 오류 발생
        request.setCharacterEncoding("UTF-8");

        String name = request.getParameter("name");
        // 데이터가 문자열이기 때문에 정수로 변환한다.
        int age = Integer.parseInt(request.getParameter("age"));
    %>
 
    이름: <%=name%>
    나이: <%=age%><br>
    <%
        // 사용자의 나이가 20살 이상이면 "성인입니다.", 아니면 "미성년자입니다."를 출력한다.
 
        // 1.Java
        if (age >= 20) {
            out.println(name + "님은 성인 입니다.<br>");
        } else {
            out.println(name + "님은 미성년자 입니다.<br>");
        }
 
        // 2.Java + HTML, 이 방식의 경우 전달 받은 매개변수를 출력할 수 없다.
        if (age >= 20) {
            %>
            님은 성인 입니다.<br>
            <%
        } else {
            %>
            님은 미성년자 입니다.<br>
            <%
        }
        
        // 3.표현식
            if (age >= 20) {
            %>
            <%=name%> 님은 성인 입니다.<br>
            <%
        } else {
            %>
            <%=name%> 님은 미성년자 입니다.<br>
            <%
        }
    %>
 
</body>
```

<h2>같은 매개변수 이름을 가지는 여러 데이터를 받아서 매개변수 값 출력</h2>

```jsp
<body>
  <h1>WebContent/jsp1/form3.jsp</h1>
 
      <form action="testPro3.jsp" method="get">   
    이름: <input type="text" name="name"><br>
    성별: 
        <input type="radio" name="gender" value="남"> 남
        <input type="radio" name="gender" value="여"> 여 
        <br>
  
    취미: 
        <input type="checkbox" name="hobby" value="게임"> 게임    
        <input type="checkbox" name="hobby" value="운동"> 운동
        <input type="checkbox" name="hobby" value="요리"> 요리
        <br>
   
   과목: 
          <select name="subject">
          <option value="">선택하세요.</option>
          <option value="java">Java</option>
          <option value="js">JavaScript</option>
          <option value="web">Web</option>
          <option value="db">DB</option>
       </select>
      <hr>
 
      <input type="submit" value="전달">
    </form>
  
  
     <h1>WebContent/jsp1/pro3.jsp</h1>
  <%
    // 한글 데이터 처리 
    request.setCharacterEncoding("UTF-8");
    // 전달정보 저장(파라미터 저장)
    String name = request.getParameter("name");
    String gender = request.getParameter("gender");
 
    // request.getParameterValues("매개변수 이름")은 String 배열을 반환한다.
    String[] hobby = request.getParameterValues("hobby");
    String subject = request.getParameter("subject");
  %>
  
  이름: <%=name%><br>
  성별: <%=gender%><br>
  
  <% // 매개변수의 값이 있는지 일단 판별해야 한다.
   if(hobby != null){
    // hobby의 크기만큼 출력
    for(int i = 0; i < hobby.length; i++){
        %>
          취미: <%=hobby[i]%><br> 
        <%
     }
   }
  %>
  
  과목: <%=subject%><br>
 
</body>
```

