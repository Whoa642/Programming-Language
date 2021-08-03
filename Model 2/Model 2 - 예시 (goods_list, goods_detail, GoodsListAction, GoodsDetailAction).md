<h3>상품목록을 출력하는 goods_list.jsp 페이지</h3>

```jsp
<%@page import="com.itwillbs.admin.goods.db.GoodsDTO"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
 
    <h1>WebContent/goods/goods_list.jsp</h1>
    
    <%
        List<GoodsDTO> goodsList = (List)request.getAttribute("goodsList");            
    %>
    
    <table border="1">
        <tr>
            <td><a href="./GoodsList.go">전체</a></td>
            <td><a href="./GoodsList.go?item=best">인기상품(Best)</a></td>
            <td><a href="./GoodsList.go?item=outwear">겉옷</a></td>
            <td><a href="./GoodsList.go?item=fulldress">정장/신사복</a></td>
            <td><a href="./GoodsList.go?item=Tshirts">티셔츠</a></td>
            <td><a href="./GoodsList.go?item=shirts">셔츠</a></td>
            <td><a href="./GoodsList.go?item=pants">바지</a></td>
            <td><a href="./GoodsList.go?item=shoes">신발</a></td>
        </tr>
        
        <% 
            // 상품개수
            int size = goodsList.size();
        
            // 열의 개수 (가로)
            int col = 8;
            
            // 행의 개수 (쎄로)
            int row = (size%col == 0) ? size/col : size/col+1;
            // row = (size/col)+(size%col > 0 ? 1 : 0);
            
            // 카운트 변수
            int cnt = 0;
            
            for(int i = 0; i < row; i++){
                %>
                <tr>
                        
                <% 
                for(int j = 0; j < col ; j++){ 
                    if(cnt >= size) break;
                    GoodsDTO gDTO = goodsList.get(cnt++);
                    %>
                    <td>
                        <img src="./upload/<%=gDTO.getImage().split(",")[0]%>" width="150" height="150"> <br>
                        <a href="./GoodsDetail.go?num=<%=gDTO.getNum()%>"><%=gDTO.getName()%></a><br>
                        <%=gDTO.getPrice()%>원<br>                        
                    </td>
                    <%
                }
                %>
                </tr>
                <% 
            }
            
        %>
    </table>
    
</body>
</html>
```

<h3>상품목록을 DB에서 가져오는 GoodsListAction 객체</h3>

```java
package com.itwillbs.goods.action;
 
import java.util.List;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.GoodsDTO;
import com.itwillbs.goods.db.GoodsDAO;
 
 
public class GoodsListAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, HttpServletResponse response) throws Exception {
 
        System.out.println("M: GoodsListAction_execute() 호출");
        
        // 출력할 목록의 구분값을 확인 (전체/인기상품/카테고리)
        String item = request.getParameter("item");
        
        if(item == null)
            item = "ALL";
        
        System.out.println("M: 상품목록 정보 - "+item);
        
        // DB 정보를 가져와서 저장
        // GoodsDAO - itwill_goods 테이블 사용
        // getGoodsList();
        
        GoodsDAO gDAO = new GoodsDAO();
        // List<GoodsDTO> goodsList = gDAO.getGoodsList();
        List<GoodsDTO> goodsList = gDAO.getGoodsList(item);
        
        // request 영역에 저장
        request.setAttribute("goodsList", goodsList);
        
        // 페이지 이동 (view ./goods/goods_list.jsp)
        ActionForward forward = new ActionForward();
        forward.setPath("./goods/goods_list.jsp");
        forward.setRedirect(false);
        
        return forward;
    }
}
```

<h3>상품정보를 출력하는 goods_detail.jsp 페이지</h3>

