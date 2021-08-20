<h1>fadeIn()</h1>

숨겨진 요소를 점점 뚜렷하게 표시

<ol>
  <li>$(선택자).fadeIn(속도, 콜백 함수)</li>
  <li>속도는 <b>'slow'</b>, <b>'fast'</b> 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 fadeIn() 다음에 실행</li>
</ol>

<h1>fadeOut()</h1>

보이는 요소를 점점 희미하게 표시

<ol>
  <li>$(선택자).fadeOut(속도, 콜백 함수)</li>
  <li>속도는 <b>'slow'</b>, <b>'fast'</b> 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 fadeOut() 다음에 실행</li>
</ol>


<h1>fadeToggle()</h1>

fadeIn()과 fadeOut()을 왔다 갔다 할 수 있다. 요소가 희미하면 뚜렷하게, 요소가 뚜렷하면 희미하게 표시

<ol>
  <li>$(선택자).fadeToggle(속도, 콜백 함수)</li>
  <li>속도는 <b>'slow'</b>, <b>'fast'</b> 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 fadeToggle() 다음에 실행</li>
</ol>

<h1>fadeTo()</h1>

투명도에 따라서 페이딩 조절

<ol>
  <li>$(선택자).fadeTo(속도, 투명도, 콜백 함수)</li>
  <li>속도는 <b>'slow'</b>, <b>'fast'</b> 또는 <b>밀리초</b></li>
  <li><b>투명도(0 ~ 1)</b>이며 0은 희미, 1은 뚜렷 </li>  
  <li><b>콜백 함수</b>는 fadeTo() 다음에 실행</li>
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
            $("button").click(function(){
                $("#p1").fadeIn(3000);
            });        
            
            $("#p2").mouseenter(function(){
                $(this).fadeOut(5000);
            });
            
            $("#p3").mouseover(function(){
                $(this).fadeTo("slow", 0.5, function(){
                    document.getElementById("p4").innerHTML = "fadeTo() 성공!!";
                });
            });
        });    
    </script>
</head>
<body>
    <button>버튼을 누르면 숨은 글이 표시됩니다.</button>
    
    <p id="p1" style="display:none;">이제 보입니다.</p>
    
    <p id="p2">마우스를 올리면 사라집니다.</p>
    
    <p id="p3">마우스를 올리면 글이 반 정도 희미해집니다.</p>
    
    <p id="p4"></p>
</body>
</html>
```
