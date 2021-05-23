브라우저 객체 모델은 인터넷 브라우저 안에 계층적으로 모여있는 객체를 말한다. 최상위 계층에는 window 객체가 존재하면 하위 객체에 document, screen, location, history, navigator 객체가 존재한다. 

<b>window</b> 객체는 브라우저 창을 표시하는 객체이며 최상위 객체이기 때문에 생략할 수 있다. <b>document</b> 객체는 현재 문서 페이지의 정보를 나타내는 객체이며 <b>screen</b> 객체는 사용자의 모니터 정보(모니터 크기, 해상도)를 제공하는 객체이다.

<b>이벤트</b>는 사용자가 브라우저에서 발생시킨 모든 동작(마우스, 키보드, ...)을 의미한다. <b>이벤트 리스너</b>는 이벤트 발생 정보를 핸들러에게 전달한다. <b>이벤트 핸들러</b>는 이벤트가 발행하면 HTML 태그에서 <b>on</b>으로 시작하는 동작들을 처리한다.
(자바스크립트의 코드를 실행 할 수 있게 해준다.) 

```html
<body onload="alert('onload 실행');">
 
  <!-- button 객체 생성 -->
  <input type="button" value="버튼1" onclick="alert('클릭');"> <!-- 버튼이 생성되며 한 번 누르면 메세지가 출력된다. -->
  <input type="button" value="버튼2" ondblclick="alert('더블 클릭');"> <!-- 버튼이 생성되며 두 번 누르면 메세지가 출력된다. -->
 
  <img src="../time.jpg" width="50" height="50" onmouseover="alert('마우스 오버');"> <!-- 마우스를 올리면 메세지가 출력된다. -->
  <input type="text" onkeyup="alert('키보드 입력');"> <!-- 키보드를 입력하면 메세지가 출력된다. -->
 
  <!-- 마우스가 올라왔을 때(over) 배경색 초록색, 마우스가 나갔을 때(out) 배경색 노란색 
       style.background="색"; -->

   <table>
    <tr bgcolor="yellow" onmouseover="style.background='green'" 
         onmouseout="style.background='yellow'"
    >
     <td>1</td>
     <td>2</td>
    </tr>
 
    <tr>
     <td>3</td>
     <td>4</td>
    </tr>
   </table>
</body>
```

<hr>

<h2>window.open()으로 새 창을 열고 window.close() 열린 창을 닫는 코드</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
 <script type="text/javascript">
    // window.open("주소", "창이름", "옵션");
    function winopen()
        window.open("test6_1.html","","width=300,height=300");
        
 </script>    
</head>
 
<body>
 
 <!--
   창열기:버튼클릭시 창열기 동작실행->test6_1.html 새창 열기
   창닫기:버튼 클릭시 새창 닫기 -->
  
 <input type="button" value="창열기" onclick="winopen();"> <!-- 자바스크립트의 함수 winopen을 실행한다. test6_1.html 파일을 새로운 창에 연다. -->
 <input type="button" value="창닫기" onclick="window.close();"> <!-- 현재 창을 닫는다. test6_1.html 창을 닫으려면 이 파일에 window.close() 코드가 있어야 한다. -->
 
</body>
```
