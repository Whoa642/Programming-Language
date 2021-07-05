<b>jQuery</b>는 자바스크립트를 빠르고 쉽게 사용하기 위해서 만들어진 라이브러리이다. 

```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            alert('제이쿼리 실행1');
        });
        
        $(function(){ // 간단해서 가장 많이 사용
            alert('제이쿼리 실행2');
        });
        
        // $는 jQuery와 동일
        jQuery(document).ready(function(){
            alert('제이쿼리 실행3');
        });
        
        jQuery(function(){
            alert("제이쿼리 실행4");
        })
    </script>
 
</head>
<body>
    <h1>WebContent/jq/test1.jsp</h1>
</body>
```
