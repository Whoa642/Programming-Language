<h2>주문 상세 페이지 이동을 구현하는 OrderStartAction 객체</h2>

```java
package com.itwillbs.order.action;
 
import java.util.List;
import java.util.Vector;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
 
import com.itwillbs.basket.db.BasketDAO;
import com.itwillbs.member.db.MemberDAO;
import com.itwillbs.member.db.MemberDTO;
 
public class OrderStartAction implements Action {
 
    @Override
    public com.itwillbs.order.action.ActionForward execute(HttpServletRequest request, HttpServletResponse response) throws Exception {
 
        System.out.println("M: OrderStartAction_execute() 호출");
        
        // 세션 처리
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();    
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;            
        }
        
        // 주문동작 -> 구매상품의 정보를 저장
        // 구매상품의 정보 -> 장바구니 
        // 1) 장바구니 정보 2) 상품정보 3) 구매자 정보
        
        // 장바구니, 상품 정보 (itwill_basket)
        BasketDAO bkDAO = new BasketDAO();
        Vector totalList = bkDAO.getBasketList(id);
        
        List basketList = (List)totalList.get(0);
        List goodsList = (List)totalList.get(1);
        
        // 구매자 정보 (itwill_member)
        MemberDAO mDAO = new MemberDAO();
        MemberDTO mDTO = mDAO.getMember(id);
        
        // request 영역 저장
        request.setAttribute("basketList", basketList);
        request.setAttribute("goodsList", goodsList);
        request.setAttribute("mDTO", mDTO);
 
        // 페이지 이동 (V - ./goods_order/goods_buy.jsp)
        forward.setPath("./goods_order/goods_buy.jsp");
        forward.setRedirect(false);
        return forward;
    }
    
}
```


<h2>주문 정보를 저장하는 OrderAddAction 객체</h2>

```java
package com.itwillbs.order.action;
 
import java.util.List;
import java.util.Vector;
 
import javax.management.RuntimeErrorException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.admin.goods.db.GoodsDTO;
import com.itwillbs.basket.db.BasketDAO;
import com.itwillbs.basket.db.BasketDTO;
import com.itwillbs.goods.db.GoodsDAO;
import com.itwillbs.order.db.OrderDAO;
import com.itwillbs.order.db.OrderDTO;
 
public class OrderAddAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
 
        System.out.println("M: OrderAddAction_execute() 호출");
        
        
        // 세션 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;                        
        }
        
        // 한글 처리
        request.setCharacterEncoding("UTF-8");
        
        // goods_buy_jsp
        // 전달된 매개변수 저장 -> 배송지 정보 + 결재 정보 -> OrderDTO 객체 생성
        OrderDTO oDTO = new OrderDTO();
        oDTO.setO_m_id(id);
        oDTO.setO_r_name(request.getParameter("o_r_name"));    
        oDTO.setO_r_addr1(request.getParameter("o_r_addr1"));
        oDTO.setO_r_addr2(request.getParameter("o_r_addr2"));
        oDTO.setO_r_phone(request.getParameter("o_r_phone"));
        oDTO.setO_r_msg(request.getParameter("o_r_msg"));
        
        oDTO.setO_trade_payer(request.getParameter("o_trade_payer"));
        oDTO.setO_trade_type(request.getParameter("o_trade_type"));
        
        System.out.println("M: 전달된 정보 완료");
        System.out.println("M:"+oDTO);
        
        // 구매한 상품정보를 추가적으로 DAO로 전달
        // 장바구니 객체 생성
        BasketDAO bkDAO = new BasketDAO();
        Vector totalList = bkDAO.getBasketList(id);
        
        // 장바구니 정보 List
        List<BasketDTO> basketList = (List)totalList.get(0);
        
        // 상품정보 List
        List<GoodsDTO> goodsList =  (List)totalList.get(1);
        
        // 결제 모듈 호출 (U+/카카오페이/네이버페이)
        
        // OrderDAO 객체 생성
        // addOrder(orderDTO, basketList, goodsList);
        OrderDAO oDAO = new OrderDAO();
        oDAO.addOrder(oDTO, basketList, goodsList);
        
        
        // 메일, 문자, 메세지 전달 - 호출 (멀티쓰레딩)
        // 익명 클래스
        new Thread(new Runnable() {
            
            @Override
            public void run() {
                for(int i = 0; i < 100000000000000L; i++);
                System.out.println("메일 보내기");
            }
        }).start();
        
        System.out.println("M: 주문정보 저장완료");
        
        // 상품의 구매수량 제거 (update)
        // 상품처리하는 객체 GoodsDAO 객체 생성
        GoodsDAO gDAO = new GoodsDAO();
        gDAO.updateAmount(basketList);
        
        // 장바구니 정보 삭제 (delete) - 특정 사용자의 정보를 삭제 (id)
        bkDAO.basketDelete(id);
        
        // 페이지 이동 (./OrderList.or)
        forward.setPath("./OrderList.or");
        forward.setRedirect(true);
        return forward;
    }
}
```

