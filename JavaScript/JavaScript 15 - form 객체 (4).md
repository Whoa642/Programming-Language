<h2>select의 속성을 확인</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
          // window-document-form-select 태그
       function func1() {
           alert("name:"+document.fr.subject.name);
           alert("length:"+document.fr.subject.length);
           alert("type:"+document.fr.subject.type);
           alert("selectedIndex:"+document.fr.subject.selectedIndex);
       
           // window-document-form-select 태그.options[위치].속성
           // .text .value .selected (true,false)
           alert("text:"+document.fr.subject.options[0].text);
           alert("value:"+document.fr.subject.options[0].value);
        }
   
</script>
</head>
<body>
    <h1>WebContent/js3/test5.html</h1>
 
    <form action="a.jsp" method="get" name="fr">
 
        <select name="subject">
            <!-- option에 value값이 없을 경우 text값이 value 값으로 처리 -->
            <option value="">선택하세요.</option>
            <option value="java">자바</option>
            <option value="js">자바스크립트</option>
            <option value="jsp">JSP</option>
            <option value="web">WEB</option>
            <option value="db">DB</option>
        </select>
 
        <hr>
        <input type="submit" value="전달하기">
        <input type="button" value="select 속성 확인" onclick="func1();">
 
    </form>
</body>
```

<h2>select가 변경되면 해당 옵션의 텍스트 값을 출력</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
    function func2(){       
           var sidx = document.fr.subject.selectedIndex;
           //alert("변경 정보:"+document.fr.subject.options[0].text);
           alert("변경 정보:"+document.fr.subject.options[sidx].text);
       
    }   
</script>
</head>
<body>
    <h1>WebContent/js3/test5.html</h1>
 
    <form action="a.jsp" method="get" name="fr">
 
        <select name="subject" onchange="func2()">
            <option value="">선택하세요.</option>
            <option value="java">자바</option>
            <option value="js">자바스크립트</option>
            <option value="jsp">JSP</option>
            <option value="web">WEB</option>
            <option value="db">DB</option>
        </select>
 
    </form>
</body>
```

<h2>선택된 항목이 있을 경우만 submit 이벤트 처리</h2>

```html
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<script type="text/javascript">
    function func3(){    
       if(document.fr.subject.selectedIndex == 0){
           alert("적어도 1개의 과목을 선택하세요.");
           document.fr.subject.focus();
           return false;
       }
       
       }
</script>
</head>
<body>
    <h1>WebContent/js3/test5.html</h1>
 
    <form action="a.jsp" method="get" name="fr" onsubmit="return func3();">
 
        <select name="subject">
               <!-- option에 value값이 없을 경우 text값이 value 값으로 처리 -->
            <option value="">선택하세요.</option>
            <option value="java">자바</option>
            <option value="js">자바스크립트</option>
            <option value="jsp">JSP</option>
            <option value="web">WEB</option>
            <option value="db">DB</option>
        </select>
 
    </form>
</body>
```
