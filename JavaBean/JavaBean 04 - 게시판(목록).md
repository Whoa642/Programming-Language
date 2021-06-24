<h2>테이블에 저장된 글의 총 개수를 사용해서 페이지의 위치를 출력</h2>

```jsp
<body>    
    <h1>WebContent/board/list.jsp</h1>
    <%
        // 테이블에 저장된 글의 총 개수 확인
        
        // BoardDAO 객체 생성
        BoardDAO bDAO = new BoardDAO();
        
        // 글의 총 개수를 계산하는 메서드 생성
        int cnt = bDAO.getBoardCount();
        
        //////////////////////////////////////////
        // 페이징 처리
        
        // 한 페이지의 출력할 글의 개수
        int pageSize = 3;
        
        // 현 페이지의 위치 정보
        String pageNum = request.getParameter("pageNum");
        if(pageNum == null){
            pageNum = "1";
        }
        
        // 시작행 번호 계산 1... 11... 21... 31...
        int currentPage = Integer.parseInt(pageNum);
        int startRow = (currentPage-1)*pageSize+1;
        
        // 끝행 번호 계산 10... 20... 30... 40...
        int endRow = currentPage*pageSize;
        
        //////////////////////////////////////////
        
        // 저장된 모든 글의 정보를 가져오는 메서드 생성
        ArrayList boardList = null;
        
        if(cnt > 0){
            //boardList = bDAO.getBoardList();    
            boardList = bDAO.getBoardList(startRow,pageSize);
            //System.out.println(boardList);
        }
    %>
 
    <h2>게시판 목록 [총: <%=cnt%>개]</h2>
    
    <h3><a href="writeForm.jsp">글쓰기</a></h3>
    
    <table border="1">
        <tr>
            <td>번호</td>
            <td>제목</td>
            <td>작성자</td>
            <td>날짜</td>
            <td>조회수</td>
            <td>IP</td>
        </tr>
        
        <%
            for(int i = 0; i < boardList.size(); i++){
                BoardBean bb = (BoardBean)boardList.get(i);
        %>
        <tr>
            <td><%=bb.getNum()%></td>
            <td><%=bb.getSubject()%></td>
            <td><%=bb.getName()%></td>
            <td><%=bb.getDate()%></td>
            <td><%=bb.getReadcount()%></td>
            <td><%=bb.getIp()%></td>
        </tr>
        <%
            }
        %>
    </table>
    <hr>
    
    <%
        //////////////////////////////////////////
        // 페이징 처리
        
        if(cnt > 0){
            // 한 페이지에서 보여줄 페이지 번호의 개수
            int pageBlock = 10;
            
            // 전체 페이지 개수 => 전체 글 개수/페이지 크기
            int pageCount = cnt/pageSize+(cnt%pageSize == 0 ? 0 : 1);
            
            // 페이지 블록의 시작번호 계산 1-10 => 1, 11-20 => 11, 21-30 => 21
            int startPage = ((currentPage-1)/pageBlock)*pageBlock+1;
            
            // 페이지 블록의 끝번호 계산 
            int endPage = startPage+pageBlock-1;
            
            if(endPage > pageCount){
                endPage = pageCount;
            }
            
            // [이전]
            if(startPage > pageBlock){
                %>
                    <a href="list.jsp?pageNum=<%=startPage-pageBlock%>">[이전]</a>
                <%
            }
                    
            // [1...10] [11...20] [21...30] [31...40] ...
            for(int i = startPage; i <= endPage; i++){
                %>
                    <a href="list.jsp?pageNum=<%=i%>">[<%=i%>]</a>
                <%                 
            }
            
            // [다음]
            if(endPage < pageCount){
                %>
                    <a href="list.jsp?pageNum=<%=startPage+pageBlock%>">[다음]</a>    
                <%
            }
        }
        //////////////////////////////////////////
    %>
    
</body>
```

