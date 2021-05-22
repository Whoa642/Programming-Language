**String** 객체를 저장하는 방식에는 문자열 객체나 문자열 상수를 사용하는 2가지가 존재한다. 
문자열 객체를 저장한 String 객체의 타입은 **object**이고 문자열 상수를 저장한 String 객체의 타입은 **string**이다.
<b>(이 때문에 저장한 문자열의 값이 같아도 '==='를 사용하면 false가 나온다.)</b>

```javascript
// var 참조 변수 = new String(문자열); -> 문자열 객체 
var str1 = new String("Good!");
 
// var 참조 변수 = "문자열"; -> 문자열 상수
var str2 = "Good!";
   
document.write(str1 == str2); // true
document.write(str1 === str2); // false
document.write(typeof str1); // object
document.write(typeof str2); // string
```

String 객체는 문자열의 스타일을 변경하는 함수와 문자열을 처리하는 2가지 종류의 함수를 가진다. 

## 문자열의 스타일을 변경하는 함수
```javascript
// 문자열을 굵게 만든다.
document.write(msg.bold()+"<hr>");
 
// 문자열을 이텔릭체로 설정한다.
document.write(msg.italics()+"<hr>");
 
// 문자열의 색깔을 푸른색으로 설정한다.
document.write(msg.fontcolor("blue")+"<hr>");
 
// 문자열의 문자 크기를 20으로 설정한다.
document.write(msg.fontsize(20)+"<hr>");
 
// 문자열을 모두 대문자로 변경한다.
document.write(msg.toUpperCase()+"<hr>");
 
// 문자열을 모두 소문자로 변경한다.
document.write(msg.toLowerCase()+"<hr>");
 
// 문자열을 대문자,글자크기 15,빨강,굵게 표현하기
document.write(msg.toUpperCase().fontsize(15).fontcolor("red").bold()+"<hr>");
// [. 연산자]를 사용해서 한 번에 여러 개의 함수를 실행할 수 있다. => 체이닝 기법
```

## 문자열을 처리하는 함수

문자열의 문자의 첨자는 C처럼 0부터 시작한다.
```javascript
// charAt(첨자)는 첨자에 해당하는 문자를 반환한다.
document.write(msg.charAt(0));
   
// substring(시작 첨자, 끝 첨자)은 시작 첨자부터 끝 첨자 앞까지 부분 문자열을 반환한다. 
document.write(msg.substring(0, 6)); // 첨자 0부터 5
 
// substring(시작 첨자)와 같이 시작 첨자만 있으면 시작 첨자부터 끝까지 부분 문자열을 반환한다.
document.write(msg.substring(6)); // 첨자 6부터 끝까지
 
// substring과 비슷한 함수인 slice(시작 첨자, 끝 첨자)는 시작 첨자부터 끝 첨자 앞까지, substr(시작 첨자, 개수)은 시작 첨자부터 개수만큼 부분 문자열을 반환한다.
 
// indexOf("문자")은 "문자"와 일치하는 문자열의 문자의 가장 왼쪽 위치를 반환하고 없으면 -1을 반환한다.
document.write(msg.indexOf("g")>=0? "글자 O":"글자 X");
   
// lastIndexOf("문자")은 "문자"와 일치하는 문자열의 문자의 가장 오른쪽 위치를 반환하고 없으면 indexOf처럼 -1을 반환한다.
 
// split("문자-구분자")은 "문자-구분자"를 기준으로 문자열을 파싱한다.
msg = "It's a pleasure to meet you!";
document.write(msg.split(" ",3)); // It's,a,pleasure
document.write("<hr>");
document.write(msg.split(" ")); // It's,a,pleasure,to,meet,you!
document.write("<hr>");
document.write(msg.split(" ")[0]); // It's
document.write("<hr>");
document.write(msg.split(" ")[2]); // pleasure
```
