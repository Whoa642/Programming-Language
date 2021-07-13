```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // 이벤트: 페이지에서 방문자가 수행하는 모든 행동
            // bind(): 이벤트 등록 함수
            // $(요소).bind(이벤트,실행코드);        
        
            $('#btn2').bind('click',function(){
                alert('클릭 이벤트 발생(jQuery)')    
            });
            
            $('#btn2').click(function(){
                alert('클릭 이벤트 발생(click)');                
            });
            
            // h2 태그 선택 시(클릭) 
            $('h2').click(function(){
                // + 기호 추가 (text(),html())
                //return '+';
                $(this).html(function(idx,ohtml){
                    return ohtml+' +';                    
                });
            }); 
            
            // 오류
             /* $(this).click(function(){
                // + 기호 추가 (text(),html())
                //return '+';
                $(this).html(function(idx,ohtml){
                    return ohtml+' +';                    
                });
            });  */
            
            /* $('img').mouseover(function(){
                $(this).attr('src','2.jpg');
            });
            
            $('img').mouseout(function(){
                $(this).attr('src','1.jpg');
            }); */
            
            // 사슬 기법
            $('img').mouseover(function(){
                $(this).attr('src','2.jpg');
            }).mouseout(function(){
                $(this).attr('src','1.jpg');
            });
            
        });
    </script>
</head>
<body>
    <h1>WebContent/jq2/test1.jsp</h1>
    
    <input type="button" value="클릭 이벤트" onclick="alert('클릭 js');">
    <input type="button" id="btn2" value="클릭 이벤트2">
    
    <hr>
    <h1>h2 태그 클릭 시 마다 "+" 기호 추가</h1>
    <h2>head-0</h2>
    <h2>head-1</h2>
    <h2>head-2</h2>
    
    <hr>
    <h1>img에 마우스 올렸을 때 2번 그림, 내렸을 때 1번 그림</h1>
    <img src="1.jpg">
    
</body>
```
