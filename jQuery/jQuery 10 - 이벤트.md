```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            
            // a 링크 클릭 시 배경색을 설정
            $('a').click(function(){
                // alert(event);
                $(this).css('background-color','blue');
                
                // 이벤트 처리 X
                // event.preventDefault();    // 페이지 이동 X (하이퍼링크)
                // console.log(event);                
                return;
            });
            
            // h2 태그 클릭 시 + 기호 추가
            $('h2').click(function(){
                $(this).html(function(idx,html){
                        return html+' +';
                });
                // return false; X
                $(this).unbind(); // 이벤트 종료
            });
            
        });
    </script>
</head>
<body>
    <h1>WebContent/jq2/test2.jsp</h1>
    
    <h1><a href="http://www.naver.com">네이버 페이지</a></h1>
    
    <h2>이벤트 시작/끝</h2> 
</body>
```
