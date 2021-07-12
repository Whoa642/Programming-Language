```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
<style type="text/css">
    h2{
        color:blue;
    }
    
    .high_0 {background:yellow;}
    .high_1 {background:orange;}
    .high_2 {background:purple;}
    .high_3 {background:pink;}
    .high_4 {background:silver;}
</style>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.min.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // addClass(클래스명):해당 요소에 클래스명을 설정
                        
            // h2 태그의 각 요소에 클래스명을 부여
            $('h2').each(function(index){
                // alert(index);
                // this: 방문자가 사이트에 방문해서 이벤트 요소를 발생 시킬 때마다 익명 함수에 있는 실행문이 실행 => 이벤트가 발생한 요소
                $(this).addClass("high_"+index);
            });
        });
        
    </script>
    
</head>
<body>
    <h1>WebContent/jq/test8.jsp</h1>
    
    <h2>head-0</h2>
    <h2>head-1</h2>
    <h2>head-2</h2>
    <h2>head-3</h2>
    <h2>head-4</h2>                        
</body>

```
