```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(function(){
            
            // textarea에 키보드 입력 시 글자수를 세서 출력
            $('textarea').keyup(function(){
                var t = $(this).val();
                
                // h3 태그의 값 수정
                $('h3').html(200-t.length);
                
                // 입력된 글자수가 200자 보다 클 경우 글자수의 색상을 red로 변경
                // 200자 보다 작으면 black
                var ret = 200-t.length;
                
                if(ret < 0){
                    // 200자 보다 작다.
                    $('h3').css('color','red');
                }else{
                    $('h3').css('color','black');
                }
                    
            }); // keyup
            
            // 유효성 확인
            $('#fr').submit(function(){
                if($('#id').val() == ""){
                    alert('아이디 입력하세요.');
                    $('#id').focus(); // 제이쿼리
                    // document.myfm.id.focus(); 자바스크립트
                    return false;
                }
            });
            
        }); // ready
    </script>
</head>
<body>
    <h1>WebContent/jq2/test3.jsp</h1>
    
    <form action="#" name="myfm" id="fr">
        아이디: <input type="text" name="id" id="id"> <br>
        <h2>글자수 200자 제한 입력</h2>
        <h3>200</h3>
        <textarea rows="5" cols="70"></textarea>
        <hr>
        <input type="submit" value="전송">
    </form>
    
</body>
```
