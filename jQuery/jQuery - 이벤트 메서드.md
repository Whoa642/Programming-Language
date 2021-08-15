<h1>정의</h1>

제이쿼리는 HTML 페이지의 이벤트에 반응하도록 설계 (<b>이벤트</b>: 웹 페이지가 반응하는 모든 사용자의 행위를 의미)

<br>

<h1>문법</h1>

대부분의 DOM 이벤트는 상응하는 제이쿼리 메서드를 가진다.
<ol>
  <li>선택자를 선택</li>
  <li>이벤트에 함수 전달</li>  
</ol>

<br>

<h1>자주 사용되는 제이쿼리 이벤트 메서드</h1>

<h2>$(document).ready()</h2>

문서가 완전히 로딩된 후 함수를 실행하게 허용

<h2>click()</h2>

HTML 요소를 클릭하면 실행

<h2>dblclick()</h2>

HTML 요소를 더블 클릭하면 실행

<h2>mouseenter()</h2>

마우스 포인터가 HTML을 가리키면 실행

<h2>mouseleave()</h2>

마우스 포인터가 HTML을 가리키고 나가면 실행

<h2>mousedown()</h2>

마우스가 HTML 요소에 있을 때 왼쪽, 가운데, 오른쪽 마우스 버튼을 누르면 실행

<h2>mouseup()</h2>

마우스가 HTML 요소에 있을 때 왼쪽, 가운데, 오른쪽 마우스 버튼을 누르고 놓으면 실행

<h2>hover()</h2>

2개의 함수를 받으며 mouseenter()와 mouseleave()의 조합
마우스가 포인터가 HTML을 가리키면 1번째 함수 실행
마우스가 포인터가 HTML을 가리키고 나가면 2번째 함수 실행

<h2>focus()</h2>

form 필드가 focus를 받으면 실행

<h2>blur()</h2>

form 필드가 focus를 잃으면 실행

<h2>on()</h2>

주어진 요소에 대해 1개 이상의 이벤트 핸들러를 바인딩

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
                    $("#h31").hide();        
                });
                
                $("#b2").dblclick(function(){
                    $("#h31").show();
                });
                
                $("#h32").mouseenter(function(){
                    alert("mouseenter() 작동");
                });
                
                $("#h33").mouseleave(function(){
                    alert("mouseleave() 작동");
                });
                
                $("#h34").mousedown(function(){
                    alert("mousedown() 작동")
                });
                
                $("#h35").mouseup(function(){
                    alert("mouseup() 작동")
                });
                
                $("p").on({
                    mouseup: function(){
                        $(this).show();
                    },
                    mousedown: function(){
                        $(this).hide();
                    }
                });
        });    
    </script>
</head>
<body>
    <h3 id="h31">Pleasure to meet you!</h3>
    
    <button id="b1">버튼 클릭 시 문장 표시 X</button>
    <button id="b2">버튼 더블 클릭 시 문장 표시 O</button>
    <hr>    
    
    <h3 id="h32">마우스를 올리면 메시지 출력</h3>
    <h3 id="h33">마우스를 올리고 내리면 메시지 출력</h3>
    <hr>
    
    <h3 id="h34">마우스를 올리고 마우스 왼쪽, 중앙, 오른쪽을 누르면 메시지 출력</h3>
    <h3 id="h35">마우스를 올리고 마우스 왼쪽, 중앙, 오른쪽을 누르고 놓으면 메시지 출력</h3>
    
    <p>테스트용 문단</p>
    
</body>
</html>
```
