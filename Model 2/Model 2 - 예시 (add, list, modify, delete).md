<h3>상품등록 JSP 페이지 (admin_goods_add.jsp)</h3>

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/admin_goods/admin_goods_add.jsp</h1>
    <h2>관리자 상품등록 (Model2)</h2>
    
    <form action="./GoodsAddAction.ag" method="post" enctype="multipart/form-data">
        <table border="1">
            <tr>
                <td>카테고리</td>
                <td>
                    <select name="category"> 
                        <option value="outwear">겉옷</option>                        
                        <option value="fulldress">정장/신사복</option>                        
                        <option value="Tshirts">티셔츠</option>                        
                        <option value="shirts">셔츠</option>                        
                        <option value="pants">바지</option>
                        <option value="shoes">신발</option>
                    </select>
                </td>
            </tr>
            
            <tr>
                <td>상품명</td>
                <td>
                    <input type="text" name="name" >
                </td>            
            </tr>    
            
            <tr>
                <td>판매가격</td>
                <td><input type="text" name="price"></td>            
            </tr>
            
            <tr>
                <td>색상</td>
                <td><input type="text" name="color"></td>            
            </tr>
            
            <tr>
                <td>수량</td>
                <td><input type="text" name="amount"></td>            
            </tr>
            
            <tr>
                <td>크기</td>
                <td><input type="text" name="size"></td>            
            </tr>            
            
            <tr>
                <td>제품정보</td>
                <td><input type="text" name="content"></td>            
            </tr>
    
            <tr>
                <td>제품 이미지(메인)</td>
                <td><input type="file" name="file1"></td>            
            </tr>
    
            <tr>
                <td>제품 이미지1(본문)</td>
                <td><input type="file" name="file2"></td>        
            </tr>
            
            <tr>
                <td>제품 이미지2(본문)</td>
                <td><input type="file" name="file3"></td>            
            </tr>    
            
            <tr>
                <td>제품 이미지3(본문)</td>
                <td><input type="file" name="file4"></td>            
            </tr>    
            
            <tr>
                <td><input type="submit" value="상품등록"></td>
                <td><input type="reset" value="초기화"></td>
            </tr>                                                                    
        </table>
    </form>
</body>
</html>
```

<h3>상품등록을 처리하는 GoodsAddAction 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.AdminGoodsDAO;
import com.itwillbs.admin.goods.db.GoodsDTO;
import com.oreilly.servlet.MultipartRequest;
import com.oreilly.servlet.multipart.DefaultFileRenamePolicy;
 
public class GoodsAddAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, HttpServletResponse response) throws Exception {
        
        System.out.println("M: GoodsAddAction_execute() 호출");
        
        // 로그인 세션 제어 생략
        
 
        // 파일 업로드
        // upload 폴더 생성
        
        // 파일 저장 경로
        ServletContext ctx = request.getServletContext();
        String realPath = ctx.getRealPath("/upload");
        
        System.out.println("M: realPath = "+realPath);
                
        // 파일 업로드 크기 제한
        int maxSize = 10*1024*1024;
        
        // 파일 업로드 처리 - 객체 생성
        MultipartRequest multi = 
                new MultipartRequest(
                        request,
                        realPath,
                        maxSize,
                        "UTF-8",
                        new DefaultFileRenamePolicy()
                        );
        System.out.println("M: 파일 업로드 완료");
        
        // 상품 테이블 생성 (itwill_goods)
        // 전달된 상품정보 저장 (DTO)
        GoodsDTO gDTO = new GoodsDTO();
        gDTO.setAmount(Integer.parseInt(multi.getParameter("amount")));
        gDTO.setBest(0); // 인기 상품 - 1, 일반 상품 - 0
        gDTO.setCategory(multi.getParameter("category"));
        gDTO.setColor(multi.getParameter("color"));
        gDTO.setContent(multi.getParameter("content"));
    
        String image 
            = multi.getFilesystemName("file1")+", "
             +multi.getFilesystemName("file2")+", "
             +multi.getFilesystemName("file3")+", "
             +multi.getFilesystemName("file4");
        
        gDTO.setImage(image);
        //System.out.println("M: image = "+image);
        
        gDTO.setName(multi.getParameter("name"));
        gDTO.setPrice(Integer.parseInt(multi.getParameter("price")));
        gDTO.setSize(multi.getParameter("size"));
        
        System.out.println("M: 전달된 정보 저장 완료");
        
        // 한글 데이터 처리
        request.setCharacterEncoding("UTF-8");
        
        
        // DB에 정보 저장 (DAO) - insertGoods(DTO)
        AdminGoodsDAO gDAO = new AdminGoodsDAO();
        gDAO.insertGoods(gDTO);
        
 
        // 페이지 이동
        ActionForward forward = new ActionForward();
        forward.setPath("./AdminGoodsList.ag");
        forward.setRedirect(true);
        
        return forward;
    }
}
```

<h3>상품목록 JSP 페이지 (admin_goods_list.jsp)</h3>

