<h2>라디오 버튼과 체크 박스의 속성 확인</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
        // window-document-form-체크 박스 이름[0]
        // window-document-form-라디오 버튼 이름[0]
        
        function func1(){
            alert('라디오 버튼 이름:' + window.document.forms[0].gender[0].name);
            alert('체크 박스 이름:' + window.document.fr.hobby[0].name);
            
            // (라디오 버튼 / 체크 박스) 타입, 값
            var hobby0 = window.document.fr.hobby[0]; // 변수에 속성을 저장한다.
            alert('체크 박스 타입:' + hobby0.type);
            alert('체크 박스 값:' + hobby0.value);
            alert('체크 박스 체크값:' + hobby0.checked);
            // checked 속성 => 버튼의 체크 여부에 따라서 true/false 출력
            
            // hobby0.focus();
            document.fr.gender[0].click();
            document.fr.hobby[1].click();
        }
        
    </script>
</head>
<body>
    <fieldset>
        <!-- 전달되는 데이터(매개변수), input 태그의 name 속성은 매개변수의 이름 -->
    
        <form action="a.jsp" method="get" name="fr">
        아이디: <input type="text" name="id"> <br>
 
        <hr>                                
        성별: <input type="radio" name="gender" value="남자"> 남자 
              <input type="radio" name="gender" value="여자"> 여자 <br>
 
        취미: <input type="checkbox" name="hobby" value="독서"> 독서
              <input type="checkbox" name="hobby" value="운동"> 운동
              <input type="checkbox" name="hobby" value="영화"> 영화
    
        <input type="button" value="속성 확인" onclick="func1();">
    
        </form>
    </fieldset>
</body>
```

<h2>라디오 버튼이 체크되어 있을 경우만 페이지를 이동</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">

    function fun2(){
        if(!document.fr.gender[0].checked && !document.fr.gender[1].checked){
            alert("성별을 선택하세요.");
            return;
        }
 
        document.fr.submit();
    }
</script>
</head>
 
<body>
    <fieldset>
        <form action="a.jsp" method="get" name="fr">
        
         아이디 : <input type="text" name="id" ><br>
         <hr>                               
         성별 : <input type="radio" name="gender" value="남자"  > 남자 
              <input type="radio" name="gender" value="여자"  > 여자 <br>
         취미 : <input type="checkbox" name="hobby" value="게임" > 게임  
              <input type="checkbox" name="hobby" value="운동" > 운동
              <input type="checkbox" name="hobby" value="영화" > 영화
         <hr>   
         <input type="submit" value="전달하기">
         <input type="reset" value="초기화하기">
         <hr>
         
         <input type="button" value="속성 체크 여부 판단하기" onclick="fun2();">
         
        </form>
    </fieldset>
 
</body>
```

<h2>submit 이벤트 발생 시 체크 박스가 하나 이상 선택되어 있을 경우만 페이지를 이동</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
    function fun3(){        
        if(document.fr.hobby[0].checked == false 
                && document.fr.hobby[1].checked == false 
                && document.fr.hobby[2].checked == false ){
            
            alert("취미를 선택하세요.");
            return false;
        }
    }
 
</script>
</head>
 
<body>
    <fieldset>
        <form action="a.jsp" method="get" name="fr" onsubmit="return fun3();">
        
         아이디 : <input type="text" name="id" ><br>
         <hr>                               
         성별 : <input type="radio" name="gender" value="남자"  > 남자 
              <input type="radio" name="gender" value="여자"  > 여자 <br>
         취미 : <input type="checkbox" name="hobby" value="게임" > 게임  
              <input type="checkbox" name="hobby" value="운동" > 운동
              <input type="checkbox" name="hobby" value="영화" > 영화
         <hr>   
         <input type="submit" value="전달하기">
         <input type="reset" value="초기화하기">
         <hr>
         
         <input type="button" value="속성 체크 여부 판단하기" onclick="fun2();">
         
        </form>
    </fieldset>
</body>
```
