자바스크립트는 객체 기반의 언어이며 **객체**는 <b>특징(속성)</b>과 <b>기능(동작)</b>으로 구성된다. 객체를 **추상화**한다 것은 객체의 특징과 기능을 정의한다는 것을 의미한다. 이렇게 추상화된 객체에서 특징은 변수로 기능은 메서드로 표현한다.

객체를 생성할 때는 **var 참조 변수명 = new Object();**

```javascript
// 스마트폰 - 특징:모델명(model),가격(price),브랜드(brand),전화번호(telNum)전화걸기() 
//          - 기능:전화 걸기(tel)
var Phone = new Object();
  
Phone.model = "아이폰6";
Phone.price = "100만";
Phone.brand = "Apple";
Phone.telNum = "010-1234-5678";
  
// 전화걸기 동작:전원 켜기 -> 통화앱 실행 -> 전화 번호 입력 -> 통화 버튼 클릭 -> 전화 
Phone.tel = function(){
    alert("전원 켜기");
    alert("통화 앱 실행");
    alert("전화 번호 입력");
    alert("통화 버튼 클릭");
    alert("전화 걸기");      
}
Phone.tel();
```

## 자바스크립트의 객체의 종류

1. 내장 객체<br>
자바스크립트에 기본적으로 내장되어 있는 객체<br>
String:문자, Array:배열, Date:날짜, Math:수학, 등 ...

2. 브라우저 객체 모델(Browser Object Model)<br>
브라우저 안에 계층적으로 모여있는 객체<br>
window, screen, location, history, docuemnt, 등 ...

3. 문서 객체 모델(Document Object Model)<br>
문서를 구성하는 객체(HTML 태그)
