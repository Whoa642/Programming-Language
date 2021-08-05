<h3>장바구니에 상품을 추가하는 과정을 처리하는 BasketAddAction 객체</h3>

```java
package com.itwillbs.basket.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.basket.db.BasketDAO;
import com.itwillbs.basket.db.BasketDTO;
 
public class BasketAddAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: BasketAddAction_execute() 호출");
        // 장바구니 정보 저장하는 테이블 생성 - itwill_basket
        
        
        // 세션값 제어
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
 
        // 전달된 정보 저장 (num,amount,size,color)
        // baskeDTO 생성 후 정보 저장
        BasketDTO bkDTO = new BasketDTO();
        
        bkDTO.setB_g_num(Integer.parseInt(request.getParameter("num")));
        bkDTO.setB_g_amount(Integer.parseInt(request.getParameter("amount")));
        bkDTO.setB_g_size(request.getParameter("size"));
        bkDTO.setB_g_color(request.getParameter("color"));
        bkDTO.setB_m_id(id);
        
        // basketDAO 객체 생성
        // 1. 기존의 장바구니에 동일상품이 있는지 확인
        //    있을 경우: 수량변경(update)
        //    없을 경우: 상품등록(insert)
        
        BasketDAO bkDAO = new BasketDAO();
        int flag = bkDAO.checkGoods(bkDTO);
        
        System.out.println("M: 장바구니 확인 결과(0:없음, 1:있음) = "+flag);
        
        // 상품중복 여부 확인
        if(flag == 0){
            // 장바구니에 상품등록
            bkDAO.basketAdd(bkDTO);
        }
        
        // 페이지 이동
        forward.setPath("./BasketList.ba");
        forward.setRedirect(true);
        return forward;
    }
 
}
```

<h3>장바구니에 상품을 제거하는 과정을 처리하는 BaskekDeleteAction 객체</h3>

```java
package com.itwillbs.basket.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.basket.db.BasketDAO;
 
public class BasketDeleteAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request,
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: BasketDeleteAction_execute() 호출");        
        
        // 세션값 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();    
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;            
        }
        
        // 전달된 데이터 (b_num) 저장
        int b_num = Integer.parseInt(request.getParameter("b_num"));
        
        // BasketDAO 객체 - basketDelete(b_num);
        BasketDAO bkDAO = new BasketDAO();
        bkDAO.basketDelete(b_num);
        
        /// 페이지 이동 (V - ./BasketList.ba)
        forward.setPath("./BasketList.ba");
        forward.setRedirect(true);
        return forward;        
    }
}
```

<h3>장바구니의 상품을 나열하는 과정을 처리하는 BasketListAction 객체</h3>

```java
package com.itwillbs.basket.action;
 
import java.util.Vector;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
 
import com.itwillbs.basket.db.BasketDAO;
 
public class BasketListAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request,
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: BasketAddAction_execute() 호출");        
        
        // 세션값 제어
        HttpSession session = request.getSession();
        String id = (String)session.getAttribute("id");
        
        ActionForward forward = new ActionForward();    
        if(id == null){
            forward.setPath("./MemberLogin.me");
            forward.setRedirect(true);
            return forward;            
        }
        
        // BasketDAO 객세 생성 -> 해당 장바구니 정보
        // 구매수량 + 상품자체 정보
        BasketDAO bkDAO = new BasketDAO();
        Vector totalList = bkDAO.getBasketList(id);
                
        // request 영역 저장
        // request.setAttribute("totalList",totalList);
        request.setAttribute("basketList", totalList.get(0));
        request.setAttribute("goodsList", totalList.get(1));
        
        /// 페이지 이동 (V - ./basket/goods_basket_list.jsp)
        forward.setPath("./basket/goods_basket_list.jsp");
        forward.setRedirect(false);
        return forward;        
    }
}
```

<h3>장바구니의 상품을 나열하는 goods_basket_list.jsp 페이지</h3>

```jsp
<%@page import="com.itwillbs.basket.db.BasketDTO"%>
<%@page import="com.itwillbs.admin.goods.db.GoodsDTO"%>
<%@page import="java.util.Vector"%>
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
    <h1>WebContent/basket/goods_basket_list.jsp</h1>
    <%
        // request.setAttribute(totalList,"totalList");
        // Vector totalList = (Vector)request.getAttribute("totalList");
        // List basketList = (List)totalList.get(0);
        // List goodsList = (List)totalList.get(1);
        
        // request.setAttribute("basketList", totalList.get(0));
        // request.setAttribute("goodsList", totalList.get(1));        
        List<BasketDTO> basketList = (List)request.getAttribute("basketList");
        List<GoodsDTO> goodsList = (List)request.getAttribute("goodsList");
    %>
 
    <h2><%=session.getAttribute("id")%>님의 장바구니
    </h2>
    <table border="1">
        <tr>
            <td>번호</td>
            <td>이미지</td>
            <td>상품명</td>
            <td>사이즈</td>
            <td>컬러</td>
            <td>구매수량</td>
            <td>가격</td>
            <td>취소</td>
        </tr>
        
        <%for(int i = 0; i < basketList.size(); i++){ 
            BasketDTO bkDTO = basketList.get(i);
            GoodsDTO gDTO = goodsList.get(i);
        %>
        <tr>
            <td><%=bkDTO.getB_num() %></td>
            <td>
                <img src="./upload/<%=gDTO.getImage().split(",")[0] %>"
                    width="50" height="50">
            </td>
            <td><%=gDTO.getName() %></td>
            <td><%=bkDTO.getB_g_size() %></td>
            <td><%=bkDTO.getB_g_color() %></td>
            <td><%=bkDTO.getB_g_amount() %></td>
            <td><%=gDTO.getPrice() %></td>
            <td>
                <a href="./BasketDelete.ba?b_num=<%=bkDTO.getB_num()%>">취소</a>
            </td>
        </tr>    
        <%} %>    
    </table>
    
    <h3><a href="./OrderStart.or">[구매하기]</a></h3>
    <h3><a href="./GoodsList.go">[계속 쇼핑하기]</a></h3>
    <h3><a href="./">[]</a></h3>
 
</body>
</html>
```
