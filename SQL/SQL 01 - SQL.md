**SQL**은 ANSI 표준 언어로서 관계형 데이터베이스의 데이터를 접근하기 위해서 사용하는 명령문이다. 

## SQL의 명령문

**DDL**(Data Definition Language)
CREATE, ALTER, DROP, RENAME, TRUNCATE, COMMENT가 이에 속하며 객체를 생성, 수정, 삭제하는 명령문이다.(객체에는 테이블, 뷰, 시퀀스, 인덱스 등이 있다.)

**DML**(Data Manipulation Language)
SELECT, INSERT, UPDATE, DELETE, MERGE가 이에 속하며 데이터를 검색하고 행을 삽입, 수정, 삭제하는 명령문이다.

**DCL**(Data Control Language)
GRANT, REVOKE가 이에 속하며 데이터베이스와 구조에 대한 접근 권한을 부여하거나 회수하는 명령문이다.

**TCL**(Transaction Control Language)
COMMIT, ROLLBACK, SAVEPOINT가 이에 속하며 DML으로 인한 데이터 변경 작업은 논리적인 작업 단위인 트랜잭션으로 묶일 수 있으며, 이러한 트랜잭션을 제어하는 명령문이다.

## DDL(Data Definition Language)

**CREATE**는 테이블을 생성하는 명령어이며 테이블명, 컬럼명, 자료형, 컬럼 크기를 지정해야하고 추가적으로 기본값(default)과 제약조건을 지정할 수 있다. 

### 제약조건
Primary key:기본키 제약조건으로 테이블당 한 번만 선언 할 수 있다. Not null과 Unique의 성격을 모두 가지며 테이블을 대표하는 컬럼에 선언한다.   
Foreign key:외래키 제약조건으로 자기 자신의 테이블이나 다른 테이블의 특정 컬럼을 참조하는 제약조건이다.   
Unique:고유한 데이터만 들어올 수 있는 제약조건으로 중복된 데이터 허용하지 않는다.   
Not null:null값이 들어올 수 없는 제약조건으로 필수 컬럼에 활용된다.   
Check:해당 컬럼이 만족해야하는 조건문을 지정하는 제약조건이다.   

**ALTER**는 테이블에 컬럼을 추가하거나 기존의 컬럼을 수정, 삭제한다. 수정 시 자료형, 컬럼 크기, 기본값 등을 수정할 수 있다. 

**DROP**은 테이블의 구조, 데이터, 제약 조건을 삭제한다. rollback이 불가능하다.

**TRUNCATE**는 테이블 구조는 남겨두고 테이블의 모든 행을 제거한다. DROP과 같이 rollback이 불가능하다.


## DML(Data Manipulation Language)

**DESCRIBE**로 테이블의 구조를 조회할 수 있다.

**SELECT**는 **FROM**과 함께 사용해서 테이블로부터 데이터를 검색한다. '*'는 모든 데이터를 가져오고 가져올 컬럼을 명시할 수 있다.(FROM에 가져올 테이블을 명시하고 SELECT에서 컬럼명을 AS를 사용해서 변경할 수 있다.)
**WHERE**를 사용해서 명시한 값과 일치하는 항목만 가져올 수 있고 결과를 **ORDER BY**를 사용해서 정렬할 수 있다.(ASC는 오름차순, DESC는 내림차순)
2개의 테이블이 공유하는 컬럼을 가질 경우 **JOIN**을 사용하면 2개의 데이터를 연관시킬 수 있다. 쿼리 안에 다시 쿼리(서브쿼리)를 사용해서 데이터를 검색할 수 있다. 

**INSERT**는 새로운 행을 테이블에 추가한다. 테이블의 컬럼과 값을 명시해야 한다. 

**UPDATE**는 테이블에서 특정 행의 컬럼 값을 업데이트한다. WHERE을 사용해서 조건을 명시하지 않으면 모든 행의 값을 변경한다.

**DELETE**는 테이블에서 특정 행을 삭제한다. UPDATE와 같이 WHERE을 사용해서 조건을 명시하지 않으면 모든 행을 제거한다.(즉 TRUNCATE TABLE과 같다.)


## DCL(Data Control Language)

권한에는 2가지 유형이 있는데 하나는 **System 권한**이고 나머지는 **Object 권한**이다. 전자는 DB를 조작할 수 있는 권한으로 DBA가 소유자이며 후자는 Object를 조작할 수 있는 권한으로 Object 소유자가 소유한다.

System 권한은 DB를 조작할 수 있는 권한으로 100개 정도의 권한이 존재하면 모든 System 권한은 DBA가 소유한다. 

Object 권한은 Object를 조작할 수 있는 권한으로 종류가 다양하다. 모든 Object 권한은 Object의 소유자가 소유한다.

**GRANT**를 사용해서 권한을 부여하고 **REVOKE**를 사용해서 권한을 제거하는데 두 권한은 공통적으로 사용하는 명령문이다.
