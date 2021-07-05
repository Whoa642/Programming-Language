```jsp
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
 
    <script src="../js/jquery-3.6.0.min.js"></script>
    <script type="text/javascript">
          $(document).ready(function(){
          // attr(): 태그의 속성값을 제어하는 함수
      
          // img 태그의 속성 src 정보를 출력(alert)
          var mySrc =  $('img').attr('src');
          alert(mySrc);
      
          // img 태그의 속성을 변경 border 속성 값을 5로 지정
          $('img').attr('border',5);
      
          // img 태그의 border의 두께를 각각 5,10,15 지정
          $('img').attr('border',function(index){
          //alert(index);
          return (index+1)*5;
          });
      
          // img태그의 속성 'border-5','width-150','height-100'
          $('img').attr({
              border: 5,
              width: 150,
              height: 100          
          });
      
      // img 속성변경, 가로 길이만 100,200,300 나머지 옵션은 동일
      $('img').attr({
          border: 5,
          width : function(index){
              return (index+1)*100;
          },
          height: 100
      });  
  });
    </script>
 
</head>
<body>
    <h1>WebContent/jq/test4.jsp</h1>
    
    <img src="1.jpg">
    <img src="2.jpg">
    <img src="3.jpg">
</body>
```
