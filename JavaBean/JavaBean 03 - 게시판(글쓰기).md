<h2>사용자의 정보를 받고 전달해서 처리하는 페이지</h2>

```jsp
<body>
   <h1>WebContent/board/writeForm.jsp</h1>
   
   <fieldset>
     <form action="writePro.jsp" method="post">
          글쓴이: <input type="text" name="name"><br>
          비밀번호: <input type="password" name="pass"><br>
          제목: <input type="text" name="subject"><br>
          내용: <br>
          <textarea rows="5" cols="20" name="content"></textarea>
          <hr>
        <input type="submit" value="글쓰기">     
     </form>
   </fieldset>
   
   <h1>WebContent/board/writePro.jsp</h1>
   
   <%
           request.setCharacterEncoding("UTF-8");
   %>
 
   <!--객체 생성-->
   <jsp:useBean id="bb" class="com.itwillbs.board.BoardBean"/>
   <!--전달된 정보 전부 저장-->
   <jsp:setProperty property="*" name="bb"/>
   <%=bb%>
 
   <%
    // bb 객체에 IP 주소 추가
    bb.setIp(request.getRemoteAddr());   
   %>
   <hr>
 
   <%=bb%>
   
   <%
    // DB 처리 객체 생성
    BoardDAO bDAO = new BoardDAO();
   
    // 글쓰기 메서드 호출
    bDAO.insertBoard(bb);
 
    // 글쓰기 이후 글 목록 페이지로 이동(list.jsp);
    response.sendRedirect("list.jsp");
   %>
    
</body>
```

<h2>사용자의 정보를 저장해서 전달되는 객체</h2>

```java
package com.itwillbs.board;
import java.util.Date;
 
public class BoardBean {
    // DTO(Data Transfer Object) => VO(Value Object)
    
    private int num;
    private String name;
    private String pass;
    private String subject;
    private String content;
    private int readcount;
    private int re_ref;
    private int re_lev;
    private int re_seq;
    private Date date;
    private String ip;
    private String file;
    
    public int getNum() {
        return num;
    }
    public void setNum(int num) {
        this.num = num;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getPass() {
        return pass;
    }
    public void setPass(String pass) {
        this.pass = pass;
    }
    public String getSubject() {
        return subject;
    }
    public void setSubject(String subject) {
        this.subject = subject;
    }
    public String getContent() {
        return content;
    }
    public void setContent(String content) {
        this.content = content;
    }
    public int getReadcount() {
        return readcount;
    }
    public void setReadcount(int readcount) {
        this.readcount = readcount;
    }
    public int getRe_ref() {
        return re_ref;
    }
    public void setRe_ref(int re_ref) {
        this.re_ref = re_ref;
    }
    public int getRe_lev() {
        return re_lev;
    }
    public void setRe_lev(int re_lev) {
        this.re_lev = re_lev;
    }
    public int getRe_seq() {
        return re_seq;
    }
    public void setRe_seq(int re_seq) {
        this.re_seq = re_seq;
    }
    public Date getDate() {
        return date;
    }
    public void setDate(Date date) {
        this.date = date;
    }
    public String getIp() {
        return ip;
    }
    public void setIp(String ip) {
        this.ip = ip;
    }
    public String getFile() {
        return file;
    }
    public void setFile(String file) {
        this.file = file;
    }
    
    @Override
    public String toString() {
        return "BoardBean [num=" + num + ", name=" + name + ", pass=" + pass + ", subject=" + subject + ", content="
                + content + ", readcount=" + readcount + ", re_ref=" + re_ref + ", re_lev=" + re_lev + ", re_seq="
                + re_seq + ", date=" + date + ", ip=" + ip + ", file=" + file + "]";
    }
    
}
```

