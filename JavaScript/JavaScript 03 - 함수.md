변수가 데이터를 저장하는 공간이라면 **함수**는 실행문을 저장하는 공간이라고 할 수 있다. 따라서 여러 개의 실행문을 한 번에 실행할 수 있기 때문에 특정 동작을 표현할 때 함수를 사용한다.
(유사한 동작들을 모아서 처리하도록 함수를 선언하는 것을 **모듈화**라고 한다.) 함수와 같이 연관되어서 사용되는 단어가 **메서드**인데 함수는 절차지향, 메서드는 객체지향에서 사용되는 단어이다.

함수 선언 형식은 <b>function 함수형)() {실행문;}</b>이다. 이름이 없는 익명 함수도 존재하는데 <b>var 참조 변수명 = function() {실행문;}</b>과 같이 선언한다. 
이름이 있는 함수의 경우 <b>함수형();</b>으로 호출하지만 익명 함수의 경우 <b>참조 변수명();</b>으로 호출한다. 매개변수가 있을 경우 ()안에 매개변수 이름을 적고 반환값이 있을 경우 함수 블록 마지막에 return을 사용한다.
<b>(매개변수는 6개까지 사용하는 것이 좋다.)</b>
```javascript
// 함수 선언
function myInfo() {
        document.write("가나다<br>");
        document.write("010-1234-5678<br>");
        document.write("지구<br>");
}
 
// 함수 호출
myInfo();
document.write("<hr>");
 
// 익명 함수 선언
var myInfo2 = function() {
        document.write("가나다<br>");
        document.write("010-1234-5678<br>");
        document.write("지구<br>");
}
 
// 익명 함수 호출
myInfo2();
document.write("<hr>");
 
// 2개의 매개변수를 가지며 반환값이 있는 함수 선언
function add(num1, num2){
        var result = num1 + num2;
        return result;
}
 
alert(add(5, 6));  
```

## 숫자 2개,연산 기호 1개(+, -, *, /, %)를 받아서 연산 결과를 출력하는 함수
```javascript
function cal(num1, op, num2){
      
      switch(op){
      case "+":
          num1 += num2;
          break;
      case "-":
          num1 -= num2;
          break;
      case "*":
          num1 *= num2;
          break;
      case "/":
          num1 /= num2;
          break;
      case "%":
          num1 %= num2;
          break;
      default:
          num1 = "잘못된 연산자";      
      }
      
    document.write("결과:" + num1 + "<br>");
}
  
cal(120, "+", 100);
cal(403, "%", 5);
```

## 내장 함수

자바스크립트에 기본적으로 내장되어 있는 함수이다.(alert(),prompt(),confirm(),Number(),Boolean() ...)
