**Date** 객체는 날짜 정보를 저장하는 객체이다. 매개변수가 없으면 현재 날짜를 표시하며 매개변수를 사용해서 특정 날짜의 년, 월, 일 ,시, 분, 초까지 표현할 수 있다. 
**문자열로 매개변수를 표현할 경우 <i>년, 월, 일</i>만 표현할 수 있다**.<br><b>(월은 1부터가 아니라 0부터 시작해서 11에 끝난다. 요일은 일요일을 0으로 시작해서 토요일은 6으로 숫자로 표현한다.)</b>
```javascript
// 현재 날짜 정보를 저장하는 객체 
var d = new Date(); 
 
// 특정 날짜 정보를 저장하는 객체
var d1 = new Date(2021, 4, 6); // 2021년 5월 6일 
 
// 문자열 날짜
var d2 = new Date("2021/4/6");
 
//(년, 월, 일, 시, 분, 초)
var d3 = new Date(2021, 4, 6, 9, 30, 0);
```
년, 월, 일, 시, 분, 초를 가져올 때는 getFullYear(), getMonth(), getDay(), getHours(), getMinutes(), getSeconds() 함수를 사용할 수 있다.

## 숫자로 표시된 요일을 문자로 변환하는 함수
```javascript
var d = new Date(); 
 
function dayToChar(d){
      var day = "";
      
      switch(d){
      case 0:
          day = "일";
          break;
      case 1:
          day = "월";
          break;
      case 2:
          day = "화";
          break;
      case 3:
          day = "수";
          break;
      case 4:
          day = "목";
          break;
      case 5:
          day = "금";
          break;
      case 6:
          day = "토";
          break;
      }
      return myDay;  
}

document.write(dayToChar(d.getDay()) + "요일");
```
