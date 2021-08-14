<h1>정의</h1>

<ol>
  <li>자바스크립트는 객체 기반의 언어이며 객체는 <b><i>특징(속성)</i></b>과 <b><i>기능(동작)</i></b>으로 구성된다.</li>
  <li>객체를 <b>추상화</b>한다 것은 객체의 특징과 기능을 정의한다는 것을 의미한다.</li>
  <li><b>이렇게 추상화된 객체에서 특징은 변수로 기능은 메서드로 표현한다.</b></li>
  <li>변수가 데이터를 저장하는 공간인 것처럼 객체도 변수이지만 많은 값을 포함할 수 있다.</li>
</ol>

<br>

<h1>속성</h1>

<ol>
  <li>속성은 <b>이름:값</b>의 쌍으로 표현한다. (e.g. const student = {ID: "023", age: 17, gender: "M"};</li>
  <li>
      객체의 속성에 접근하는 2가지 방식
      <ul>
        <li><b>객체명.속성명</b></li>
        <li><b>객체명["속성명"]</b></li>
      </ul>
  </li>
</ol>

<br>

<h1>동작</h1>

<ol>
  <li>동작은 <b>메서드</b>로 표현한다. </li>
  <li>메서드에서 <b><i>this</i></b>는 함수의 소유자를 가리킨다. 즉 객체 const stu가 grade라는 메서드를 가지고 있으면 this는 grade를 소유하는 stu 객체를 의미한다. this.age는 이 객체의 age 속성을 의미한다.</li>
  <li>
     객체의 메서드에 접근하는 방식
     <ul><li><b>객체명.메서드명()</b></li></ul>
  </li>
</ol>

변수를 new 키워드로 선언하면 객체를 생성할 수있다. <b><i>var 참조 변수명 = new Object();</i></b> (<b>String, Number, Boolean는 객체로 선언하면 코드의 복잡성이 높아지고 실행 속도가 느려진다</b>.)

```javascript
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
 
  const Phone = {
          model: "아이폰 12",
          price: "100만 원",
          brand: "애플",
          num: "010-1234-5678",
          call: function(){
              alert("전원 켜기");
              alert("통화 앱 실행");
              alert("전화번호 입력");
              alert("통화버튼 클릭");
              alert("전화 걸기");                  
          }
  };
 
  Phone.call();
 
</script>
</head>
<body> 
</body>
</html>
```

<h1>자바스크립트의 객체의 종류</h1>

<ol>
  <li>
    내장 객체
    <ul>
      <li>자바스크립트에 기본적으로 내장되어 있는 객체</li>
      <li>String, Array, Date, Math ...</li>
    </ul>
  </li>
  <li>
    브라우저 객체 모델 (Browser Object Model)
    <ul>
      <li>브라우저 안에 계층적으로 모여있는 객체</li>
      <li>window, screen, location, history, docuemnt ...</li>
    </ul>    
  </li>
  <li>
    문서 객체 모델(Document Object Model)
    <ul><li>문서를 구성하는 객체(HTML 태그)</li></ul>
  </li>
</ol>