```java
package com.itwillbs.board;
 
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;
 
public class BoardDAO {
    
    Connection con = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;
    String sql = "";
 
    private Connection getCon() throws Exception {
        Context initCTX = new InitialContext();
 
        DataSource ds = (DataSource) initCTX.lookup("java:comp/env/jdbc/mysqlDB");
        con = ds.getConnection();
        System.out.println("DAO: DB 연결"+con);
 
        return con;
    }
 
    // 자원해제
    public void closeDB() {
        try {
            if (rs != null)
                rs.close();
            if (pstmt != null)
                pstmt.close();
            if (con != null)
                con.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
 
    // getBoardCount()--------------------------------------------
    public int getBoardCount() {
        int cnt = 0;
 
        try {
            con = getCon();
 
            sql = "select count(*) from itwill_board";
            pstmt = con.prepareStatement(sql);
 
            rs = pstmt.executeQuery();
 
            if (rs.next()) {
                cnt = rs.getInt(1); 
            }
 
            System.out.println("DAO: 글 개수 확인 "+cnt);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeDB();
        }
 
        return cnt;
    }
    // getBoardCount()--------------------------------------------
 
    // getBoardList()
    public ArrayList getBoardList() {
        ArrayList boardList = new ArrayList();
        
        try {
            con = getCon();
 
            sql = "select * from itwill_board";
            pstmt = con.prepareStatement(sql);
 
            rs = pstmt.executeQuery();
 
            while(rs.next()){
                BoardBean bb = new BoardBean();
                bb.setContent(rs.getString("content"));
                bb.setDate(rs.getDate("date"));
                bb.setFile(rs.getString("file"));
                bb.setIp(rs.getString("ip"));
                bb.setName(rs.getString("name"));
                bb.setNum(rs.getInt("num"));
                bb.setPass(rs.getString("pass"));
                bb.setRe_lev(rs.getInt("re_lev"));
                bb.setRe_ref(rs.getInt("re_ref"));
                bb.setRe_seq(rs.getInt("re_seq"));
                bb.setReadcount(rs.getInt("readcount"));
                bb.setSubject(rs.getString("subject"));
                
                boardList.add(bb);
            }
            
            System.out.println("DAO: 글목록 저장완료");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeDB();
        }
 
        return boardList;
    }
    // getBoardList()
    
    // getBoardList(startRow,pageSize)
    public ArrayList getBoardList(int startRow,int pageSize){
        ArrayList boardList = new ArrayList();
        
        try {
            con = getCon();
            
            sql ="select * from itwill_board "
                    + "order by re_ref desc, re_seq asc "
                    + "limit ?,?";
            pstmt = con.prepareStatement(sql);
            
            pstmt.setInt(1,startRow-1);
            pstmt.setInt(2,pageSize);
 
            rs = pstmt.executeQuery();
            
            while(rs.next()){
                BoardBean bb = new BoardBean();
                bb.setContent(rs.getString("content"));
                bb.setDate(rs.getDate("date"));
                bb.setFile(rs.getString("file"));
                bb.setIp(rs.getString("ip"));
                bb.setName(rs.getString("name"));
                bb.setNum(rs.getInt("num"));
                bb.setPass(rs.getString("pass"));
                bb.setRe_lev(rs.getInt("re_lev"));
                bb.setRe_ref(rs.getInt("re_ref"));
                bb.setRe_seq(rs.getInt("re_seq"));
                bb.setReadcount(rs.getInt("readcount"));
                bb.setSubject(rs.getString("subject"));
                
                boardList.add(bb);
            }
            
            System.out.println("DAO: 게시판 글 저장완료(페이징 처리)");
            
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeDB();
        }
        
        return boardList;
    }
    // getBoardList(startRow,pageSize)
    
    // getBoard(num)
    public BoardBean getBoard(int num){
        BoardBean bb = null;
        
        try {
 
            con = getCon();
 
            sql = "select * from itwill_board "
                    + " where num=?";
            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, num);
            
            rs = pstmt.executeQuery();
 
            if(rs.next()){
                bb = new BoardBean();
                
                bb.setContent(rs.getString("content"));
                bb.setDate(rs.getDate("date"));
                bb.setFile(rs.getString("file"));
                bb.setIp(rs.getString("ip"));
                bb.setName(rs.getString("name"));
                bb.setNum(rs.getInt("num"));
                bb.setPass(rs.getString("pass"));
                bb.setRe_lev(rs.getInt("re_lev"));
                bb.setRe_ref(rs.getInt("re_ref"));
                bb.setRe_seq(rs.getInt("re_seq"));
                bb.setReadcount(rs.getInt("readcount"));
                bb.setSubject(rs.getString("subject"));
            }
            
            System.out.println("DAO: 글 정보를 저장완료");
            
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeDB();
        }
        
        return bb;
    }
    // getBoard(num)
}
```
