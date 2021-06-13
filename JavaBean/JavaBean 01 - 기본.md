<b>자바빈(JavaBean)</b>은 디자인 부분과 비즈니스 로직 부분을 분리하기 위해서 사용한다. <b><i>만들어진 클래스가 자바빈의 특성을 가지려면 반드시 규정되어있는 규약에 따라서 작성해야 한다.</i></b>

<h2>자바빈 설계 규칙</h2>
<ul>
 <li>기본 패키지를 제외한 다른 특정 패키지에 생성해야 한다.</li>
 <li>기본 생성자가 있어야 한다.</li>
 <li>멤버 변수의 접근 지정자는 private (캡슐화)</li>
 <li>멤버 변수에 접근 하려면 get/set 메서드를 사용한다.</li>
 <li>get/set 메서드는 반드시 public 접근 지정자를 사용한다.</li>
</ul>

<h2>자바빈 객체를 사용해서 정보 저장</h2>

```jsp
<body>
   <h1>WebContent/javabean/beanForm1.jsp</h1>
   <h2>자바빈</h2>
   
   <form action="beanPro1.jsp" method="post">
      아이디: <input type="text" name="id">
    <input type="submit" value="전달">   
   </form>
 
    <h1>WebContent/javabean/beanPro1.jsp</h1>
    <h2>자바빈 처리</h2>
    <%
          request.setCharacterEncoding("UTF-8");
          String id = request.getParameter("id");
    %>
    
    아이디: <%=id%><br>
 
   <%
      // 자바빈 객체 사용      
      JavaBean1 jb1 = new JavaBean1();
     
      jb1.setId(request.getParameter("id"));
      System.out.println(jb1);
   %>
    <!--위와 동일한 동작을 수행-->
    <!--action 태그 사용하여 JavaBean 객체 사용-->
    <jsp:useBean id="jb2" class="com.itwillbs.beantest.JavaBean1"></jsp:useBean>
    
    <!--자비빈 객체에 정보 저장-->
    <jsp:setProperty property="id" name="jb2" param="id"/>
    
    <%
        System.out.println(jb2);
    %>
</body>
```

```java
package com.itwillbs.beantest;
 
public class JavaBean1{
 
    // 테이블의 컬럼명 == 자바빈 변수명 == 파라미터명 -> 권장
    private String id;
 
    // public JavaBean1() { }
 
    public String getId() {
        return id;
    }
 
    public void setId(String id) {
        this.id = id;
    }
 
    
    // 메서드 오버라이딩
    // @Override
    // public String toString() {
    // return "메서드 오버라이딩!";
    // }
    
    @Override
    public String toString() {
        return "JavaBean1 [id=" + id + "]";
    }
}
```
