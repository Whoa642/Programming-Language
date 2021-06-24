<h2>작성한 글을 수정</h2>

```jsp
<body>
   <h1>WebContent/board/updateForm.jsp</h1>
   
   <h2>글 수정</h2>
   
   <%
     int num = Integer.parseInt(request.getParameter("num"));
     String pageNum = request.getParameter("pageNum");
      
     BoardDAO bdao = new BoardDAO();
     BoardBean bb = bdao.getBoard(num);
   %>
   
   <fieldset>
     <form action="updatePro.jsp?pageNum=<%=pageNum %>" method="post">
       <input type="hidden" name="num" value="<%=num%>">
          글쓴이: <input type="text" name="name" value="<%=bb.getName()%>"><br>
          비밀번호: <input type="password" name="pass" placeholder="비밀번호를 입력하세요."><br>
          제목: <input type="text" name="subject" value="<%=bb.getSubject()%>"><br>
          내용: <br>
          <textarea rows="5" cols="20" name="content" ><%=bb.getContent() %></textarea>
          <hr>
        <input type="submit" value="수정">     
     </form>
   </fieldset>
  
    <h1>WebContent/board/updatePro.jsp</h1>
    <%
        request.setCharacterEncoding("UTF-8");
     
        // get - pageNum (주소) => 변수
        String pageNum = request.getParameter("pageNum");
        // post - num,name,pass,subject,content (from) => 자바빈 액션태그 
    %>
        <jsp:useBean id="bb" class="com.itwillbs.board.BoardBean"/>
        <jsp:setProperty property="*" name="bb"/>
   <%
   
    BoardDAO bDAO = new BoardDAO();
    int check = bDAO.updateBoard(bb); 
    
    if(check == 1){
        %>
         <script type="text/javascript">
            alert("글 정보 수정완료");
            location.href='list.jsp?pageNum=<%=pageNum%>';
         </script>        
        <%
    }else if(check == 0){
        %>
         <script type="text/javascript">
             alert("비밀번호 오류");
             history.back();
         </script>        
        <%
    }else{ //check == -1
        %>
            <script type="text/javascript">
                alert("해당 글 없음");
                history.back();
            </script>        
           <%
    }
   %>
</body>
```
