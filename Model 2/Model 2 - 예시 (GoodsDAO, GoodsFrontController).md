<h3>DB의 상품 정보를 처리하는 GoodsDAO 객체</h3>

```jsp
package com.itwillbs.goods.db;
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;
 
import com.itwillbs.admin.goods.db.GoodsDTO;
 
public class GoodsDAO {
    
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
    
    
    // 상품목록 
    public List<GoodsDTO> getGoodsList(){
        List<GoodsDTO> goodsList = new ArrayList<GoodsDTO>();
    
        try{
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            sql = "select * from itwill_goods";
            pstmt = conn.prepareStatement(sql);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
                    
            // 5. 데이터 처리
            while(rs.next()){
                GoodsDTO gDTO = new GoodsDTO();
            
                gDTO.setAmount(rs.getInt("amount"));
                gDTO.setBest(rs.getInt("best"));
                gDTO.setCategory(rs.getString("category"));
                gDTO.setColor(rs.getString("color"));
                gDTO.setContent(rs.getString("content"));
                gDTO.setDate(rs.getString("date"));
                gDTO.setImage(rs.getString("image"));
                gDTO.setName(rs.getString("name"));
                gDTO.setNum(rs.getInt("num"));
                gDTO.setPrice(rs.getInt("price"));
                gDTO.setSize(rs.getString("size"));
                
                goodsList.add(gDTO);
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally{
            closeDB();
        }
        
        return goodsList;
    }
    // 상품목록
    
    // String -> 메서드를 통한 실행정보 저장 X -> 바로 사용, 기존값 변경 x
    // StringBuffer -> 메서드를 통한 실행정보 저장 O -> 기존값 변경 O
    
    // 상품목록 오버라이딩
    public List<GoodsDTO> getGoodsList(String item){
        List<GoodsDTO> goodsList = new ArrayList<GoodsDTO>();
        StringBuffer SQL = new StringBuffer();
        
        try{
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            // sql = "select * from itwill_goods";
            SQL.append("select * from itwill_goods ");
            
            if(item.equals("ALL")) {}
            else if(item.equals("best")) SQL.append("where best=?");
            else SQL.append("where category=?");
        
            pstmt = conn.prepareStatement(SQL.toString());
 
            if(item.equals("ALL")) {}
            else if(item.equals("best")) pstmt.setInt(1, 1);
            else pstmt.setString(1, item);            
            
            
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
                    
            // 5. 데이터 처리
            while(rs.next()){
                GoodsDTO gDTO = new GoodsDTO();
            
                gDTO.setAmount(rs.getInt("amount"));
                gDTO.setBest(rs.getInt("best"));
                gDTO.setCategory(rs.getString("category"));
                gDTO.setColor(rs.getString("color"));
                gDTO.setContent(rs.getString("content"));
                gDTO.setDate(rs.getString("date"));
                gDTO.setImage(rs.getString("image"));
                gDTO.setName(rs.getString("name"));
                gDTO.setNum(rs.getInt("num"));
                gDTO.setPrice(rs.getInt("price"));
                gDTO.setSize(rs.getString("size"));
                
                goodsList.add(gDTO);
            }
            
            System.out.println("gDAO: "+item+" 정보 리스트 조회 완료");
        }catch (Exception e){
            e.printStackTrace();
        }finally{
            closeDB();
        }
        
        return goodsList;
    }
    // 상품목록 오버라이딩
    
    
    // 상품정보
    public GoodsDTO getGoods(int num){
        GoodsDTO gDTO = null;
        
        try{
            
            // 1,2. DB 연결
            conn = getConn();
            
            // 3. SQL 작성 & pstmt 객체
            sql = "select * from itwill_goods where num=?";
            pstmt = conn.prepareStatement(sql);
            
            pstmt.setInt(1, num);
            
            // 4. SQL 실행
            rs = pstmt.executeQuery();
            
            // 5. 데이터 처리
            if(rs.next()){
                gDTO = new GoodsDTO();
                
                gDTO.setAmount(rs.getInt("amount"));
                gDTO.setBest(rs.getInt("best"));
                gDTO.setCategory(rs.getString("category"));
                gDTO.setColor(rs.getString("color"));
                gDTO.setContent(rs.getString("content"));
                gDTO.setDate(rs.getString("date"));
                gDTO.setImage(rs.getString("image"));
                gDTO.setName(rs.getString("name"));
                gDTO.setNum(rs.getInt("num"));
                gDTO.setPrice(rs.getInt("price"));
                gDTO.setSize(rs.getString("size"));
                
            }
            System.out.println("gDAO: "+num+"번 상품정보 저장완료");
            System.out.println("gDAO: "+gDTO);
        }catch (Exception e){
            e.printStackTrace();
        }finally{
            closeDB();
        }
        
        return gDTO;
    }
    // 상품정보 
}
```

<h3>Model과 Veiw를 연결하는 GoodsFrontController 객체</h3>

```java
package com.itwillbs.goods.action;
 
import java.io.IOException;
 
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
public class GoodsFrontController extends HttpServlet {
 
        protected void doProcess(HttpServletRequest request, 
                HttpServletResponse response) throws ServletException, IOException {
            System.out.println("GoodsFrontController_doProcess()");
            
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
            
            if(command.equals("/GoodsList.go")){
                System.out.println("C: /GoodsList.go 호출");
                System.out.println("C: DB 정보를 가져와서 화면(view)에 출력");
                
                // GoodsListAction() 객체 생성
                action = new GoodsListAction();
                
                try{
                    forward = action.execute(request, response);
                }catch (Exception e){
                    e.printStackTrace();
                }
            }else if(command.equals("/GoodsDetail.go")){
                System.out.println("C: /GoodsDetail.go 호출");
                System.out.println("C: DB 정보를 가져와서 화면(view)에 출력");
                
                // GoodsDetailAction() 객체 생성
                action = new GoodsDetailAction();
                
                try{
                    forward = action.execute(request, response);
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
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
            System.out.println("AdminGoodsFrontController_doGet()");
            doProcess(request,response);
        }
 
        @Override
        protected void doPost(HttpServletRequest request, 
                HttpServletResponse response) throws ServletException, IOException {
            System.out.println("AdminGoodsFrontController_doPost()");
            doProcess(request,response);
        }
}
```