<h2>DB의 테이블에 관련된 정보 처리 객체</h2>

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
    // Data Access Object => itwill_board 테이블에 관련된 정보 처리 객체
    
    Connection conn = null;
    PreparedStatement pstmt = null;
    ResultSet rs = null;
    String sql = "";
    
    
    // DB 연결 메서드 - 커넥션 풀 사용
    // => DB 연결 정보(Connection)를 미리 생성해서 pool에 저장
    // 사용 시 연결 정보 대여, 사용 후 반납 처리(기본처리 논리: 대기 -> 생성 후 반납)
    
    // 1. 라이브러리 설치
    // 2. context.xml 파일 생성(DB 연결 정보)
    // 3. 파일을 호출해서 DB 연결
    
    private Connection getConn() throws Exception{
        // 프로젝트 정보 초기화
        Context initCTX = new InitialContext();
        
        // 프로젝트에 있는 DB 연결 정보(이름)를 불러온다.
        DataSource ds = (DataSource)initCTX.lookup("java:comp/env/jdbc/mysqlDB");
        
        // DB 연결 
        conn = ds.getConnection();
        System.out.println("DAO:DB 연결 성공 "+conn);
        return conn;
    }
    
    // 자원 해제
    public void closeDB(){
        try {
            if(rs != null) rs.close();
            if(pstmt != null) pstmt.close();
            if(conn != null) conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    // 글쓰기 메서드() - insertBoard(bb)
    public void insertBoard(BoardBean bb){
        /*final String DRIVER = "com.mysql.jdbc.Driver";
        final String DBURL = "jdbc:mysql://localhost:3306/jspdb";
        final String DBID = "root";
        final String DBPW = "1234";*/
        
        int num = 0; /* 계산된 글 번호 저장 */
        
        try {
            // 1. 드라이버 로딩
            Class.forName(DRIVER);
            
            // 2. DB 연결
            Connection conn = DriverManager.getConnection(DBURL, DBID, DBPW);*/
            
            // 1,2 DB 연결(Connection pool)
            Connection conn = getConn();
            
            // 3. SQL 작성(select) & pstmt 객체 생성
            // select max(num) from itwill_board
            // => rs.next():true
            // => 함수의 결과는 항상 커서가 존재한다.(데이터 유무와 상관없다.)
            
            // select num from itwill_bard
            // => rs.next():false
            // => 함수의 결과가 데이터의 유무에 따라서 커서 유무가 결정된다.
            //    (원 모양)
            
            // 게시판 번호 계산
            String sql = "select max(num) from itwill_board";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            
            // 4. SQL 실행
            ResultSet rs = pstmt.executeQuery();
            
            // 5. 데이터 처리
            if(rs.next()){
                //num = rs.getInt("max(num)");
                num = rs.getInt(1)+1;
            }
            
            System.out.println("DAO 글번호:"+num);
            
            // 
            sql = "insert into itwill_board(num,name,pass,subject,content,"+
            "readcount,re_ref,re_lev,re_seq,date,ip,file)"+
            "values(?,?,?,?,?,?,?,?,?,now(),?,?)";
            
            pstmt = conn.prepareStatement(sql);
            pstmt.setInt(1, num);
            pstmt.setString(2, bb.getName());
            pstmt.setString(3, bb.getPass());
            pstmt.setString(4, bb.getSubject());
            pstmt.setString(5, bb.getContent());
            pstmt.setInt(6, 0); // 조회수 0
            pstmt.setInt(7, num); // re_ref 답글 그룹 번호 / 일반 글 번호 == 그룹 번호    
            pstmt.setInt(8, 0); // re_lev 답글 들여쓰기 / 일반 글 들여쓰기 없음(0)
            pstmt.setInt(9, 0); // re_seq 답글 순서 / 일반 글 0
            pstmt.setString(10, bb.getIp());
            pstmt.setString(11, bb.getFile());
            
            pstmt.executeUpdate();
            System.out.println("DAO:게시글 작성 완료");
            
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            System.out.println("DAO:드라이버 로딩 실패");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("DAO:DB 연결 실패");
        } catch (Exception e) {
            e.printStackTrace();
        }finally{
            closeDB();
        }
    }
    // 글쓰기 메서드() - insertBoard(bb)
    
    
    // getBoardCount()
    public int getBoardCount(){
        int cnt = 0;
        
        try {
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체 생성
            // 글의 총 개수를 계산
            sql = "select count(*) from itwill_board";
            pstmt = conn.prepareStatement(sql);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
            
            // 5. 데이터 처리
            if(rs.next()){
                cnt = rs.getInt(1); // 첨자, 처리 속도가 훨씬 빠르다.
                // cnt = rs.getInt("count(*)"); 컬럼명
            }
            
            System.out.println("DAO:글 개수 확인 "+cnt);
            
        } catch (Exception e) {
            e.printStackTrace();
        }finally{
            closeDB();
        }
        
        return cnt;
    }
    // getBoardCount()
    
    // getBoardList()
    public ArrayList getBoardList(){
        // ArrayList:가변 길이 배열(자동으로 배열의 크기를 지정)
        ArrayList boardList = new ArrayList();
        
        try {
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            sql = "select * from itwill_board";
            pstmt = conn.prepareStatement(sql);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
            
            // 5. 데이터 처리
            while(rs.next()){
                
                // 글 1개의 정보를 저장
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
                
                // 글 정보를 배열 1칸에 저장
                boardList.add(bb);
            }
            System.out.println("DAO:글 목록 저장 완료");
        } catch (Exception e) {
            e.printStackTrace();
        } finally{
            closeDB();
        }
    
        return boardList;
    }
    // getBoardList()
    
    // getBoardList() 오버로딩
    public ArrayList getBoardList(int startRow,int pageSize){
        ArrayList boardList = new ArrayList();
        
        try {
            // 1, 2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            // re_ref 내림차순, re_seq 오름차순
            // limit 시작행 - 1, 개수 => 원하는 개수만큼 짤라서 처리
            sql = "select * from itwill_board order by re_ref desc, re_seq asc limit ?,?";
            pstmt = conn.prepareStatement(sql);        
            
            pstmt.setInt(1, startRow-1);
            pstmt.setInt(2, pageSize);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
        
            // 5. 데이터 처리
            while(rs.next()){
                // 글 1개의 정보를 저장
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
                
                // 글 정보를 배열 1칸에 저장
                boardList.add(bb);
            }
            
            System.out.println("DAO:게시판 글 저장 완료(페이징 처리)");
        } catch (Exception e) {
            e.printStackTrace();
        }
    
        return boardList;
    }
}
```
