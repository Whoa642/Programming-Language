<h2>document 객체의 속성을 확인, 변경하고 기능을 사용해서 페이지의 배경 색과 글자 색을 바꾸는 코드</h2>

```html
<head>
<meta charset="UTF-8">
<title>Document 객체 정보</title>
<script type="text/javascript">
  // func1()
  function func1(){
      alert("document 속성");
      console.log(window.document);
      alert("title:" + document.title);
      alert("locatio:" + document.location);
  }
 
  // func2()
  // "속성 변경" 버튼 클릭 시 배경색을 yellow
  function func2()
      document.bgColor = "yellow";
 
  //func3()
  function func3(){
      // 배경색, 글자색 둘 다 무작위로 변경
      var colors =['red', 'green', 'blue', 'yellow', 'orange'];
      
      // [0,5] 사이의 정수 난수
      var bg = Math.floor(Math.random() * 6);
      var ft = Math.floor(Math.random() * 6);
      
      // 배경색 변경
      document.bgColor = colors[bg];
      // 글자색 변경
      document.fgColor = colors[ft];
  }
 
  // func4()
  function func4(color)
      document.bgColor = color;
 
</script>
</head>
<body>
 
  <input type="button" value="속성 확인" onclick="func1();">
  <input type="button" value="속성 변경" onclick="func2();">
  <input type="button" value="무작위 속성 변경" onclick="func3();">
  
  <hr>
  <!-- 라디오 버튼으로 색으로 배경색 변경하기 -->
  <input type="radio" name="col" onclick="func4('pink');"> PINK
  <input type="radio" name="col" onclick="func4('orange');"> ORANGE
  <input type="radio" name="col" onclick="func4('purple');"> PURPLE
  
</body>
```
<hr>

이미지는 배열의 형태로 저장되기 때문에 images[첨자] or img 태그의 name을 사용할 수 있다.

<h2>이미지 버튼의 정보를 출력하고 속성을 변경하는 코드</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
 
  // (window).document.images[첨자].속성
  // (window).document.images[첨자].기능()
  // (window).document.img 태그의 name.속성
  // (window).document.img 태그의 name.기능()
  
  function func1(){
      alert("이름:" + window.document.images[0].name);
      alert("파일 주소:" + document.img1.src);
      alert("테두리:" + document.img1.border);
      alert("높이:" + document.images[0].height);
      alert("너비:" + document.images[0].width);  
  }
   
  function func2(){
      // 두 번째 이미지의 테두리 생성
      window.document.images[1].border = 5;
      // img1 그림의 가로길이 -> 300
      document.img1.width = 300;
      // images[2] 세로길이 -> 200
      document.images[2].height = 200;
      // 두 번째 이미지의 그림 -> 1.jpg
      document.img2.src = "1.jpg";
  }
 
</script>
</head>
 
<body>
 
    <img src="1.jpg" name="img1">
    <img src="2.jpg" name="img2">
    <img src="3.jpg" name="img3">
 
    <input type="button" value="이미지 버튼 정보" onclick="func1();">
    <input type="button" value="이미지 속성 변경" onclick="func2();">
 
</body>
```

<hr>

<h2> 마우스를 올리면 현재 이미지를 제외한 다른 이미지로 변경되고 내리면 원래대로 돌아오는 코드</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
 
  function func3(imgName){
      if(imgName == "img1"){
          //document.img1.src="2.jpg"; 둘 중 하나
          document.img1.src = "3.jpg";
      }
      if(imgName == 'img2'){
          document.img2.src = "1.jpg";
          //document.img2.src="3.jpg"; 둘 중 하나
      }
      if(imgName == "img3"){
          //document.img3.src="1.jpg"; 둘 중 하나
          document.img3.src = "2.jpg";
      }
  }
  
  function func4(imgName){
      if(imgName == "img1")
          document.img1.src = "1.jpg";
      
      if(imgName == 'img2')
          document.img2.src = "2.jpg";
      
      if(imgName == "img3")
          document.img3.src = "3.jpg";
  }
  
</script>
</head>
 
<body>
 
    <img src="1.jpg" name="img1" onmouseover="func3('img1');" onmouseout="func4('img1');">  
    <img src="2.jpg" name="img2" onmouseover="func3('img2');" onmouseout="func4('img2');">
    <img src="3.jpg" name="img3" onmouseover="func3('img3');" onmouseout="func4('img3');">
    
    <input type="button" value="이미지 버튼 정보" onclick="func1();">
    <input type="button" value="이미지 속성 변경" onclick="func2();">
 
</body>
```
