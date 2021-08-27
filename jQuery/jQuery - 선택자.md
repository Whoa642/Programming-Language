<h1>정의</h1>

<ol>
 <li>HTML 요소를 선택하고 조작</li>
 <li>HTML 요소의 이름, id, class, 자료형, 속성, 속성값을 찾는데 선택자 사용(이미 존재하는 CSS 선택자에 기반하며 맞춤 선택자도 존재)</li> 
 <li>모든 선택자는 '<b><i>$()</i></b>'로 시작 </li>
</ol>

<br>

<h1>종류</h1>

<ol>
  <li>
   HTML 요소
   <ul>
    <li><b>HTML 요소의 이름</b>을 사용해서 요소를 선택</li>
    <li><b>해당하는 모든 HTML 요소에 적용</b></li>   
   </ul>
 </li>
 <li>
   #id
   <ul>
    <li><b>HTML 태그의 id 속성</b>을 사용해서 요소를 선택</li>
    <li>페이지에서 id는 유일무이하기 때문에 <b>1개의 요소만 적용</b></li>
    <li>'<b><i>#</i></b>'를 사용한 다음 id의 이름을 적는다.</li>    
  </ul>
 </li>
 <li>
  .class
   <ul>
     <li><b>특정 클래스</b>를 가지는 요소를 선택</li>
     <li>'<b><i>.</i></b>'를 사용한 다음 class의 이름을 적는다.</li>    
   </ul>  
 </li>
</ol>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <!--jQuery 라이브러리 추가-->
    <script src="../js/jquery-3.6.0.js"></script>
    
    <!--jQuery 사용-->
    <script type="text/javascript">
        $(document).ready(function(){
            // 선택자
            // $(대상 정보).메서드();
            
            // * -> 전체 요소
            $('*').css('color', 'orange');
            
            // '태그명' -> 태그 요소
            $('h1').css('color', 'red');
            $('h2').css('color', 'blue');
            
            // #아이디명 -> 아이디 요소
            $('#title1').css('color', 'green');
            // .클래스명 -> 클래스 요소
            $('.title2').css('color', '#A566FF');
            
            // 속성 탐색 선택자
            // 태그[속성=값]: 속성에서 값과 일치하는 대상 선택
            // 태그[속성^=값]: 속성에서 값으로 시작하는 대상 선택
            // 태그[속성$=값]: 속성에서 값으로 끝나는 대상 선택
            $('input[type=text]').css('color', 'green');
            $('input[type=password]').css('color', 'red');
            
            $('input[type^=t]').css('color', 'black');
            $('input[type=text]').val('홍길동');
            
            var tmp = $('input[type=text]').val();
            alert("tmp: "+tmp);
            
            // 위치 탐색 선택자
            // 태그:odd -> 홀수 // 태그:even -> 짝수
            // 태그:first -> 처음 // 태그:last -> 마지막          
            $('tr:odd').css('background','yellow');
            $('tr:even').css('background','green');
            
            $('tr:first').css('background','red');
            $('tr:last').css('background','blue');              
        });
    </script>
</head>
<body>
    <h2 id="title1">제목 1</h2>
    <h2 class="title2">제목 2</h2>
    <h2>제목 3</h2>  

    내용<br>
    
    <hr>
    
    아이디: <input type="text" name="id"><br>
    비밀번호: <input type="password" name="pw"><br>
    이름: <input type="text" name="name"><br>

    <hr>
    
    <table border="1">
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
        
        <tr>
            <td>1</td>
            <td>2</td>
            <td>3</td>
        </tr>
    </table>
</body>
</html>
```
