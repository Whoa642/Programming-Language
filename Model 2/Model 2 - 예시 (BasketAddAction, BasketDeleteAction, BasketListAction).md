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
