```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.min.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(function(){
            // 요소의 속성을 사용
            $('h2').css('color','blue');
            
            // 요소의 속성값을 가져오는 기능
            var c = $('h2').css('color');
            //alert(c);
            
            // h2 요소의 글자색 속성값을 red로 변경
            $('h2').css('color','red'); // 4,5번
            
            // 요소의 설정값을 변경(배열 사용)
            var color = ['red','orange','yellow','green'];
            
            // $('h2').css('color',color[1]);
            $('h2').css('color',function(index){
                //alert(index);
                return color[index];
            });
            
            // 속성 여러 개 적용 시 {} 사용 (글자색, 배경색 변경)
            $('h2').css({
                color: 'green',
                backgroundColor: 'yellow'
            });
            
            // 속성을 여러 개 적용(글자색, 배경색) + 배경색을 배열을 사용해서 처리
            $('h2').css({
                color: 'black',
                backgroundColor: function(index){
                    return color[index]
                }
            })
        });
    </script>
</head>
<body>
    <h1>WebContent/jq/test3.jsp</h1>
    
    <h2>head-0</h2>
    <h2>head-1</h2>
    <h2>head-2</h2>
    <h2>head-3</h2>
    <h2>head-4</h2>
    <h2>head-5</h2>
</body>
```
