<h1>콜백 함수</h1>

콜백 함수는 현재 효과가 100% 끝난 다음에 실행된다.

<h1>체이닝</h1>

제이쿼리를 사용하면 여러 개의 액션과 메서드를 묶을 수 있으며 한 문장에 같은 요소에 행해지는 여러 개의 메서드를 실행할 수 있다.

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
            $("#p1").mouseover(function(){
                $(this).fadeTo("slow", 0.6, function(){
                    alert("fadeTo 작동 완료");
                });
            });
            
            $("button").click(function(){
                $("#p2").slideUp(3000).slideDown(3000);
            });
        });        
    </script>
</head>
<body>
    <p id="p1">마우스를 올리면 흐리해집니다.</p>
    
    <button>버튼을 누르면 올라갔다 내려갑니다.</button>
    <p id="p2">체이닝 기법</p> 
</body>
</html>
```
