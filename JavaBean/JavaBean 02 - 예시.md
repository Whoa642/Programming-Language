<h1>사용자가 입력한 정보를 자바빈 객체에 저장해서 출력</h1>

<br>

<h2>사용자의 정보를 입력하고 처리하는 JSP 페이지</h2>

```jsp
<body>
  <h1>WebContent/javabean/beanForm2.jsp</h1>
  <!--beanPro2.jsp로 정보를 전달한 다음 beanPro2 페이지에서 정보 출력-->
    <fieldset>
          <form action="beanPro2.jsp" method="post">
              아이디:<input type="text" name="id"><br>
              비밀번호:<input type="password" name="pw"><br>
              나이:<input type="text" name="age"><br>
              전화번호:<input type="text" name="tel"><br>
              <hr>
              <input type="submit" name="전송">
          </form>
      </fieldset>
 
  <h1>WebContent/javabean/beanPro2.jsp</h1>
    <!--이전에 사용했던 방식-->
    <%
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");
        int age = Integer.parseInt(request.getParameter("age"));
        String tel = request.getParameter("tel");
    %>
    
    아이디:<%=id%><br>
    비밀번호:<%=pw%><br>
    나이:<%=age%><br>
    전화번호:<%=tel%><hr>
 
 
    <hr>
    <% 
        // 아이디,비밀번호,나이,전화번호 정보를 저장하는 JavaBean2 객체 생성
        JavaBean2 jb2 = new JavaBean2();
        jb2.setId(id);
        jb2.setPw(pw);
        jb2.setAge(age);
        jb2.setTel(request.getParameter("tel"));
    %>
    
    <%=jb2%><br>
    <%=jb2.getId()%><br>
    
 
 
    <hr>
    <h2>action 태그</h2>
    <!--객체 생성-->
    <%-- <jsp:useBean id="객체 이름" class="객체 파일 위치"/> --%>
    <jsp:useBean id="jb3" class="com.itwillbs.beantest.JavaBean2"/>
    
    <!--정보 저장-->
    <%-- <jsp:setProperty property="자바빈 객체 변수명" name="객체 이름" param="매개변수명"/> --%>
    <!--property와 param 속성이 동일한 경우 param 생략 가능-->
    <!--전달되는 모든 매개변수와 저장되는 모든 매개변수가 동일한 경우-->
    
    <%-- <jsp:setProperty property="id" name="jb3" param="id"/>
    <jsp:setProperty property="pw" name="jb3" param="pw"/>
    <jsp:setProperty property="age" name="jb3" param="age"/>
    <jsp:setProperty property="tel" name="jb3" param="tel"/>
    --%>     
     
    <%
        // jb3.setAge(age)+request.getParameter(arg0)
        // 2개의 동작을 결합한 형태로 실행
        // 자동으로 타입에 맞는 처리 실행
    %>
     
    <jsp:setProperty property="*" name="jb3"/>
    
    <!--정보 출력(action 태그)-->
    <jsp:getProperty property="id" name="jb3"/><br>
    <jsp:getProperty property="pw" name="jb3"/><br>
    <jsp:getProperty property="age" name="jb3"/><br>
    <jsp:getProperty property="tel" name="jb3"/><br>
    
</body>
```

<h2>사용자의 정보를 저장하는 자바빈 객체</h2>

```java
package com.itwillbs.beantest;
 
public class JavaBean2 {
    
    private String id;
    private String pw;
    private int age;
    private String tel;
    
    public String getId() {
        return id;
    }
    
    public void setId(String id) {
        this.id = id;
    }
    
    public String getPw() {
        return pw;
    }
    
    public void setPw(String pw) {
        this.pw = pw;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public String getTel() {
        return tel;
    }
    
    public void setTel(String tel) {
        this.tel = tel;
    }
    
    @Override
    public String toString() {
        return "JavaBean2 [id=" + id + ", pw=" + pw + ", age=" + age + ", tel=" + tel + "]";
    }
 
}
```
