<b>form</b> 태그를 사용해서 사용자가 입력한 정보를 저장해서 <b>action="주소"</b>에서 주소로 전달할 수 있다.(<b>주소가 없으면 자신의 페이지로 전달한다.</b>) 
method에는 정보 전달 방식을 명시한다. 정보 전달 방식에는 get, post 2가지 방식이 존재한다. <b>get 방식의 경우 기본값이기 때문에 생략할 수 있지만 post는 직접 명시해야 한다.</b>

<h2>GET 방식(get 메서드)</h2>
<ul>
  <li>데이터를 전달할 때 매개변수를 사용해서 전달한다.</li>
  <li>해당 정보를 URL의 정보에 붙여서 전달하는 방식이다.</li>
  <li>데이터의 길이가 256 byte를 넘을 수 없다는 제약을 가진다.</li>
  <li>본문 body 영역이 필요 없다.</li>
  <li>빠른 데이터 전송이 가능하다.</li>
  <li>주소 줄에 매개변수가 표현되기 때문에 보안에 취약하다.</li>
  <li>정보 입력, 출력 페이지에 사용한다.</li>
</ul>

<h2>POST 방식(post 메서드)</h2>
<ul>
  <li>GET과 마찬가지로 데이터를 전달할 때 매개변수를 사용해서 전달한다.</li>
  <li>해당 정보를  본문 body에 붙여서 전달한다.</li>
  <li>데이터 길이에 제약이 없다.</li>
  <li>상대적으로 느린 데이터 전송 방식이다.</li>
  <li>주소 줄에 매개변수가 보이지 않기 때문에 보안에 우수하다.</li>
  <li>정보 처리 페이지에 사용한다.</li>
</ul>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
 
      // form 태그의 접근방식(document의 image)
      // 1) (window.)document.forms[0].속성
      // 2) (window.)document.form 태그의 name.속성
     
      function func1(){
          alert("method:" + document.fr.method);
          alert("name:" + document.forms[0].method);
      }
      
      function func2(){
          // 이동페이지 b.jsp 
          window.document.forms[0].action = "b.jsp";
          // 이동방식 post
          document.fr.method = "post";
          // submit 기능실행
          document.fr.submit();          
      }
      
      function func3(){
          // c.jsp, get방식
          document.forms[0].action = "c.jsp";
          document.fr.method = "get";
          // submit() 사용 X => submit 버튼 클릭(submit 이벤트 발생)
      }
      
    </script>
</head>
<body>
 
  <fieldset>
    <legend>form 태그</legend>
      <!-- submit 이벤트 발생시 get 방식으로 c.jsp 페이지로 정보를 전달한다. -->
      <form action="a.jsp" method="get" name="fr" onsubmit="func3();">
        <input type="text" name="id">
        
        <input type="submit">
        <hr>
        <input type="button" value="form 태그 속성 확인" onclick="func1();">
        <!-- 해당 버튼 클릭시 b.jsp 페이지로 post 방식으로 정보를 전달한다. -->
        <input type="button" value="form 태그 속성 변경" onclick="func2();">
      </form> 
  </fieldset>
  
</body>
```
