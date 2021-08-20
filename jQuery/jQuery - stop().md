<h1>stop()</h1>


애니메이션 또는 효과가 완료되기 전에 중단할 수 있다. (<b>모든 제이쿼리 효과 메서드, 슬라이딩, 페이딩, 커스텀 애니메이션에 작동한다.</b>) 

<ol>
  <li>$(선택자).stop(stopAll, goToEnd)</li>
  <li>stopAll은 옵션으로 <b>애니메이션 큐가 정리되어야 하는지 명시</b>하며 기본값은 false으로 이는 활성화된 애니메이션만 정지</li>
  <li>goToEnd는 옵션으로 <b>현재 애니메이션을 즉시 완성해야 하는지 명시</b>하며 기본값은 false</li>
  <li><b>기본적으로 stop() 메서드는 주어진 요소에 행해지는 현재 애니메이션을 죽인다.</b> </li>
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
        #sign, #board {
          padding: 10px;
          font-size: 20px;
          text-align: center;
          background-color: #48C9B0;
          color: white;
          border: solid 1px #666;
          border-radius: 3px;
        }
        
        #board {
          padding: 100px;
          display: none;
        }
    </style>
    
    <!--jQuery 라이브러리 추가-->
    <script src="../jql/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            $("#sign").mouseover(function(){
                $("#board").slideDown(3000);
            });
            
            $("button").click(function(){
                $("#board").stop();
            });
        });        
    </script>
</head>
<body>
    <button>현재 작업 정지</button>
    <p id="sign">글을 보려면 마우스를 올리세요.</p>
    <p id="board">별 다른 내용은 없습니다.</p>
</body>
</html>
```
