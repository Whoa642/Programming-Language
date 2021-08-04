<h3>장바구니 정보를 저장하는 BasketDTO 객체</h3>

```java
package com.itwillbs.basket.db;
 
import java.util.Date;
 
public class BasketDTO {
    private int b_num;
    private String b_m_id;
    private int b_g_num;
    private int b_g_amount;
    private String b_g_size;
    private String b_g_color;
    private Date b_date;
    
    
    public int getB_num() {
        return b_num;
    }
    public void setB_num(int b_num) {
        this.b_num = b_num;
    }
    public String getB_m_id() {
        return b_m_id;
    }
    public void setB_m_id(String b_m_id) {
        this.b_m_id = b_m_id;
    }
    public int getB_g_num() {
        return b_g_num;
    }
    public void setB_g_num(int b_g_num) {
        this.b_g_num = b_g_num;
    }
    public int getB_g_amount() {
        return b_g_amount;
    }
    public void setB_g_amount(int b_g_amount) {
        this.b_g_amount = b_g_amount;
    }
    public String getB_g_size() {
        return b_g_size;
    }
    public void setB_g_size(String b_g_size) {
        this.b_g_size = b_g_size;
    }
    public String getB_g_color() {
        return b_g_color;
    }
    public void setB_g_color(String b_g_color) {
        this.b_g_color = b_g_color;
    }
    public Date getB_date() {
        return b_date;
    }
    public void setB_date(Date b_date) {
        this.b_date = b_date;
    }
    
    
    @Override
    public String toString() {
        return "BasketDTO [b_num=" + b_num + ", b_m_id=" + b_m_id + ", b_g_num=" + b_g_num + ", b_g_amount="
                + b_g_amount + ", b_g_size=" + b_g_size + ", b_g_color=" + b_g_color + ", b_date=" + b_date + "]";
    }
}
```

<h3>DB의 장바구니 정보를 처리하는 BasketDAO 객체</h3>

