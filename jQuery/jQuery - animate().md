<h1>animate()</h1>

커스텀 애니메이션을 생성한다.

<ol>
  <li>$(선택자).animate({매개변수}, 속도, 콜백 함수)</li>
  <li>매개변수는 <b>CSS 속성</b>을 정의</li>
  <li>속도는 '<b>slow</b>', '<b>fast</b>' 또는 <b>밀리초</b></li>
  <li><b>콜백 함수</b>는 animate() 다음에 실행</li>
  <li><b>모든 속성 이름은 반드시 낙타 표기법을 따른다.</b></li>
</ol>

<b><i>기본적으로 모든 HTML 요소는 고정 위치를 가지며 움직일 수 없다. 위치를 조작하려면 요소의 CSS 속성은 relative, fixed, absolute 중 하나로 설정해야 한다.</i></b>

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
            // 여러 속성을 조작
            $("#p1").mouseover(function(){
                $(this).animate({
                      left: '500px',
                      opacity: '0.7'        
                }, 5000);
            });
            
            // 현재 요소의 값에 상대적인 값을 정의
            $("#p2").mouseup(function(){
                $(this).animate({
                    left: '+=50px',
                    height: '+=10px',
                    width: '+=10px'
                });
            })
            
            // 'show', 'hide', 'toggle' 사용 가능
            $("#p3").mousedown(function(){
                $(this).animate({
                    height: 'hide'
                });            
            });
            
            // 큐 기능(여러 개의 animate 메서드 사용 시)
            $("button").click(function(){
                var d = $("#p4");
                
                d.animate({left: '500px'}, 3000);
                d.animate({bottom: '500px'}, 3000);
                d.animate({top: '500px'}, 3000);
                d.animate({left: '-=500px'}, 3000);
            });
        });        
    </script>
</head>
<body>
    <p id="p1" style="background:#2ECC71;height:30px;width:30px;position:absolute;"></p>
    <br><br><br><br>
 
    <p id="p2" style="background:#EC7063;height:40px;width:40px;position:absolute;"></p>
    <br><br><br><br>    
        
    <p id="p3" style="background:#76448A ;height:50px;width:50px;position:absolute;"></p>
    <br><br><br><br>    
        
    <p id="p4" style="background:#2980B9 ;height:100px;width:100px;position:absolute;"></p>
    <br><br><br><br>
        <br><br><br><br>    
    <button>버튼을 누르세요.</button>
</body>
</html>
```
