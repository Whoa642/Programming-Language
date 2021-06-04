<h2>간단한 회원 가입 페이지</h2>

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
    // submit 이벤트 발생 시 다음을 처리한다.
    // 1) 값 입력, 선택 여부를 확인한다.
    // 2) 아이디의 길이가 5~10자리인지 확인한다.
    // 3) 비밀번호를 입력하면 다시 한 번 확인한다.
    // 4) 주민번호 앞자리 6자리, 뒷자리 7자리인지 확인한다.
    // 5) 모든 이벤트 처리는 동작을 만족하지 않는 경우 메시지를 출력하고 다음 동작을 실행하지 않는다.
    function process(){
        var lenOfID = document.fr.userID.value.length;
        var lenOfPW = document.fr.userPW.value.length;
        var lenOfCPW = document.fr.userCPW.value.length;
        var lenOfNum1 = document.fr.num1.value.length;
        var lenOfNum2 = document.fr.num2.value.length;
        var lenOfName = document.fr.name.value.length;
        var lenOfMsg = document.fr.msg.value.length;
        var PW = document.fr.userPW.value;
        var CPW = document.fr.userCPW.value;
        
        if(lenOfID > 10 || lenOfID < 5){
            alert("아이디를 입력하세요.(5-10자리)");
            document.fr.userID.focus();
            return false;
        }
        if(lenOfPW == 0){
            alert("비밀번호를 입력하세요.");
            document.fr.userPW.focus();
            return false;
        }
        if(lenOfCPW == 0){
            alert("비밀번호 확인이 필요합니다.\n비밀번호를 다시 입력하세요.");
            document.fr.userCPW.focus();
            return false;
        }
        if(PW != CPW){
            alert("비밀번호가 다릅니다.");
            return false;
        }
        
        if(lenOfName == 0){
            alert("이름을 입력하세요.");
            document.fr.name.focus();
            return false;
        }
        if(lenOfNum1 != 6){
            alert('주민번호 앞자리 입력하세요.(6자리)');
            document.fr.num1.focus();
            return false;
        }
        if(lenOfNum2 != 7){
            alert('주민번호 뒷자리 입력하세요.(7자리)');
            document.fr.num2.focus();
            return false;
        }
        
        
        var rd1 = document.fr.gender[0];
        var rd2 = document.fr.gender[1];
        
        if(!rd1.checked && !rd2.checked){
            alert('성별을 선택하세요.');
            return false;
        }
        
        var check1 = document.fr.hobby[0];
        var check2 = document.fr.hobby[1];
        var check3 = document.fr.hobby[2];
        var check4 = document.fr.hobby[3];
        
        if(!check1.checked && !check2.checked && !check3.checked && !check4.checked){
            alert('적어도 한 개의 취미를 선택하세요.');
            return false;
        }
        
        var opt = document.fr.subject.options[0];
        
        if(opt.selected){
            alert('적어도 한 개의 과목을 선택하세요.');
            document.fr.subject.focus();
            return false;
        }
        
        if(lenOfMsg == 0){
            alert("메세지를 입력하세요.");
            document.fr.msg.focus();
            return false;
        }
    }
    
    </script>
</head>
<body>
    <h1>WebContent/js3/test6.html</h1>
    
    <h2>회원 가입 페이지</h2>
    
    
    <fieldset>
        <form action="next.jsp" method="post" name="fr" onsubmit="return process();">
            <!--  
                정보 입력 - text
                비밀번호 - password
                성별 - radio
                취미 - checkbox
                버튼 - submit,reset
            -->
        
            아이디:<input type="text" name="userID"><br>
            비밀번호:<input type="password" name="userPW"><br>
            비밀번호 확인:<input type="password" name="userCPW"><br>
            이름:<input type="text" name="name"><br>
            주민번호:<input type="text" name="num1"> 
                    - 
                   <input type="password" name="num2"><br>
             
            성별:<input type="radio" name="gender" value="male"> 남자
                <input type="radio" name="gender" value="female"> 여자<br>
                
            취미:<input type="checkbox" name="hobby" value="게임"> 게임
                <input type="checkbox" name="hobby" value="영화"> 영화
                <input type="checkbox" name="hobby" value="운동"> 운동
                <input type="checkbox" name="hobby" value="독서"> 독서
                <br>
            좋아하는 과목:<select name="subject">
                        <option value="">선택하세요.</option>
                        <option value="">자바</option>
                        <option value="">자바스크립트</option>
                        <option value="">웹프로그래밍WEB</option>
                        <option value="">웹프로그래밍JSP</option>
                        <option value="">데이터베이스</option>
                      </select><br>
            메시지:<textarea rows="5" cols="100" name="msg"></textarea>
            <hr>
            
            <input type="submit" value="입력"> 
            <input type="reset" value="초기화">
            
        </form>
    </fieldset>
</body>
</html>
```
