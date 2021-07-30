<h3>상품 정보를 저장하는 GoodsDTO 객체</h3>

```java
package com.itwillbs.admin.goods.db;
 
public class GoodsDTO {
    private int num;
    private String category;
    private String name;
    private String content;
    private String size;
    private String color;
    private int amount;
    private int price;
    private String image;
    private int best;
    private String date;
    
    
    public int getNum() {
        return num;
    }
    public void setNum(int num) {
        this.num = num;
    }
    public String getCategory() {
        return category;
    }
    public void setCategory(String category) {
        this.category = category;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getContent() {
        return content;
    }
    public void setContent(String content) {
        this.content = content;
    }
    public String getSize() {
        return size;
    }
    public void setSize(String size) {
        this.size = size;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public int getAmount() {
        return amount;
    }
    public void setAmount(int amount) {
        this.amount = amount;
    }
    public int getPrice() {
        return price;
    }
    public void setPrice(int price) {
        this.price = price;
    }
    public String getImage() {
        return image;
    }
    public void setImage(String image) {
        this.image = image;
    }
    public int getBest() {
        return best;
    }
    public void setBest(int best) {
        this.best = best;
    }
    public String getDate() {
        return date;
    }
    public void setDate(String date) {
        this.date = date;
    }
    
    
    @Override
    public String toString() {
        return "GoodsDTO [num=" + num + ", category=" + category + ", name=" + name + ", content=" + content + ", size="
                + size + ", color=" + color + ", amount=" + amount + ", price=" + price + ", image=" + image + ", best="
                + best + ", date=" + date + "]";
    }   
}
```

<h3>DB의 상품 정보를 처리하는 AdminGoodsDAO 객체</h3>

```java
package com.itwillbs.admin.goods.db;
 
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
 
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;
 
import com.itwillbs.member.db.MemberDTO;
 
public class AdminGoodsDAO {
    
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
        
        
        // 상품등록
        public void insertGoods(GoodsDTO gDTO){
            int num = 0;
            try{
                // 1,2,. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 & pstmt 객체
                
                // 3.1 상품번호(num) 계산 => 게시판 글번호 계산
                sql = "select max(num) from itwill_goods";
                pstmt = conn.prepareStatement(sql);
                
                rs = pstmt.executeQuery();
                if(rs.next()){
                    num = rs.getInt(1)+1;
                }
                
                System.out.println("agDAO: 상품번호 = "+num);
                
                // 3.2  상품등록
                sql = "insert into itwill_goods values(?,?,?,?,?,?,?,?,?,?,now())";
                pstmt = conn.prepareStatement(sql);
                
                pstmt.setInt(1, num);
                pstmt.setString(2, gDTO.getCategory());
                pstmt.setString(3, gDTO.getName());
                pstmt.setString(4, gDTO.getContent());
                pstmt.setString(5, gDTO.getSize());
                pstmt.setString(6, gDTO.getColor());
                pstmt.setInt(7, gDTO.getAmount());
                pstmt.setInt(8, gDTO.getPrice());
                pstmt.setString(9, gDTO.getImage());
                pstmt.setInt(10,gDTO.getBest());
                
                // 4. SQL 실행
                pstmt.executeUpdate();
                
                System.out.println("agDAO: 관리자 상품등록 저장완료");
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
        }
        // 상품등록
 
        
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
                    
                    gDTO.setAmount(rs.getInt("num"));
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
                System.out.println("agDAO: 관리자 상품목록 저장완료");
            }catch(Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
            
            return goodsList;
            
        }
        // 상품목록
 
 
        // 상품정보
        public GoodsDTO getAdminGoods(int num){
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
                System.out.println("agDAO: 상품정보 저장 완료 ("+num+"번)");
            }catch (Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
            
            return gDTO;
        }
        // 상품정보
        
        
        // 상품정보 수정
        public void modifyGoods(GoodsDTO gDTO){
            
            try{
                // 1,2. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 & pstmt 객체
                sql = "update itwill_goods set category=?,name=?,color=?,"
                        + "amount=?,size=?,best=?,content=?,price=? where num=?";
                pstmt = conn.prepareStatement(sql);
                
                pstmt.setString(1, gDTO.getCategory());
                pstmt.setString(2, gDTO.getName());
                pstmt.setString(3, gDTO.getColor());
                pstmt.setInt(4, gDTO.getAmount());
                pstmt.setString(5, gDTO.getSize());
                pstmt.setInt(6, gDTO.getBest());
                pstmt.setString(7, gDTO.getContent());
                pstmt.setInt(8, gDTO.getPrice());
                pstmt.setInt(9, gDTO.getNum());
                
                // 4. SQL 실행
                pstmt.executeUpdate();
                
                System.out.println("agDAO: 관리자 - 상품수정 완료");
                
            }catch (Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
        }
        // 상품정보 수정
        
        
        // 상품삭제
        public void deleteGoods(int num){
            
            try{
                // 1,2. DB 연결
                conn = getConn();
                
                // 3. SQL 작성 & pstmt 객체
                sql = "delete from itwill_goods where num=?";
                pstmt = conn.prepareStatement(sql);
                
                pstmt.setInt(1, num);
        
                // 4. SQL 실행
                pstmt.executeUpdate();
                
                System.out.println("agDAO: 관리자 - 상품삭제 완료");
                
            }catch (Exception e){
                e.printStackTrace();
            }finally{
                closeDB();
            }
        }            
        // 상품삭제
}
```