```jsp
<%@page import="com.itwillbs.goods.db.GoodsDAO"%>
<%@page import="com.itwillbs.admin.goods.db.GoodsDTO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
    <script type="text/javascript">
        function isBasket(){
            alert('장바구니 실행');
            // 장바구니 페이지로 submit (이동)
            
            // 구매 수량, 크기, 색상 입력 확인
            if(document.gfr.amount.value == ""){
                alert('최소 구매 수량은 1개 입니다.');
                document.gfr.amount.value = 1;
                document.gfr.amount.focus();
                return;
            }
            
            if(document.gfr.size.value == ""){
                alert('크기를 선택하세요.');
                document.gfr.size.focus();                
 
                return;
            }
            
            if(document.gfr.color.value == ""){
                alert('색상을 선택하세요.');
                document.gfr.color.focus();                
                return;
            }
 
            // 입력 완료 시 "장바구니에 저장하시겠습니까?" yes/no
            // yes: 페이지 이동
            // no: 페이지 대기
            var flag = confirm("장바구니에 저장하시겠습니까?");
            
            if(flag){
                // 장바구니 페이지로 이동 (submit)
                document.gfr.action = './BasketAdd.ba';
                document.gfr.submit();
            }else{
                return;
            }
            
        }    
    </script>
</head>
<body>
    <h1>WebContent/goods/goods_detail.jsp</h1>
    <h2>제품 상세 페이지</h2>
    
    <%
        GoodsDTO gDTO = (GoodsDTO)request.getAttribute("gDTO");
    %>
    
    <form action="" name="gfr" method="post">
        <input type="hidden" name="num" value="<%=gDTO.getNum() %>">
        
        <table border="1">
            <tr>
                <td>
                    <img src="./upload/<%=gDTO.getImage().split(",")[0]%>"
                        width="300" height="300"
                    >
                </td>
                <td>
                    <h3>상품명: <%=gDTO.getName() %></h3>
                    <h3>판매가격: <%=gDTO.getPrice() %>원</h3>
                    <h3>구매수량: <input type="number" name="amount" value="1">개</h3>
                    <h3>잔여수량: <%=gDTO.getAmount() %>개</h3>
                    크기: <select name="size">
                            <option value="">크기 선택</option>
                            <c:forTokens var="size" items="<%=gDTO.getSize() %>" delims=",">
                                <option value="${size }">${size }</option>
                            </c:forTokens>
                        </select> <br>
                    색깔: <select name="color">
                            <option value="">색깔 선택</option>
                            <c:forTokens var="color" items="${gDTO.color }" delims=",">
                                <option value="${color }">${color }</option>
                            </c:forTokens>
                            
                        </select>
                    <hr>
                    <a href="javascript:isBasket();">[장바구니 담기]</a><br>
                    <a href="#">[바로 구매하기]</a><br>
                    
                </td>
            </tr>
            
            <tr>
                <td colspan="2">상품 본문내용
                    <img src="./upload/<%=gDTO.getImage().split(",")[1]%>">
                </td>
            </tr>
            
            <tr>
                <td colspan="2">리뷰 및 질문 (Q&A)</td>        
            </tr>
        </table>
    </form>
</body>
</html>
```

<h3>상품정보를 DB에서 가져오는 GoodsDetailAction 객체</h3>

```java
package com.itwillbs.goods.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.GoodsDTO;
import com.itwillbs.goods.db.GoodsDAO;
 
public class GoodsDetailAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, HttpServletResponse response) throws Exception {
        
        System.out.println("M: GoodsDetailAction_execute() 호출");
        
        // 전달된 정보 (num) 저장
        int num = Integer.parseInt(request.getParameter("num"));
        System.out.println("M: 상품번호 = "+num);
        
        // DAO 객체 생성 - getGoods(num);
        GoodsDAO gDAO = new GoodsDAO();
        GoodsDTO gDTO = gDAO.getGoods(num);
        
        // DB에서 가져온 상품정보를 request 영역에 저장
        request.setAttribute("gDTO",gDTO);
        
        // 페이지 이동 (view - ./goods/goods_detail.jsp)
        ActionForward forward = new ActionForward();
        forward.setPath("./goods/goods_detail.jsp");
        forward.setRedirect(false);
        
        return forward;
    }
}
```
