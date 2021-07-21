```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <style type="text/css">
        ul{
            list-style:none;
        }
    </style>
    
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    <script src="../js/jquery.innerfade.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            //$('#news').innerfade('animationtype','slide');
            $('#news').innerfade({
                animationtype: 'fade',
                speed: 'slow',
                type: 'random'
            });
        });
    </script>
</head>
<body>
    <ul id="news"> 
       <li><img src="att.png"></li>
       <li><img src="ggbg.gif"></li>
       <li><img src="km.jpg"></li>
       <li><img src="rt_arch.jpg"></li>
       <li><img src="tuev.jpg"></li>
       <li><img src="whizzkids.jpg"></li>
      </ul>
</body>

```
