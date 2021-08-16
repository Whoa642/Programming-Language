<h1>hide(), show()</h1>

hide()를 사용해서 HTML 요소를 숨기고 show()를 사용해서 HTML 요소를 표시
<ol>
  <li>$(선택자).hide/show(속도, 콜백 함수)</li>
  <li><b>속도</b>를 옵션으로 '<b>slow</b>', '<b>fast</b>', <b>밀리초</b>로 받을 수 있다.</li>
  <li><b>콜백 함수</b>를 옵션으로 hide(), show() 다음에 받을 수 있다.</li>
</ol>

<br>  
  
<h1>toggle()</h1>

hide(), show()를 왔다 갔다 한다. 요소가 보이면 숨기고 안보이면 보이게 한다.

<ol>
  <li>$(선택자).toggle(속도, 콜백 함수)</li>
  <li><b>속도</b>를 옵션으로 '<b>slow</b>', '<b>fast</b>' 또는 <b>밀리초</b>로 받을 수 있다.</li>
  <li><b>콜백 함수</b>를 옵션으로 toggle() 다음에 받을 수 있다.</li>
</ol>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <!--jQuery 라이브러리 추가-->
    <script src="../jql/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            $("#b1").click(function(){
                $("h3").hide(2000);
            });
            
            $("#b2").click(function(){
                $("h3").show(2000);
            });
            
            // 콜백 함수
            $("#b3").click(function(){
                $("h3").toggle(3000, function(){
                    alert("toggle 호출");
                });
            })
            
        });    
    </script>
</head>
<body>
    <h3 id="h31">왜 이리 졸리지?</h3>
    <button id="b1">버튼 클릭 시 글 표시 X</button>
    <button id="b2">버튼 클릭 시 글 표시 O</button>
    <button id="b3">버튼 클릭 시 글 표시 O/X</button>
    
</body>
</html>
```
