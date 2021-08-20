<h1>slideDown()</h1>

요소가 미끄러져 내려간다.

<ol>
  <li>$(선택자).slideDown(속도, 콜백 함수)</li>
  <li>속도는 '<b>slow</b>', '<b>fast</b>' 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 slideDown() 다음에 실행</li>
</ol>

<br>

<h1>slideUp()</h1>

요소가 미끄러져 올라간다.

<ol>
  <li>$(선택자).slideUp(속도, 콜백 함수)</li>
  <li>속도는 '<b>slow</b>', '<b>fast</b>' 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 slideUp() 다음에 실행</li>
</ol>

<br>

<h1>slideToggle()</h1>

slideUp()과 slideDown()을 왔다 갔다 할 수 있다. 요소가 내려가 있으면 미끄러져 올라가고, 요소가 올라가 있으면 미끄러져 내려간다.

<ol>
  <li>$(선택자).slideToggle(속도, 콜백 함수)</li>
  <li>속도는 '<b>slow</b>', '<b>fast</b>' 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 slideToggle() 다음에 실행</li>
</ol>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <style> 
        #board, #doUp {
          padding: 5px;
          text-align: center;
          background-color: #229954;
          border: solid 1px #8E44AD;
        }
        
        #board {
          padding: 50px;
          display: none;
        }
    </style>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../jql/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            $("#doUp").mouseover(function(){
                $("#board").slideDown(2000);
            });
            
            $("button").click(function(){
                $("#board").slideUp(2000);
            });
        });    
        
        
    </script>
</head>
<body>
    <p id="doUp">마우스를 올리면 글이 보입니다.</p>
    
    <p id="board">안녕하세요.</p>
    
    <button>버튼을 누르면 글이 숨겨집니다.</button>
</body>
</html>
```
