<h2>버튼을 눌렀을 때 모든 항목이 입력 되어있으면 페이지를 전송</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
    
    function func2(){
        var lenOfID = document.fr.userID.value.length;
        var lenOfPW = document.fr.userPW.value.length;
        var lenOfJu1 = document.fr.ju1.value.length; 
        var lenOfJu2 = document.fr.ju2.value.length; 
        var lenOfMsg = document.fr.msg.value.length
        
        if(lenOfID == 0){
            alert("ID 입력하세요.");
            document.fr.userID.focus(); // 주어진 항목을 강조한다.
            return;
        }
        if(lenOfPW == 0){
            alert("PW 입력하세요.");
            document.fr.userPW.focus();
            return;
        }
        if(lenOfJu1 == 0){
            alert("주민 번호 앞자리 입력하세요.");
            document.fr.ju1.focus();
            return;
        }
        if(lenOfJu2 == 0){
            alert("주민 번호 뒷자리 입력하세요.");
            document.fr.ju2.focus();
            return;
        }
        if(lenOfMsg == 0){
            alert("메세지 입력하세요.");
            document.fr.msg.focus();
            return;
        }
        document.fr.submit(); // 페이지를 전송한다.
    }    
    
    </script>
</head>
<body>
    
    <fieldset>
        <legend>정보 입력 form</legend>
        <form action="test.jsp" name="fr">
            <label>아이디: </label><input type="text" name="userID" value=""> <br>
            비밀번호:<input type="password" name="userPW"> <br>
            주민번호:<input type="text" name="ju1">
                    -
                    <input type="text" name="ju2"> <br>
            하고 싶은 말:<textarea rows="5" cols="100" name="msg"></textarea> <br> <!-- 큰 글상자를 만든다. -->
            
            <hr>
            <input type="submit" value="정보 입력"> 
            <input type="reset" value="정보 초기화">
            
            <hr>
            <input type="button" value="페이지 전송" onclick="func2();">
        
        </form>
    </fieldset>
</body>
```

<h2>submit()을 사용하지 않고 버튼을 눌렀을 때 모든 항목이 입력 되어있으면 페이지를 전송</h2>

<b>반환값이 없거나 true를 반환하면 submit 이벤트가 발생하지만 false를 반환하면 이벤트가 발생하지 않는다.</b>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
    
    function func3(){
        var lenOfID = document.fr.userID.value.length;
        var lenOfPW = document.fr.userPW.value.length;
        var lenOfJu1 = document.fr.ju1.value.length;
        var lenOfJu2 = document.fr.ju2.value.length;
        var lenOfMsg = document.fr.msg.value.length;
        
        if(lenOfID == 0){
            alert("ID 입력하세요.");
            document.fr.userID.focus();
            return false;
        }
        if(lenOfPW == 0){
            alert("PW 입력하세요.");
            document.fr.userPW.focus();
            return false;
        }
        if(lenOfJu1 == 0){
            alert('주민 번호 앞자리 입력하세요.');
            document.fr.ju1.focus();
            return false;
        }
        if(lenOfJu2 == 0){
            alert('주민 번호 뒷자리 입력하세요.');
            document.fr.ju2.focus();
            return false;
        }
        if(lenOfMsg == 0){
            alert("메세지 입력하세요.");
            document.fr.msg.focus();
            return false;
        }
        // submit 이벤트 실행
    }
    
    </script>
</head>
<body>
    
    <fieldset>
        <legend>정보 입력 form</legend>
        <form action="test.jsp" name="fr" onsubmit="return func3();"> // 함수를 반환한다.
            <label>아이디: </label><input type="text" name="userID" value=""> <br>
            비밀번호:<input type="password" name="userPW"> <br>
            주민번호:<input type="text" name="ju1">
                    -
                    <input type="text" name="ju2"> <br>
            하고 싶은 말:<textarea rows="5" cols="100" name="msg"></textarea> <br> 
            
            <hr>
            <input type="submit" value="정보 입력"> 
            <input type="reset" value="정보 초기화">
        
        </form>
    </fieldset>
</body>
```
