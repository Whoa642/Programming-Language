```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.min.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // 요소의 앞뒤에 해당 요소를 추가하는 동작
            // apppend():뒤에 추가
            // prepend():앞에 추가
            
            $('body').append('뒤에 추가하기');
            $('body').prepend('앞 추가하기');        
            
            $('div').append(function(idx){
                return " "+idx;
            });
            
            //$('tr').append('<tr><td>홍길동</td><td>010-1234-5678</td></tr>'); -> 올바른 방법 X
            $('#tel').append('<tr><td>홍길동</td><td>010-1234-5678</td></tr>'); 
            
            // 배열
            var data = [
                {name:'홍길동',region:'부산'},    
                {name:'김길동',region:'제주'},
                {name:'박길동',region:'서울'},
            ];
            
            console.log(data[0]);
            //$('#region').append('<tr><td>'+data[0].name+'</td><td>'+data[0].region+'</td></tr>');
            
            // each(): 선택한 여러 개의 요소를 각각 순차적으로 접근할 때 사용하는 메서드
            // $(요소 선택자).each(function(){});
            // $.each(요소 선택자,function(){});
            $.each(data,function(idx,item){
                //alert(idx+" // "+item.name);
                $('#region').append(function(){
                    return '<tr><td>'+item.name+'</td><td>'+item.region+'</td></tr>';
                });
            });
            
            // 배열의 값(이름, 지역)을 div안에 추가
        /*     $.each(data,function(idx,item){
                $('div').append(item.name+"//"+item.region);
            });
             */
             
            $('div').append(function(idx){
                var item = data[idx];
                return " "+item.name+" // "+item.region;
            });
        });
    </script>
</head>
<body>
    <h1>WebContent/jq/test5.jsp</h1>
    
    1<br>
    2<br>
    3<br>
    <hr>
    
    <div>제목</div>
    <div>제목</div>
    <div>제목</div>
    <hr>
    
    <table border="1" id="tel">
        <tr>
            <td>이름</td>
            <td>전화번호</td>
        </tr>
    </table>
    <hr>
    
    <table border="1" id="region">
        <tr>
            <td>이름</td>
            <td>지역</td>
        </tr>
    </table>
    
</body>
```
