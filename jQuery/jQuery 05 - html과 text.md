```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.min.js"></script>
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(function(){
            // html() / text() - 출력된 요소의 값을 가져오는 동작
            
            // html: 해당 요소의 해당하는 값 1개 가져오기
            var htValue = $('h2').html();
            alert(htValue);
            // text: 해당 요소의 해당하는 값을 모두 가져오기
            var txValue = $('h2').text();
            alert(txValue);
                    
            // h2 태그의 값을 변경
            $('h2').html('Hello');
            $('h2').html('jQuery');
            
            // div 태그의 값을 변경 ('<h3>html() 함수 호출</h3>', '<h3>text() 함수 호출</h3>')
            // $('div').html('<h3>html() 함수 호출</h3>');
            // => 전달된 값을 요소를 적용해서 처리(태그로 표현 가능)
            
            // $('div').text('<h3>text() 함수 호출</h3>');
            // => 전달된 값을 새로운 텍스트로 변경 (태그로 표현 불가능)
            
            // div의 값을 [ 기존값 **** ] 형태로 변경 후 출력
            /* $('div').html(function(idx,ohtml){
                return "[ "+ohtml+"**"+idx+"** ]";
            }); */
            
            $('div').text(function(idx,ohtml){
                return "[ "+ohtml+"**"+idx+"** ]";
            });
        });
    </script>
</head>
<body>
    <h1>WebContent/jq/test5.jsp</h1>
    
    <h2>head-0</h2>
    <h2>head-1</h2>
    <h2>head-2</h2>
 
    <hr>
    <div>00</div>
    <div>11</div>
    <div>22</div>
    
</body>
```
