## 로그인 처리 

1. prompt를 사용해서 사용자로부터 아이디와 비밀번호를 입력 받는다.   
2. 입력된 아이디가 저장된 아이디와 같은지 확인한다.   
3. 같을 경우 회원이기 때문에 비밀번호를 확인한다.    
&nbsp;&nbsp;&nbsp;&nbsp;3.1. 비밀번호가 일치하면 로그인이 성공적으로 이루어진다.      
&nbsp;&nbsp;&nbsp;&nbsp;3.2. 비밀번호가 일치하지 않으면 오류 메세지를 출력한다.     
4. 아이디가 일치하지 않을 경우 회원이 아니기 때문에 오류 메세지를 출력한다.   
```javascript
var ID = "admin";
var PW = "1234";
   
var inputID = prompt("아이디를 입력하시오.");
var inputPW = prompt("비밀번호를 입력하시오.");
   
if(ID == inputID){
    if(PW == inputPW){
        alert(inputID+"님 로그인이 되었습니다.");
    }else{
        alert("비밀번호가 일치하지 않습니다.");
    }
}else{
       alert("아이디가 없습니다.");
}
```

## 회원 탈퇴 확인

1. confirm으로 사용자에게 회원 탈퇴 여부를 묻는다.    
2. 확인(true)이면 확인 메세지를 출력한다.    
3. 취소(false)이면 취소 메세지를 출력한다.    
```javascript
var result = confirm("회원 탈퇴 하시겠습니까?");
    
if(result)
   document.write("정상적으로 탈퇴했습니다.");
else
   document.write("탈퇴를 취소했습니다.");
```

## 포털 사이트로 이동

1. prompt로 사용자로부터 포털 사이트의 이름을 입력받는다.
2. 주어진 포털 사이트의 주소를 저장할 변수를 선언한다.
3. switch-case문을 사용하는데 사용자가 한글뿐만 아니라 영어로 입력할 수 있기 때문에 3개의 case를 묶어서 처리한다.
4. naver,daum,nate,google가 아닐 경우 default에 예외를 처리한다.
5. 만약 변수에 주소가 저장되어 있으면 location.href에 대입한다.
```javascript
 var site = prompt("이동할 포털 사이트의 이름을 입력하시오. ");
 var dest = "";
   
switch(site){
   case "네이버":
   case "NAVER":
   case "naver":
       alert("네이버 페이지로 이동합니다.");
       dest = "www.naver.com";       
       break;
   case "다음":
   case "DAUM":
   case "daum":
       alert("다음 페이지로 이동합니다.");
       dest = "www.daum.net";
       break;
   case "네이트":
   case "NATE":
   case "nate":
       alert("네이트 페이지로 이동합니다.");
       dest = "www.nate.com";
       break;
   case "구글":
   case "GOOGLE":
   case "google":
       alert("구글 페이지로 이동합니다.");
       dest = "www.google.com";
       break;
   default:
       alert("처리 불가능한 페이지 입니다.");
   }
   
   if(dest)
       location.href = "http://"+dest;   
```

## 숫자 맞추기 게임

1. 프로그램 실행 시 Math.random 함수를 사용해서 임의의 숫자 1개를 생성하고 사용자가 숫자를 입력한다.
2. 입력값이 정답보다 작으면 작다는 메세지를 출력한다.
3. 입력값이 정답보다 크면 크다는 메세지를 출력한다.
4. 입력값이 정답과 같으면 게임을 종료한다.
5. 사용자가 시도한 횟수를 출력한다.
```javascript
var num = Math.floor(Math.random() * 100) + 1;
var input = 0;
var cnt = 0;
 
while(true){
    input = prompt("정답을 입력하세요");
    cnt++;
       
    if(num > input){
        alert("입력한 값이 작습니다.");            
    }else if(num < input){
        alert("입력한 값이 큽니다.");
    }else{ 
        alert("도전횟수:"+cnt+"회");
        break;
    }
};
```
