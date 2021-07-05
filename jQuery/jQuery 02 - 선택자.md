```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // 선택자
            // $(대상 정보).메서드();
            
            // * - 전체 요소
            $('*').css('color','orange');
            
            // '태그명' - 태그 요소
            $('h1').css('color','red');
            $('h2').css('color','blue');
            
            // #아이디 - 아이디 요소
            $('#title1').css('color','green');
            // .클래스명 - 클래스 요소
            $('.title2').css('color','#A566FF');
            
            // 속성 탐색 선택자
            // 태그[속성=값]
            // 태그[속성^=값]: 속성의 값 중에서 값으로 시작하는 대상을 구분
            // 태그[속성$=값]: 속성의 값 중에서 값으로 끝나는 대상을 구분
            $('input[type=text]').css('color','green');
            $('input[type=password]').css('color','red');
            
            $('input[type^=t]').css('color','black');
            $('input[type=text]').val('홍길동');
            
            var tmp = $('input[type=text]').val();
            alert("tmp: "+tmp);
            
            // 위치를 탐색 선택자
            // 태그:odd 홀수 // 태그:even 짝수   
            // 태그:first 처음 // 태그:last 마지막
            
            $('tr:odd').css('background','yellow');
            $('tr:even').css('background','green');
            
            $('tr:first').css('background','red');
            $('tr:last').css('background','blue');
                
        });
    </script>
</head>
<body>
    <h1>WebContent/jq/test2.jsp</h1>
    
    <h2 id="title1">제목 1</h2>
    <h2 class="title2">제목 2</h2>
        
    내용<br>
    
    <hr>
    
    아이디:<input type="text" name=""><br>
    비밀번호:<input type="password" name=""><br>
    
    <hr>
    
    <table border="1">
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
    </table>
</body>
```
