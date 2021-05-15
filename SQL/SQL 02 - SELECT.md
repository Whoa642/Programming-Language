**DESCRIBE**로 테이블의 구조를 조회할 수 있다. 예를 들어 students라는 테이블이 있을 경우
```SQL
DESCRIBE students
Name                Null     Type
------------------- -------  -----------
STUDENT_ID          NOT NULL NUMBER(4)    
FIRST_NAME          NOT NULL VARCHAR(5)
LAST_NAME           NOT NULL VARCHAR(5)
GRADE                   
PHONE_NUMBER                 VARCHAR(15)
ADDRESS             NOT NULL VARCHAR(20)
MAJOR                        VARCHAR(10)
GPA                 NOT NULL NUMBER(4)
```

**SELECT**를 사용해서 테이블의 데이터를 검색하는데 가져올 컬럼을 명시할 수 있으며 컬럼에 수식을 사용할 수도 있다. 만약 모든 컬럼을 선택할 경우 '*'를 사용한다. 
```SQL
SELECT student_id, address, gpa*10+4
FROM students;
```

**null**은 특수한 값(사용할 수 없는 값, 정의되지 않은 값 등)으로 모든 자료형에 사용할 수 있다. **참고로 null은 공백이나 0과 같지 않기 때문에 이 점에 유의해야 한다**. 
null 값의 특성 때문에 연산을 하면 결과는 null이 나온다.

**Alias**을 사용해서 SELECT 구문의 컬럼명을 변경할 수 있다.
1. 컬럼명 AS alias 
2. 컬럼명 alias
3. 컬럼명 [AS] "alias"(이 옵션의 경우 대소문자를 구분하고 공백과 특수문자(**'#', '_', '$'**)를 포함할 수 있다.)

__연결 연산자(||)__ 를 사용해서 여러 개의 컬럼을 묶어서 하나의 컬럼으로 출력할 수 있다.
```SQL
SELECT last_name || first_name AS "Name"
FROM students;
```

컬럼명에 리터럴 문자(일반 문자,숫자, 날짜 값)를 추가할 수 있는데 문자와 날짜의 경우 작은 따옴표('')안에 작성해야 한다. 컬럼명과 묶을 경우 앞에서 사용한 연결 연산자를 사용한다.

중복된 값을 1번만 출력하고 싶을 경우 **DISTINCT**를 사용한다.
```SQL
SELECT DISTINCT last_name 
FROM students;
```
