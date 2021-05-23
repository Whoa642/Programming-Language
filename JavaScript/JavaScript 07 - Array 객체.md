<b>Array</b> 객체는 배열이며 데이터를 연속된 메모리 공간에 저장하는 객체이다. 배열의 개별 데이터를 <b>요소</b>라고 하며 배열의 이름과 첨자를 사용해서 접근할 수 있다. 
개별 요소는 변수처럼 사용할 수 있다. 첨자는 C, Java와 같이 0부터 시작한다. <b>다른 언어와 큰 차이점은 자바스크립트의 배열 객체는 자료형에 상관없이 데이터를 저장할 수 있다.</b>
```javascript
// 배열 생성 방법 
// 1) var 참조변수 = new Array();
// 2) var 참조변수 = new Array(값1, 값2, ...);
// 3) var 참조변수 = [값1, 값2, 값3, ...];
var arr1 = new Array();
arr[0] = 100;
arr[1] = 200;
arr[2] = 300;
arr[3] = 400;
   
var arr2 = new Array(5, 19, 2, 3, 0, 7);
 
var arr3 = [1, 2, 3, 4, 5, 6, 7];
```

일반적으로 사용하는 for문 이외에도 C++, Java와 같이 향상된 for문과 같은 for ~ in문을 사용할 수 있다. 자동으로 Array 객체의 길이를 계산해서 전체를 순회한다. 
<b>다만, 자바스크립트의 for ~ in문은 C++, Java와 같이 배열의 요소를 가져오는게 아니라 첨자를 가져오기 때문에 여전히 배열 이름과 첨자를 사용해야 한다.</b>
<b><i>(첨자를 사용하지 않고 배열 이름을 출력문에 넣어도 모든 요소를 출력한다.)</i></b>

```javascript
var arr = [12, 1, 5, 7, 3, 52, 63];
   
// for문
for(var i = 0; i < arr.length; i++)
       document.write("arr[" + i + "]:" + arr[i] + "<br>");   
 
 
// for ~ in 문
for(var i in arr)
       document.write("arr[" + i + "]:" + arr[i] + "<br>");
```
<hr>

## 사용자 이메일 판별
1. 사용자가 prompt로 이메일을 입력한다.
2. 유효한 이메일인지 판별하기 위해서 다음 2가지 조건을 확인한다.     
  2.1. 주소에 '@'가 포함되어있는지 확인한다.    
  2.2. co.kr, com, net, or.kr, go.kr 주소만 유효한 이메일 주소이다.
3. 2개의 조건을 확인하는 변수를 선언하고 false로 초기화한다.
4. 크기가 5인 배열을 선언하고 위의 주소들로 초기화한다.
5. indexOf로 사용해서 -1이 아니면 조건 변수에 true를 대입한다.
6. 둘 다 true이면 사용 가능한 이메일이다.

```javascript
var email = prompt("이메일 주소를 입력하세요.");
   
var valid1 = false;
var valid2 = false;   
   
// 1) 주소에 '@'가 포함되어있는지 확인
if( email.indexOf('@') > 5)
       valid1 = true;
   
// 2) [".co.kr",".com",".net",".or.kr",".go.kr"] 해당 주소만 유효한 이메일
var validUrl = [".co.kr", ".com", ".net", ".or.kr", ".go.kr"];
   
for(var i = 0; i < validUrl.length; i++)
    if(email.indexOf(validUrl[i]) > -1)
           valid2 = true;
   
// 조건 2개를 만족하는지 확인
if(valid1 && valid2)
    alert("유효한 이메일 입니다.");
else
    alert("유효하지 않은 이메일 입니다."); 
```
