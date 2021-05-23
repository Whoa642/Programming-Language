<b>history</b> 객체는 사용자가 방문한 페이지에 대해서 처리하는 객체이고 navigator 객체는 페이지에 방문하는 사용자의 브라우저 정보와 운영체제 정보를 제공하는 객체이다.

<h2>history 객체의 기능을 사용해서 페이지를 앞뒤로 이동하는 코드</h2>

```html
<body>
 
  <h2>1 페이지</h2>
  
  <a href="test9_1.html">2페이지로 이동하기</a>
  
</body>
-------------------------------------------------------------------------------------------------------
 
<body>
  <h1>test9_1.html</h1>
  
  <h2>2 페이지</h2>
  
  <a href="test9_2.html">3페이지로 이동하기</a>
  <hr>
  
  <input type="button" value="뒤로 이동" onclick="history.back();">
  <input type="button" value="앞으로 이동" onclick="history.forward();">
 
</body>
-------------------------------------------------------------------------------------------------------
 
<body>
  <h1>test9_2.html</h1>
  
  <h2>3 페이지</h2>
  
  <a href="test9_3.html">4페이지로 이동하기</a>
  
  <hr>
  <input type="button" value="뒤로 이동" onclick="history.back();">
  <input type="button" value="앞으로 이동" onclick="history.forward();">
  
</body>
-------------------------------------------------------------------------------------------------------
 
<body>
  <h1>test9_3.html.</h1>
  
  <h2> 4 페이지 </h2>
  
  <hr>
  <input type="button" value="뒤로 이동(-1)" onclick="history.go(-1);">
  <input type="button" value="뒤로 이동(-2)" onclick="history.go(-2);">
  
  
</body>
```
