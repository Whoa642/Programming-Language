<b>쿠키(cookie)</b>란 HTTP 통신에서 사용자의 응답을 처리하고 서버의 정보를 저장하기 위한 객체이다. 
<ul>
  <li>이름, 값, 유효 기간, 도메인, 경로 등의 정보를 가지고 있으며 이름은 영문자와 숫자로 구성된다.(공백과 특수 문자를 사용하고 싶을 경우 인코딩이 필요하다).</li>
  <li>쿠키는 브라우저가 종료되어도 생존 시간이 정해지면 그동안 계속 사용할 수 있다.<b>(사용자의 HDD에 저장된다.)</b></li>
  <li><b><i>생성한 쿠키를 반드시 클라이언트에 보내야 사용자의 HDD에 저장된다.</i></b></li>
  <li>세션과 달리 서버가 아니라 클라이언트에 정보가 저장되기 때문에 보안에 취약한다.</li>
</ul>

<h2>쿠키 생성, 저장, 사용</h2>

```jsp
<%
// 쿠키 생성 (서블릿 API사용)
Cookie cookie = new Cookie("이름", "값");
 
// 쿠키정보를 저장(response 객체에 저장)
response.addCookie(쿠키 객체);
 
// 쿠키 사용(request 객체에 있는 쿠키 사용), 쿠키의 정보는 객체 배열의 형태로 사용
Cookie[] cookies = request.getCookies();
%>
```

<h2>쿠키를 생성하고 삭제</h2>

```jsp
<body>
  <h1>WebContent/jsp4/cookieTest.jsp</h1>
  <%
   // 쿠키값 사용
   Cookie[] cookies = request.getCookies();
   
   String name = "";
   String value = "";
 
   // 쿠키값이 있을 때만 비교
   if(cookies != null){
       // 생성된 쿠키의 값을 출력
       for(int i = 0; i < cookies.length; i++){
           //쿠키값 이름이 'name'대상을 찾아서 값을 사용
           if(cookies[i].getName().equals("name")){
               name = cookies[i].getName();
               value = cookies[i].getValue();
           }
       } 
   }
  %>
  
  <h2>클라이언트</h2>
  <h3>쿠키 이름: <%=cName %></h3>
  <h3>쿠키 값: <%=cValue %></h3>
  
  <input type="button" value="쿠키값 생성" onclick="location.href='cookieSet.jsp';">
  <input type="button" value="쿠키값 삭제" onclick="location.href='cookieDel.jsp';">
  
  
  <h1>WebContent/jsp4/cookieSet.jsp</h1>
  
  <h2>서버</h2>
  <%
    // 쿠키값 생성 (서블릿 API), 메모리에 저장되고 HDD에는 저장되지 않는다.
    Cookie cookie = new Cookie("name", "cookieValue");
    
    // 쿠키 필수 옵션을 지정, 사용 가능 시간을 지정
    cookie.setMaxAge(600); // 600초 -> 10분
    
    // 쿠키 정보를 클라이언트로 전달해서 클라이언트의 HDD에 저장
    response.addCookie(cookie);
  %>
  
  <script type="text/javascript">
    alert('서버: 쿠키값 생성');
    location.href = 'cookieTest.jsp';  
  </script>
  
  <h1>WebContent/jsp4/cookieDel.jsp</h1>
   <h2>서버</h2>
   <%
  
   // 1) 기존의 쿠키값 가져오기 (배열의 형태로 저장)
   Cookie[] cookies = request.getCookies();
   
   // 2) 쿠키 배열을 처음부터 끝까지 검색 - 필요정보 확인
   if(cookies != null){
       for(int i= 0; i < cookies.length; i++){
           if(cookies[i].getName().equals("name")){
             // 3) 쿠키값을 삭제 
             // 파일을 삭제하는 것이 아니라 쿠키값 데이터 자체의 사용시간 -> 0
             cookies[i].setMaxAge(0);    
             
             // 4) 쿠키 삭제 정보를 클라이언트로 전달
             response.addCookie(cookies[i]);
           }           
       }
   }
   %>
 
   <script type="text/javascript">
     alert("서버: 쿠키값 삭제!");
     location.href = "cookieTest.jsp";   
   </script>
   
</body>
```

<h2>선택된 언어에 따라서 다른 메세지를 출력</h2>