```java
package com.itwillbs.basket.db;
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;
 
public class BasketDAO {
    
        // 공통의 멤버 변수 (전역 변수, 인스턴스 변수)
        Connection conn = null;
        PreparedStatement pstmt = null;
        String sql = "";
        ResultSet rs = null;
        
        // 공통의 멤버 메서드
        // DB 연결 (Connection pool)
        private Connection getConn() throws Exception{
            // 프로젝트 정보를 초기화
            Context init = new InitialContext();
            init.lookup("java:comp/env/jdbc/model2");
            
            // 프로젝트에 있는 DB 연결 정보(이름) 가져오기
            DataSource ds = (DataSource)init.lookup("java:comp/env/jdbc/model2");
            
            // DB 연결
            //conn = ds.getConnection();
            //System.out.println("uDAO: DB 연결 성공 "+conn);
 
            return ds.getConnection();    
        }
        
        
        // 자원 해제
        public void closeDB(){
            try{
                if(rs != null)
                    rs.close();
                if(pstmt != null)
                    pstmt.close();
                if(conn != null)
                    conn.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
        }    
        // 자원 해제
        
        
        // 장바구니 상품확인
        public int checkGoods(BasketDTO bkDTO){
            int flag = 0;
            
            try{
                // 1,2. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 (id,num,size,color 옵션이 동일한 정보 조회) & pstmt 객체
                sql = "select * from itwill_basket "
                        + "where b_m_id=? and b_g_num=? and "
                        + "b_g_size=? and b_g_color=?";
                pstmt = conn.prepareStatement(sql);
                
                pstmt.setString(1, bkDTO.getB_m_id());
                pstmt.setInt(2, bkDTO.getB_g_num());
                pstmt.setString(3, bkDTO.getB_g_size());
                pstmt.setString(4, bkDTO.getB_g_color());
                
                // 4. SQL 실행
                rs = pstmt.executeQuery();
                
                // 5. 데이터 처리
                if(rs.next()){
                    // 장바구니에 들어있는 상품 => 기존의 상품 수량만 변경
                    sql = "update itwill_basket set b_g_amount = b_g_amount+? "
                            + "where b_m_id=? and b_g_num=? and "
                            + "b_g_size=? and b_g_color=?";
                    pstmt = conn.prepareStatement(sql);
                    
                    pstmt.setInt(1, bkDTO.getB_g_amount());
                    pstmt.setString(2, bkDTO.getB_m_id());
                    pstmt.setInt(3, bkDTO.getB_g_num());
                    pstmt.setString(4, bkDTO.getB_g_size());
                    pstmt.setString(5, bkDTO.getB_g_color());
 
                    flag = pstmt.executeUpdate();
                }
                System.out.println("bkDAO: 장바구니 - 상품확인");
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
            
            return flag;
        }
        // 장바구니 상품확인
        
        
        // 장바구니에 상품등록
        public void basketAdd(BasketDTO bkDTO){
            int b_num = 0;
            
            try{
                // 1,2. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 & pstmt 객체
                sql = "select max(b_num) from itwill_basket";
                pstmt = conn.prepareStatement(sql);
                
                // 4. SQL 실행
                rs = pstmt.executeQuery();
                if(rs.next()){
                    b_num = rs.getInt(1)+1;
                }
                
                System.out.println("bkDAO: b_num = "+b_num);
                
                // 3. SQL 작성 & pstmt 객체
                sql = "insert into itwill_basket values(?,?,?,?,?,?,now())";
                pstmt = conn.prepareStatement(sql);
                
                pstmt.setInt(1, b_num);
                pstmt.setString(2, bkDTO.getB_m_id());
                pstmt.setInt(3, bkDTO.getB_g_num());
                pstmt.setInt(4, bkDTO.getB_g_amount());
                pstmt.setString(5, bkDTO.getB_g_size());
                pstmt.setString(6, bkDTO.getB_g_color());
                
                // 4. SQL 실행
                pstmt.executeUpdate();
                System.out.println("bkDAO: 장바구니 상품등록 완료");
                
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
        }
        // 장바구니에 상품등록
 
 
        // 장바구니 반환
        public Vector getBasketList(String id){
            // 장바구니 정보 저장 (상품번호, 구매수량, 옵션 ...)
            List<BasketDTO> basketList = new ArrayList<BasketDTO>();
            // 상품정보 저장 (상품번호, 상품명, 가격, 이미지 ...)
            List<GoodsDTO> goodsList = new ArrayList<GoodsDTO>();
            // 장바구니 정보 + 상품정보 저장 리스트를 모두 저장하는 벡터
            Vector totalList = new Vector();
            
            try{
                // 1,2. DB 연결
                conn = getConn();
 
                // 3. SQL 구문 (장바구니 리스트) & pstmt 객체
                sql = "select * from itwill_basket where b_m_id=?";
                pstmt = conn.prepareStatement(sql);
                pstmt.setString(1, id);
                
                // 4. SQL 실행
                rs = pstmt.executeQuery();
                
                // 5. 데이터 처리
                while(rs.next()){
                    BasketDTO bkDTO = new BasketDTO();
                    
                    bkDTO.setB_date(rs.getDate("b_date"));
                    bkDTO.setB_g_amount(rs.getInt("b_g_amount"));
                    bkDTO.setB_g_color(rs.getString("b_g_color"));
                    bkDTO.setB_g_num(rs.getInt("b_g_num"));
                    bkDTO.setB_g_size(rs.getString("b_g_size"));
                    bkDTO.setB_m_id(rs.getString("b_m_id"));
                    bkDTO.setB_num(rs.getInt("b_num"));
                    
                    basketList.add(bkDTO);
                    
                    // 장바구니에 저장된 상품정보 조회
                    sql = "select * from itwill_goods where num=?";
                    PreparedStatement pstmt2 = conn.prepareStatement(sql);
                    pstmt2.setInt(1, bkDTO.getB_num());
                    
                    // 실행
                    ResultSet rs2 = pstmt2.executeQuery();
                    
                    if(rs2.next()){
                        GoodsDTO gDTO = new GoodsDTO();
                        gDTO.setPrice(rs2.getInt("price"));
                        gDTO.setName(rs2.getString("name"));
                        gDTO.setImage(rs2.getString("image"));
                        
                        // 추가정보 필요 시 구문 추가
                        goodsList.add(gDTO);
                    }
                }
                
                System.out.println("bkDAO: 장바구니 정보, 상품정보 저장 완료");
                System.out.println("bkDAO: 장바구니 갯수 = "+basketList.size());
                System.out.println("bkDAO: 상품 갯수 = "+goodsList.size());
                
                // Vector에 정보 저장
                totalList.add(basketList);
                totalList.add(goodsList);
                System.out.println("bkDAO: totaList 저장완료");
                
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
            return totalList;
        }
        // 장바구니 반환
        
        
        // 장바구니 상품 삭제
        public void basketDelete(int b_num){
            
            try{
                // 1,2. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 & pstmt 객체
                sql = "delete from itwill_basket where b_num=?";
                pstmt = conn.prepareStatement(sql);
                pstmt.setInt(1, b_num);
                
                // 4. SQL 실행
                int ret = pstmt.executeUpdate();
                
                System.out.println("bkDAO: 장바구니 삭제 = "+ret);
                
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
        }
        // 장바구니 상품 삭제
}
```

