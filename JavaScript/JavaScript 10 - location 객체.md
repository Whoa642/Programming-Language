<b>location</b> 객체는 브라우저의 주소 창에 대한 정보를 저장하는 객체이다. 

<h2>location 객체의 속성을 확인하고 변경하는 코드</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
 
  // location 객체의 속성을 확인
  function func1(){
      alert("href:" + window.location.href); 
      alert("protocol:" + location.protocol); 
      alert("hostname:" + location.hostname); 
      alert("host:" + location.host);  
      alert("port:" + location.port);
      alert("search:" + location.search);
  }
  
  // location.href 속성을 변경해서 test1.html 페이지로 이동
  function func2()
      location.href="test1.html";
  
  // 페이지 새로고침
  location.reload();
  
  // 페이지 이동
  location.replace("test1.html");
      
</script>
</head>
<body>
    <h1>WebContent/js2/test8.html</h1>
    
    <input type="button" value="location 속성 값 확인" onclick="func1();"> <br>
    <input type="button" value="location 속성 값 변경" onclick="func2();"> <br>
    
</body>
```
