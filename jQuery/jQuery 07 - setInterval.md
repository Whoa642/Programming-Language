```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.min.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // setInterval(함수,시간): 일정 시간 마다 특정 함수를 반복
             var auto = setInterval(function(){
                $('body').append($('img').first());
            },2000);
        });
        
        // clearInterval(객체 정보):구간 객체 정보 초기화
        clearInterval(auto);
    </script>
    
 
</head>
<body>
    <h1>WebContent/jq/test7.jsp</h1>
    
    <img src="1.jpg">
    <img src="2.jpg">
    <img src="3.jpg">
</body>
```
