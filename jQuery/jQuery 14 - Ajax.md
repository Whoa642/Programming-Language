<b>Ajax</b>(Asynchronous JavaScript and XML)을 약자로 <b>비동기 방식의 자바스크립트와 XML</b>을 의미한다. 

XML은 일종의 자료형으로 사람과 기계가 읽을 수 있는 형태로 문서를 인코딩하는 일련의 규칙을 정의한다.

XML의 특징
태그의 형태로 데이터를 저장한다.
유연한 데이터의 형태를 가진다.
HTML과 동일하게 DOM 메서드를 사용할 수 있다.
다른 프로그램들과의 데이터 통신에서 많이 사용한다.
태그의 크기가 데이터보다 크기 때문에 처리 시간이 많이 걸린다.
요청이 동일한 도메인에서 처리된다.

동기 방식의 데이터 처리
서버의 데이터를 처리하며 페이지 이동 시 처리가 가능하다.(화면이 깜빡인다.)
자료 요청 시 반드시 서버 컴퓨터를 거쳐야 하며 그동안 사용자는 대기해야 한다. (사용자 요청 -> 웹 서버 -> 사용자 응답)

비동기 방식의 데이터 처리
자료 요청 시 서버 컴퓨터에 정보를 가져와서 사용하며 화면 전환이 없다. (페이지 이동)

<pre>
Ajax 표현식
    $.(주소).ajax({속성}); 
    $.ajax(주소, {속성}); 
    $.ajax({
            url: "전송 페이지",
            type: "전송 방식(get/post)",
            data: "전송할 데이터",
            dataType: "요청한 자료형(html, xml, text, json)",
            success: function(데이터){
                전송 완료 시 동작 처리
            }
    });
</pre>   
  

```jsp
<!--string1.html-->
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script src="../js/jquery-3.6.0.js"></script>
    <script type="text/javascript">
      $(document).ready(function(){
          // $.ajax(); , $(요소).ajax();
          // $.ajax("string1.jsp");
          // location.href = "string1.jsp";
          
          $.ajax('string1.jsp',{
              success: function(data){
                  alert('전송 성공')
                  alert('Data: '+data);
                  $('body').append(data);
              }
          });
      });
    </script>
</head>
<body>
    <h1>WebContent/jq3/string1.html</h1>
</body>
 
<!--string1.jsp-->
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <% 
        System.out.println("string1.jsp 페이지 호출");
    %>
    
    <h1>Hello</h1>
</body>
```

```jsp
<!--string2.html-->
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script src="../js/jquery-3.6.0.js"></script>
    <script type="text/javascript">
      $(document).ready(function(){
          // $.ajax(); , $(요소).ajax();
          // $.ajax("string1.jsp");
          // location.href = "string1.jsp";
          
          $.ajax('string2.jsp',{
              data: {name:'홍길동', age:20},
              
              success: function(data){
                  alert('페이지 호출 완료');
                  alert('Data: '+data);
                  $('body').append(data);
              }
          });
      });
    </script>
</head>
<body>
    <h1>WebContent/jq3/string2.html</h1>
    <!--string2.jsp 페이지에 있는 정보 출력-->
    
</body>
 
<!--string2.jsp-->
<h1>string2.jsp</h1>
<%
    System.out.println("string2.jsp 호출");
    System.out.println("데이터: "+request.getParameter("name"));
    System.out.println("데이터: "+request.getParameter("age"));
    
    String name = request.getParameter("name");
    String age = request.getParameter("age");
    
    // 이름: 홍길동, 나이: 20살
%>
 
    <h2>이름: <%=name %>, 나이: <%=age %>살</h2>
```

```jsp
<!--xml.html-->
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script src="../js/jquery-3.6.0.js"></script>
    <script type="text/javascript">
      $(document).ready(function(){
 
          // ajax 사용해서 xml 데이터 가져오기
          $.ajax('xml.jsp',{
                data: {name:'홍길동', age:20},
              
              success: function(data){
                  alert('xml 페이지 데이터 가져오기');
                  //alert(data);
                  //console.log(data);
                  //$('body').append(data);
                  
                  $(data).find('person').each(function(){
                      
                      // alert($(this).find('name').text());
                      // body 태그에 이름, 나이, 성별 출력
                      var name = $(this).find('name').text();
                      var age = $(this).find('age').text();
                      var gender = $(this).find('gender').text();
                      
                      $('body').append('이름:'+name+', 나이:'+age+', 성별:'+gender+'<br><hr>');
                  });
              }
          });
      });
    </script>
</head>
<body>
    <h1>WebContent/jq3/xml.html</h1>
    <!--xml.jsp 페이지에 있는 정보 출력-->
</body>
 
<!--xml.jsp-->
    <people>
        <person>
        <name>홍길동</name>
         <age>20</age>
         <gender>남</gender>
        </person>
        
        <person>
        <name>홍길동2</name>
         <age>30</age>
         <gender>여</gender>
        </person>
        
        <person>
        <name>홍길동3</name>
         <age>40</age>
         <gender>남</gender>
        </person>
    </people>
```
