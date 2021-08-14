<h1>정의</h1>
<b>변수</b>가 <b>데이터</b>를 저장하는 공간이라면 <b>함수</b>는 <b>실행문</b>을 저장하는 공간

<ol>
        <li>여러 개의 실행문을 한 번에 실행할 수 있기 때문에 특정 동작을 표현할 때 함수를 사용한다.(유사한 동작들을 모아서 처리하도록 함수를 선언하는 것을 <b>모듈화</b>라고 한다.) </li>
        <li>함수와 같이 연관되어서 사용되는 단어가 <b>메서드</b>인데 함수는 <b>절차 지향</b>, 메서드는 <b>객체 지향</b>에서 사용되는 단어이다.</li>
</ol>

<br>

<h1>선언</h1>

<ol>
        <li>함수 선언 형식: <b><i>function 함수명() {실행문;}</b></i></li>
        <li>함수명의 규칙은 변수명의 동일한 규칙</li>
        <li><b>함수안에 선언된 지역 변수는 함수에 국한된다.</b> 따라서 오직 함수 내에서만 접근할 수 있다.</li>
        <li>함수안의 지역 변수는 함수가 시작되면 생성되면 종료되면 사라진다. </li>
        <li><b>이름이 없는 익명 함수</b>는 <b><i>var 참조 변수명 = function() {실행문;}</i></b>과 같이 선언</li>
        <li>이름이 있는 함수의 경우 <b>함수명();</b>으로 호출하지만 익명 함수의 경우 <b>참조 변수명();</b>으로 호출</li>
        <li>매개변수가 있을 경우 ()안에 매개변수 이름을 적고 반환값이 있을 경우 함수 블록 마지막에 return을 사용한다. (<b><i>매개변수는 6개까지 사용하는 것이 좋다.</i></b>)</li>
</ol>

<br>


<h1>호출</h1>


<b>함수를 호출할 때 ()를 생략하면 함수의 결과가 아닌 함수 객체가 반환된다.</b>

<ol>
        <li>이벤트 발생</li>
        <li>자바스크립트 코드에서 호출</li>
        <li>자동 호출</li>
</ol>


함수 선언 형식은 <b>function 함수형)() {실행문;}</b>이다. 이름이 없는 익명 함수도 존재하는데 <b>var 참조 변수명 = function() {실행문;}</b>과 같이 선언한다. 
이름이 있는 함수의 경우 <b>함수형();</b>으로 호출하지만 익명 함수의 경우 <b>참조 변수명();</b>으로 호출한다. 매개변수가 있을 경우 ()안에 매개변수 이름을 적고 반환값이 있을 경우 함수 블록 마지막에 return을 사용한다.
<b>(매개변수는 6개까지 사용하는 것이 좋다.)</b>

```javascript
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
        <script type="text/javascript">
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
	</script>
</head>
<body> 
</body>
</html>
```

<br>

<h2>숫자 2개, 연산 기호 1개(+, -, *, /, %)를 받아서 연산 결과를 출력하는 함수</h2>

```javascript
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
        <script type="text/javascript">
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
        	        document.write("결과: " + num1 + "<br>");
     	        }
                cal(120, "+", 100);
       	        cal(403, "%", 5);
	</script>
</head>
<body> 
</body>
</html>
```