```jsp
<%@page import="com.itwillbs.admin.goods.db.GoodsDTO"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/admin_goods/admin_goods_list.jsp</h1>
    <h2>관리자 상품목록 (Model2)</h2>    
    
    <h3><a href="./GoodsAdd.ag">상품등록 하기 (관리자)</a></h3>
    
    <%
        List<GoodsDTO> goodsList = (List)request.getAttribute("goodsList");        
    %>
    
    <table border="1">
        <tr>
            <td>번호</td>
            <td>카테고리</td>
            <td>사진</td>
            <td>상품명</td>
            <td>가격</td>
            <td>수량</td>
            <td>등록일자</td>
            <td>수정/삭제</td>            
        </tr>
        
        <%for(int i = 0; i < goodsList.size(); i++){ 
            GoodsDTO gDTO = goodsList.get(i);
        %>
            <tr>
                <td><%=gDTO.getNum() %></td>
                <td><%=gDTO.getCategory() %></td>
                <td>
                    <img src="./upload/<%=gDTO.getImage().split(",")[0] %>">
                </td> 
                <td><%=gDTO.getName() %></td>
                <td><%=gDTO.getPrice() %></td>
                <td><%=gDTO.getAmount() %></td>
                <td><%=gDTO.getDate() %></td>
                <td>
                <a href="./AdminGoodsModify.ag?num=<%=gDTO.getNum()%>">수정</a>
                /
                <a href="./AdminGoodsDelete.ag?num=<%=gDTO.getNum()%>">삭제</a>
                </td>            
            </tr>
        <%} %>
        
    </table>
</body>
</html>
```

<h3>상품목록을 처리하는 AdminGoodsListAction 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import java.util.List;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.AdminGoodsDAO;
import com.itwillbs.admin.goods.db.GoodsDTO;
 
public class AdminGoodsListAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: AdminGoodsListAction_execute() 호출");
        
        // DAO 객체 생성 - getGoodList();
        AdminGoodsDAO agDAO = new AdminGoodsDAO();
        List<GoodsDTO> goodsList = agDAO.getGoodsList();
        
        // view 페이지 전달 -> request 영역에 저장
        request.setAttribute("goodsList", goodsList);
        // request.setAttribute("goodsList", agDAO.getGoodsList());
        
        // 페이지 이동(forward)
        // ./admin_goods/admin_goods_list.jsp
        ActionForward forward = new ActionForward();
        forward.setPath("./admin_goods/admin_goods_list.jsp");
        forward.setRedirect(false);
        
        return forward;
    }
}
```

<h3>상품정보 수정  JSP 페이지 (admin_goods_modify.jsp)</h3>

```jsp
<%@page import="com.itwillbs.admin.goods.db.GoodsDTO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
    <h1>WebContent/admin_goods/admin_goods_modify.jsp</h1>
    <h2>관리자 상품정보 수정 (Model2)</h2>
    
    <%
        GoodsDTO gDTO = (GoodsDTO)request.getAttribute("gDTO");        
    %>
    
    <form action="./AdminGoodsModifyAction.ag" method="post">
        <input type="hidden" name="num" value="<%=gDTO.getNum() %>"> 
        <table border="1">
            <tr>
                <td>카테고리</td>
                <td>
                    <select name="category"> 
                        <option value="outwear"
                            <%if(gDTO.getCategory().equals("outwear")){ %> 
                            selected 
                            <%} %>
                        >겉옷</option>                        
                        <option value="fulldress"
                            <%if(gDTO.getCategory().equals("fulldress")){ %> 
                            selected 
                            <%} %>
                            >정장/신사복</option>                        
                        <option value="Tshirts"
                            <%if(gDTO.getCategory().equals("Tshirts")){ %> 
                            selected 
                            <%} %>
                        >티셔츠</option>                        
                        <option value="shirts"
                            <%if(gDTO.getCategory().equals("shirts")){ %> 
                            selected 
                            <%} %>
                        >셔츠</option>                        
                        <option value="pants"
                            <%if(gDTO.getCategory().equals("pants")){ %> 
                            selected 
                            <%} %>
                        >바지</option>
                        <option value="shoes"
                            <%if(gDTO.getCategory().equals("shoes")){ %> 
                            selected 
                            <%} %>
                        >신발</option>
                    </select>
                </td>
            </tr>
            
            <tr>
                <td>상품명</td>
                <td>
                    <input type="text" name="name" value="<%=gDTO.getName()%>">
                </td>            
            </tr>    
            
            <tr>
                <td>판매가격</td>
                <td><input type="text" name="price" value="<%=gDTO.getPrice()%>"></td>            
            </tr>
            
            <tr>
                <td>색상</td>
                <td><input type="text" name="color" value="<%=gDTO.getColor()%>"></td>            
            </tr>
            
            <tr>
                <td>수량</td>
                <td><input type="text" name="amount" value="<%=gDTO.getAmount()%>"></td>            
            </tr>
            
            <tr>
                <td>크기</td>
                <td><input type="text" name="size" value="<%=gDTO.getSize()%>"></td>            
            </tr>            
            
            <tr>
                <td>제품정보</td>
                <td><input type="text" name="content" value="<%=gDTO.getContent()%>"></td>            
            </tr>
 
            <tr>
                <td>인기상품</td>
                <td>
                    <input type="radio" name="best" value="1"
                        <%if(gDTO.getBest() == 1){ %> 
                        checked 
                        <%} %>
                    > 예
                    <input type="radio" name="best" value="0"
                        <%if(gDTO.getBest() == 0){ %> 
                        checked 
                        <%} %>
                    > 아니오
                </td>
            </tr>
                
            <tr>
                <td>제품 이미지(메인)</td>
                <td><input type="file" name="file1"></td>            
            </tr>
    
            <tr>
                <td>제품 이미지1(본문)</td>
                <td><input type="file" name="file2"></td>        
            </tr>
            
            <tr>
                <td>제품 이미지2(본문)</td>
                <td><input type="file" name="file3"></td>            
            </tr>    
            
            <tr>
                <td>제품 이미지3(본문)</td>
                <td><input type="file" name="file4"></td>            
            </tr>    
            
            <tr>
                <td><input type="submit" value="상품수정"></td>
                <td><input type="reset" value="초기화"></td>
            </tr>                                                                    
        </table>
    </form>