```jsp
<body>
 <h1>WebContent/jsp4/cookieForm.jsp</h1>
 <%
   // 9. 출력을 위한 언어 정보 저장 변수
   String lang = "KOR";
   // 6. 생성된 쿠키값에 따라서 출력되는 메세지 변경
   // 7. 쿠키값을 request에서 가져오기
   Cookie[] cookies = request.getCookies();
 
   // 8. 쿠키 배열의 값을 모두 비교해서  원하는 정보 사용
   if(cookies != null){
       for(int i=0; i < cookies.length; i++){
           if(cookies[i].getName().equals("lang")){
               lang = cookies[i].getValue();
           }
       }
   }
 
   // 10. 결과 출력
   if(lang.equals("KOR")){
       out.print("안녕하세요, 쿠키 연습!");
   }else{
       out.print("Hello, Cookie Test!");
   }
   
 %>
 
   <!-- 1. 쿠키 값을 생성하기 위한 데이터 전달 -->
   <form action="cookiePro.jsp" method="post">
      <input type="radio" name="language" value="KOR"
             <%if(lang.equals("KOR")){ %>checked="checked"<%} %>> 한국어 
      <input type="radio" name="language" value="ENG"
             <%if(lang.equals("ENG")){ %>checked="checked"<%} %>> 영어 
      <input type="submit" value="언어 설정"> 
   </form>
 
    <h1>WebContent/jsp4/cookiePro.jsp</h1>
   <%
    // 2. 전달된 정보사용 쿠키값 생성
    Cookie cookie = new Cookie("lang", request.getParameter("language"));
    
    // 3. 쿠키 설정값 지정 (1시간 사용)
    cookie.setMaxAge(60*60);
    
    // 4. 쿠키 정보를 사용자에게 전달 (HDD저장)
    response.addCookie(cookie);

    // 5. cookieForm.jsp 페이지 이동
   %>
   <script type="text/javascript">
      alert("언어 쿠키 정보를 생성!");
      location.href = "cookieForm.jsp";
   </script>
  
 
</body>
```

<h2>쿠키를 사용한 간단한 팝업 창</h2>

```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
<script type="text/javascript">
   
   // 페이지 온로드 이벤트 발생 시 pageLoad()호출
   window.onload = pageLoad();
   
   function pageLoad(){
       var notShowPop = getCookieValue();
       
       if(notShowPop != "true"){
       // 팝업 열기
         window.open("cookiePopup.jsp", "","width=400, height=500, left=200, top=300");
       }
       
   }
   
   function getCookieValue(){
       var result = "false";
       
       // 쿠키 정보를 확인해서 해당 쿠키를 체크
       if(document.cookie != ""){
          // 쿠키값을 구분
          var cookie = document.cookie.split(";");
           
          for(var i = 0; i < cookie.length; i++){
              // 속성과 값을 구분
              var element = cookie[i].split("=");
              var nameValue = element[0];
              // \ s(문자열 공백) 제거 
              nameValue = nameValue.replace(/^\s*/, '');
              // 쿠키명이 notShowPop 쿠키를 찾는다
              if(nameValue == "notShowPop"){
                  // 쿠키값을 result변수에 저장
                  result = element[1];
              }
          }
       }       
       return result;
   }
   
   function popUpReStart(){
       document.cookie = "notShowPop="+"false"+";path=/; expires=-1";
   }
   
</script>
 
</head>
<body>
  <h1>WebContent/jsp4/cookiePopupTest.jsp</h1>
  
  <h2> 쿠키사용한 팝업 예제 (Javascript 사용)</h2>
  
  <input type="button" value="팝업 허용하기" onclick="popUpReStart();">
  
</body>
```

```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
  <script type="text/javascript">
      // setPopupStart(this); 호출 코드
      function setPopupStart(obj){
          // 쿠키 정보를 생성 (시간 정보를 저장)
          if(obj.checked == true){
              var expireDate = new Date();
              expireDate.setMonth(expireDate.getMonth() + 1); // 유효기간 1달
              // 쿠키이름 = 쿠키값; path=경로; expires = 기간;
              document.cookie = "notShowPop="+"true"+";path=/; expires="+expireDate.toGMTString();
              window.close();
          }
      }
  </script>
 
</head>
<body bgcolor="orange">
   <h1>cookiePopup.jsp</h1>
   <h2> ITWILL 광고 이벤트 입니다. </h2>
   
   <br><br><br><br><br><br>
   <br><br><br><br><br><br>
   
   <input type="checkbox" onclick="setPopupStart(this);"> 오늘 더 이상 팝업창 띄우지 않기 
   
</body>
```