<h3>Model과 View를 연결하는 BasketFrontController 객체</h3>

```java
package com.itwillbs.basket.action;
 
import java.io.IOException;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
 
public class BasketFrontController extends HttpServlet {
    
    protected void doProcess(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("BasketFrontController_doProcess()");
        
        
        // --------------------1. 가상주소 계산-------------------------
        System.out.println();
        System.out.println("C: 가상주소 계산 시작");
        
        String requestURI = request.getRequestURI();
        System.out.println("C: requestURI = "+requestURI);
        
        String ctxPath = request.getContextPath();
        System.out.println("C: ctxPath = "+ctxPath);
        
        String command = requestURI.substring(ctxPath.length());
        System.out.println("C: command = "+command);
        
        System.out.println("C: 가상주소 계산 끝");
        // --------------------1. 가상주소 계산-------------------------
        
        
        // --------------------2. 가상주소 매핑-------------------------
        Action action = null;
        ActionForward forward = null;
 
        
        System.out.println();
        System.out.println("C: 가상주소 매핑 시작");
        
        if(command.equals("/BasketAdd.ba")){
            System.out.println("C: BasketAdd.ba 호출");
            System.out.println("C: DB 작업을 통한 저장");
            
            // BasketAddAction() 객체 생성
            action = new BasketAddAction();            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        }else if(command.equals("/BasketList.ba")){
            System.out.println("C: /BasketList.ba 호출");
            System.out.println("C: DB 정보를 가져와서 view에 출력");
            
            // BasketListAction() 객체 생성
            action = new BasketListAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        }else if(command.equals("/BasketDelete.ba")){
            System.out.println("C: /BasketDelete.ba 호출");        
            System.out.println("C: DB 정보 삭제 후 List로 이동");        
            
            // BasketDeleteAction() 객체 생성
            action = new BasketDeleteAction();
            
            try{
                forward = action.execute(request, response);
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        
        System.out.println("C: 가상주소 매핑 끝");
        
        // --------------------2. 가상주소 매핑-------------------------
        
        
        // --------------------3. 페이지 이동-------------------------
        System.out.println();
        System.out.println("C: 페이지 이동 시작");
        
        if(forward != null){
            if(forward.isRedirect()){
            // true
                System.out.println("C: 방식 = sendRedirect, 주소 = "+forward.getPath());
                response.sendRedirect(forward.getPath());
            }else{
            // false
                System.out.println("C: 방식 = forward, 주소 = "+forward.getPath());
                RequestDispatcher dis = 
                        request.getRequestDispatcher(forward.getPath());
                dis.forward(request, response);
            }
        }
        System.out.println("C: 페이지 이동 끝\n\n\n\n");
        // --------------------3. 페이지 이동-------------------------    
            
    }
    
    @Override
    protected void doGet(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("BasketFrontController_doGet()");
        doProcess(request,response);
    }
 
    @Override
    protected void doPost(HttpServletRequest request, 
            HttpServletResponse response) throws ServletException, IOException {
        System.out.println("BasketFrontController_doPost()");
        doProcess(request,response);
    }
}
```
