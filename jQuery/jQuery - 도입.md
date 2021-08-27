<h1>정의</h1>

<b>제이쿼리</b>는 자바스크립트를 빠르고 쉽게 사용하기 위해서 만들어진 <b>라이브러리</b>

<ol>
 <li>HTML/DOM, CSS 조작</li>
 <li>HTML 이벤트 메서드</li>
 <li>효과, 애니메이션</li>
 <li>Ajax</li>
 <li>유틸리티</li>
</ol>

<br>

<h1>라이브러리 추가</h1>

<ol>
 <li>
  다운로드
  <ul>
   <li>HTML <script> 태그 안에 파일을 추가</li>
   <li>제이쿼리를 사용할 페이지와 같은 디렉토리에 추가</li>
  </ul>
 </li>
 <li>
  jQuery CDN
  <ul><li>CDN에서 제이쿼리를 다운받지 않고 추가</li></ul>
 </li>
</ol>

<br>

<h1>문법</h1>

제이쿼리 문법은 <b>HTML 요소</b>를 선택하고 요소에 <b>행위(action)</b>를 수행하도록 맞춤 설계
<ol>
  <li>
    기본 구문: <b><i>$(선택자).행위()</i></b>
    <ul>
     <li>'$'는 제이쿼리를 정의하고 접근</li>
     <li>'선택자'는 HTML 요소를 검색</li>
     <li>'행위'는 HTML 요소에 수행</li>     
    </ul>
 </li>
</ol>

<br>

<h1>문서 준비 이벤트</h1>

모든 제이쿼리 메서드는 문서 준비 이벤트에 위치하는데 이는 <b>문서가 로딩 완료전에 제이쿼리 코드가 실행되는 것을 방지하기 위해서이다</b>.

<ol>
 <li>$(document).ready(function() 제이쿼리 메서드 {});</li> 
 <li>$(function() 제이쿼리 메서드 {});</li>
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
            alert('제이쿼리 실행1');
        });

        // 간단해서 가장 많이 사용
        $(function(){ 
            alert('제이쿼리 실행2');
        });
        
        // jQuery 함수를 $에 매핑
        jQuery(document).ready(function(){
            alert('제이쿼리 실행3');
        });
        
        jQuery(function(){
            alert("제이쿼리 실행4");
        })
    </script></head>
<body>
</body>
</html>
```
