<h1>정의</h1>

다른 프로그래밍 언어와 달리 자바스크립트는 오직 1개의 숫자 자료형을 가지며 <b>숫자는 항상 64 비트 부동 소수점 숫자로 정의된다.</b>

<ol>
  <li>숫자는 소수점을 포함할 수 있다.</li>
  <li>매우 크거나 작은 숫자는 지수 표기법을 사용한다.</li>
  <li>정수는 최대 15자리까지 정확하다.</li>
  <li>소수점 뒤에는 최대 17자리까지 적을 수 있지만 <b>부동 소수점 연산은 항상 오차가 발생할 수 있다</b>.</li>
  <li><b>숫자와 문자열을 더하면 결과는 문자열</b></li>
  <li><b><i>문자열로 표현된 숫자를 사용해서 연산을 수행할 때 '+'는 작동하지 않는다</i></b>. <b>(문자열이 더해진다.)</b></li>
  <li>Number는 일반적으로 숫자 리터럴로 생성되는 원시 자료형이지만 new 키워드를 사용해서 객체로 정의할 수 있다. new 키워드를 사용하면 자료형은 Object이고 숫자 리터럴을 사용하면 자료형은 Number(이 때문에 저장한 문자열의 값이 같아도 비교 연산자 '==='를 사용하면 false가 나온다. 또한 객체는 비교 연산이 불가능하기 때문에 항상 false를 반환한다.)</li>
</ol>

<br>


<h1>NaN - Not a Number</h1>

숫자가 유효하지 않다는 것을 알려주는 예약어

<ol>
  <li>숫자와 숫자가 아닌 문자열에 연산을 수행하면 NaN</li>
  <li>전역 함수 <b>isNaN()</b>을 사용해서 값이 숫자인지 판별 (숫자면 false, 아니면 true)</li>
  <li>연산에 NaN을 사용하면 결과는 NaN 혹은 문자열 결합(concatenation)</li>
  <li>NaN의 자료형은 숫자(Number)</li>
</ol>

<br>

<h1>Infinity</h1>

Infinity 또는 -Infinity는 자바스크립트가 표현할 수 있는 숫자의 범위를 넘어가면 반환되는 값

<ol>
  <li>0으로 나누면 Infinity</li>
  <li>Infinity의 자료형은 숫자(Number)</li>
</ol>

<br>

<h1>Hexadecimal</h1>

숫자 앞에 0x를 붙이면 16진수로 해석, 자바스크립트는 기본적으로 숫자를 10진법으로 표시하지만 <b>toString()</b> 메서드에 2부터 36까지의 숫자를 입력해서 진법을 변경시킬 수 있다.

<br>

<h1>메서드</h1>

<b><i>모든 숫자 메서드는 모든 숫자 자료형에 적용할 수 있다. (리터럴, 변수, 식)</i></b>

<h2>toString()</h2> 

숫자를 문자열로 반환

<h2>toExponential()</h2>

숫자를 반올림하고 지수 표기법으로 변환해서 문자열로 반환

<ul><li>매개변수를 생략하면 반올림 적용 X</li></ul>

<h2>toFixed()</h2>

명시된 개수의 숫자를 소수점 뒤에 표시하고 반올림해서 문자열로 반환

<h2>toPrecision()</h2>

명시된 길이로 숫자를 반올림해서 문자열로 반환

<ul><li><b>매개변수 생략 시 숫자 그대로 반환</b></li></ul>

<h2>valueOf()</h2>

숫자를 숫자로 반환

<ul><li>주로 Number 객체를 원시형으로 변환할 때 내부적으로 사용된다.</li></ul>

<br>

<h1>변수를 숫자로 변환하는 전역 메서드</h1>

<h2>Number()</h2>

변수를 숫자로 변환
  
<ul>
  <li>숫자로 변환이 안될 경우 NaN 반환</li>
  <li>날짜를 숫자로 변환할 경우 1970년 1월 1일 이후 지난 시간을 밀리초로 변환</li>
</ul>
  
<h2>parseInt()</h2>

문자열을 파싱한 다음 정수로 반환
  
<ul>
  <li>숫자가 여러 개면 <b>오직 1번째 값</b>만 반환 </li>
  <li>숫자로 변환이 안될 경우 NaN 반환</li>
</ul>

<h2>parseFloat()</h2>
  
문자열을 파싱한 다음 숫자로 반환
  
<ul>
  <li>숫자가 여러 개면 <b>오직 1번째 값</b>만 반환 </li>
  <li>숫자로 변환이 안될 경우 NaN 반환</li>
</ul>

<br>


<h1>숫자 속성</h1>

<h2>MIN_VALUE, MAX_VALUE</h2>

<ul>
  <li>MIN_VALUE: 가장 작은 값</li>
  <li>MAX_VALUE: 가장 큰 값</li>
</ul>

<h2>POSITIVE_INFINITY, NAGATIVE_INFINITY</h2>

<ul>
    <li>POSITIVE_INFINITY: 오버플로우 시 반환</li>
    <li>NEGATIVE_INFINITY: 언더플로우 시 반환/li>
</ul>


```javascript
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
		// 숫자는 항상 64 비트 부동 소수점
		var num = 9.123456;
		num = 100;
		
		// 지수 표기법
		num = 1.93823e-8;
		// 문자열 숫자 연산
		var n1 = "10", n2 = "20", n3 = "30", n4 = "40";
		
		// '-'
		var a1 = n1-n2; // -10
		// '*'
		var a2 = n2*n3; // 600
		// '/'
		var a3 = n4/n2; // 2
		// '+' -> 덧셈 연산이 아니라 문자열 결합
		// 16 진법
		num = 0xffff; // 65535
		// toString()으로 진법 변환 (2 ~ 36)
		document.write(num.toString(5)); // 4044120
		document.write(num.toString(36)); // 1EUF
		document.write(num.toString(2)); // 1111111111111111
		document.write(num.toString(8)); // 177777
		document.write(num.toString(23)); // 58U8
		
		// toExponential()
		num = 3.1415926;
		num.toExponential(3); // 3.142e+0
		num.toExponential(5); // 3.14159e+0
		num.toExponential(2); // 3.14e+0
		// toFixed()
		num.toExponential(3); // 3.142
		num.toExponential(5); // 3.14159
		num.toExponential(2); // 3.14
		// toPrecision()
		num.toPrecision(6); // 3.14159
		num.toPrecision(4); // 3.141
		num.toPrecision(1); // 3
		// Number()
		Number(true); // 1
		Number(false); // 0
		Number("    123 "); // 123
		Number("123    "); // 123
		Number("    123"); // 123
		Number("  123, 456"); // NaN
		Number("  123 456"); // NaN
		
		// parseInt()
		parseInt("-123 456"); // -123
		parseInt("3923 World"); // 3923
		parseInt("World 3923"); // NaN
		parseInt("102.323"); // 102	
		
		// parseFloat()
		parseFloat("-123.456"); // -123.456
		parseFloat("-123"); // -123
		parseFloat("3.14159 2.214 1.213"); // 3.14159
		parseFloat("STFU 0.03202"); // NaN
    </script>
</head>
<body> 
</body>
</html>
```
