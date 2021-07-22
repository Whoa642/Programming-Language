<b>JSON</b>(JavaScript Object Notation)은 <b>키와 값의 쌍</b>으로 구성된 자료형이다.

JSON의 특징
<ol>
  <li>다른 도메인 주소에서 처리되는 요청을 처리할 수 있다.</li>
<li>키와 값으로 데이터를 매우 간결하게 표현한다.</li>
<li>문법을 엄격하게 준수한다.</li>
<li>자바스크립트에서 실행 가능한 데이터이기 때문에 악용 가능성이 높다.</li>
</ol>

JSON 객체는 {}, 배열은 []으로 표현한다. 기본 데이터의 형태는 키 : 값이며 <b>키는 ""안에 넣어서 표시하고 값은 자료형의 형태에 따라서 적절하게 변경한다</b>. 
여러 개의 키 값이 존재하면 ','으로 구분한다.

  
JSON 자료형
<ul>
<li>정수형: 10진수만 사용할 수 있다.</li>
<li>실수형: 부동 소수점, 고정 소수점</li>
<li>불리언</li>
<li>null</li>
<li>문자열: ""안에 넣고 사용하며 유니코드 형태로도 사용할 수 있다.</li>
<li>배열</li>
</ul>

```jsp
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
 
    <script src="../js/jquery-3.6.0.min.js"></script>
    <script type="text/javascript">
        $(function(){
            // ajax 사용해서 JSON 데이터를 가져오기
            
            $.ajax('json1.jsp',{
                
                dataType:"json",
                
                success: function(data){
                    //alert('성공');            
                    //alert(data);
                    //console.log(data);
                    $('body').append(data.name);
                    /* $(data).each(function(k,v){
                        $('body').append(k+"//"+v.name+"<br>");
                        $('body').append(k+"//"+v.age+"<br>");
                        $('body').append(k+"//"+v.gender+"<br>");
                    }); */
                }                
            });
            // ajax
            
            // .getJSON():비동기 방식으로 JSON 데이터를 가져온다.
            $.getJSON('json1.jsp',function(data){
                //alert('data: '+data);            
                //console.log(data);
                $.each(data,function(k,v){
                    $('body').append(k+"//"+v+"<br>");
                });
            });
        });
    </script>
</head>
<body>
    <h1>WebContent/jq3/json.html</h1>
</body>
 
<!--json1.jsp-->
{"name":"홍길동","age":20,"gender":"남"}
```

```jsp
<!--json3.html-->
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
    <script src="../js/jquery-3.6.0.js"></script>
    <script type="text/javascript">
        
        $(document).ready(function(){
            
            // 비동기 방식으로 생성된 DB 정보(JSON 데이터)    
            $.getJSON('json3.jsp',function(data){
            
                $.each(data,function(idx,item){
                    $('body').append(item.id+'/'+item.pass+'/'+item.reg_date+'<br>');
                });
            });
        })
    </script>
</head>
<body>
    
</body>
 
<!--json3.jsp-->
<%
    // DB에서 정보를 가져오기
    // 모든 회원 정보를 가져오기 동작 구현
    
    // 1. 드라이버 로딩
    Class.forName("com.mysql.jdbc.Driver");
 
    // 2. DB 연결
    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/jspdb","root","1234");
    
    // 3. SQL 작성 & pstmt 객체
    String sql = "select * from itwill_member";
    PreparedStatement pstmt = conn.prepareStatement(sql);
    
    // 4. SQL 실행
    ResultSet rs = pstmt.executeQuery();
        
    // 5. 데이터 처리
    // JSON으로 변환
    JSONArray memberList = new JSONArray();
    while(rs.next()){
        // 배열 한칸에 객체 1개
        JSONObject member = new JSONObject();
        
        member.put("id",rs.getString("id"));
        member.put("pass",rs.getString("pass"));
        member.put("name",rs.getString("name"));
        member.put("age",rs.getInt("age"));
        member.put("gender",rs.getString("gender"));
        member.put("email",rs.getString("email"));
        member.put("reg_date",rs.getTimestamp("reg_date")+"");
        
        memberList.add(member);
    }
    // 화면에 출력
%>
 
    <%=memberList %>
```