</body>
</html>
```

<h3>수정 전 상품정보를 반환하는 AdminGoodsModify 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.AdminGoodsDAO;
import com.itwillbs.admin.goods.db.GoodsDTO;
 
public class AdminGoodsModify implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, 
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: AdminGoodsModify_execute() 실행");
        
        // 전달받은 정보 num 저장
        int num = Integer.parseInt(request.getParameter("num"));
        
        // DAO 객체 - getAdminGoods(num);
        AdminGoodsDAO agDAO = new AdminGoodsDAO();
        GoodsDTO gDTO = agDAO.getAdminGoods(num);
        
        // request 영역에 데이터 저장
        request.setAttribute("gDTO",gDTO);
        
        // 페이지 이동 (view - ./admin_goods/admin_goods_modify.jsp)
        ActionForward forward = new ActionForward();
        forward.setPath("./admin_goods/admin_goods_modify.jsp");
        forward.setRedirect(false);
        
        return forward;        
    }
}
```

<h3>상품정보 수정을 처리하는 AdminGoodsModifyAction 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.AdminGoodsDAO;
import com.itwillbs.admin.goods.db.GoodsDTO;
 
public class AdminGoodsModifyAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request,
            HttpServletResponse response) throws Exception {
        
        System.out.println("M: AdminGoodsModifyAction_execute() 실행");
        
        // 한글 처리
        request.setCharacterEncoding("UTF-8");
        
        // 전달된 정보를 저장 (DTO)
        GoodsDTO gDTO = new GoodsDTO();
        
        gDTO.setAmount(Integer.parseInt(request.getParameter("amount")));
        gDTO.setBest(Integer.parseInt(request.getParameter("best")));
        gDTO.setCategory(request.getParameter("category"));
        gDTO.setColor(request.getParameter("color"));
        gDTO.setContent(request.getParameter("content"));
        gDTO.setName(request.getParameter("name"));
        gDTO.setNum(Integer.parseInt(request.getParameter("num")));
        gDTO.setPrice(Integer.parseInt(request.getParameter("price")));
        gDTO.setSize(request.getParameter("size"));
        
        // 수정할 정보를 출력
        System.out.println("M: 수정할 정보 "+gDTO);
        
        // 상품정보 DB에 수정
        // DAO - modifyGoods(gDTO);
        AdminGoodsDAO agDAO = new AdminGoodsDAO();
        agDAO.modifyGoods(gDTO);
        
        // 페이지 이동 (./AdminGoodsList.ag)
        ActionForward forward = new ActionForward();
        forward.setPath("./AdminGoodsList.ag");
        forward.setRedirect(true);
        
        return forward;
    }
}
```

<h3>상품삭제를 처리하는 AdminGoodsDeleteAction 객체</h3>

```java
package com.itwillbs.admin.goods.action;
 
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 
import com.itwillbs.admin.goods.db.AdminGoodsDAO;
 
public class AdminGoodsDeleteAction implements Action {
 
    @Override
    public ActionForward execute(HttpServletRequest request, HttpServletResponse response) throws Exception {
        
        System.out.println("M: AdminGoodsDeleteAction_execute() 실행");
        
        // 전달된 정보(num)
        int num = Integer.parseInt(request.getParameter("num"));
        
        // DAO 객체 생성 - deleteGoods(num);
        AdminGoodsDAO agDAO = new AdminGoodsDAO();
        agDAO.deleteGoods(num);
        
        // 페이지 이동 (./AdminGoodsList.ag)
        ActionForward forward = new ActionForward();
        forward.setPath("./AdminGoodsList.ag");
        forward.setRedirect(true);
        
        return forward;
    }
}
```