<h2>주문 상세 페이지를 보여주는 goods_buy.jsp 페이지</h2>

```jsp
<%@page import="com.itwillbs.member.db.MemberDTO"%>
<%@page import="com.itwillbs.basket.db.BasketDTO"%>
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
    <h1>WebContent/goods_order/goods_buy.jsp</h1>
    
    <%
        List<BasketDTO> basketList = (List)request.getAttribute("basketList");
        List<GoodsDTO> goodsList = (List)request.getAttribute("goodsList");
        MemberDTO mDTO = (MemberDTO)request.getAttribute("mDTO");
    %>
    
    <h2>주문상세 페이지</h2>
    <form action="./OrderAddAction.or" method="post">
    <!--배송지, 결제 정보만 전달
        장바구니 정보/상품정보는 없다. (DB에서 조회)
    -->
        <table border="1">
            <tr>
                <td colspan="6">
                    <h3>주문상품 정보</h3>
                </td>
            </tr>
                
            <tr>
                <td>상품사진</td>
                <td>상품명</td>
                <td>구매수량</td>
                <td>구매옵션(크기)</td>
                <td>구매옵션(색상)</td>
                <td>가격</td>            
            </tr>
            
            <%
                int total = 0;
                for(int i = 0; i < basketList.size(); i++){ 
                    BasketDTO bkDTO = basketList.get(i);    
                    GoodsDTO gDTO = goodsList.get(i);
                    total += bkDTO.getB_g_amount()*gDTO.getPrice();
            %>
            
            <tr>
                <td>
                    <img src="./upload/<%=gDTO.getImage().split(",")[0] %>"
                        width="50" height="50">
                </td>
                <td>
                    <a href="./GoodsDetail.go?num=<%=bkDTO.getB_g_num()%>"><%=gDTO.getName() %></a>
                </td>
                <td><%=bkDTO.getB_g_amount() %></td>
                <td><%=bkDTO.getB_g_size() %></td>
                <td><%=bkDTO.getB_g_color() %></td>
                <td><%=gDTO.getPrice() %></td>            
            </tr>
            <%} %>
    
    
            <tr>
                <td colspan="6">
                    <h3>총 가격:<%=total %></h3>
                </td>
            </tr>
                    
                    
            <tr>
                <td colspan="6">
                    <h3>주문자 정보</h3>
                </td>
            </tr>
            
            
            <tr>
                <td colspan="6">
                    <h5>이름: <%=mDTO.getName() %></h5>
                    <h5>전화번호: </h5>
                    <h5>이메일 주소: <%=mDTO.getEmail() %></h5>
                </td>
            </tr>
    
    
            <tr>
                <td colspan="6">
                    <h3>배송지 정보</h3>
                </td>
            </tr>
            
            
            <tr>
                <td colspan="6">
                    <h5>받는 사람: <input type="text" name="o_r_name" value="<%=mDTO.getName()%>"></h5>                
                    <h5>전화번호: <input type="text" name="o_r_phone"></h5>                
                    <h5>배송지 주소: <input type="text" name="o_r_addr1"></h5>                
                    <h5>배송지 세부주소: <input type="text" name="o_r_addr2"></h5>                
                    <h5>요청사항: <input type="text" name="o_r_msg"></h5>                
                </td>
            </tr>
            
    
            <tr>
                <td colspan="6">
                    <h3>결제 정보</h3>
                </td>
            </tr>
            
            
            <tr>
                <td colspan="6">
                    <h5>입금자명(온라인): <input type="text" name="o_trade_payer" value=<%=mDTO.getName() %>></h5>
                    <input type="radio" name="o_trade_type" value="신용카드">신용카드<br>
                    <input type="radio" name="o_trade_type" value="체크카드">체크카드<br>
                    <input type="radio" name="o_trade_type" value="카카오페이">카카오페이<br>
                    <input type="radio" name="o_trade_type" value="네이버페이">네이버페이<br>
                    <input type="radio" name="o_trade_type" value="온라인입금" checked>온라입입금<br>
                </td>
            </tr>
            
            
            <tr>
                <td colspan="6">
                    <input type="submit" value="주문하기">
                    <input type="reset" value="취소하기">
                </td>
            </tr>
                    
        </table>
    </form>
</body>
</html>
```
