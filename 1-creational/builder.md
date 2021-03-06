# builder

## 의도
 복잡한 객체를 생성하는 방법과 표현하는 방법을 정의하는 클래스를 별도로 분리, 생성에 대한 동일한 절차 제공

## 동기
 RTF 문서 판독기에 대한 예시. Reader가 Converter(builder) 를 가지고 있고, 이 builder 는 서브클래스를 가진다.
 각기 다른 구현이 서브클래스에 구현되어 있고, 이는 전부 생성에 대한 동작임. 조립, 조립, 조립 후 생성! 하는 동작에서
 사용할 수 있는 패턴.
 - 빌더 패턴을 사용하는 클래스는 director
 - Separate the construction of a complex object from its representation so that the same construction process can create different representations. **같은 생성 과정, 다른 표현물**

## 활용성
 - 복합객체(builder가 생성할 객체)의 이를 합성하는 요소 객체들이 무엇인지 이들의 조립방법에 독립적일 때.
   - 표현이 애매한데 조립방법에 독립적일 때 사용한다고 보면될듯
 - 합성할 객체들의 표현이 서로 다르더라도 생성 절차에서 이를 지원해야 할 때

## 구조
 책 그림 참고

## 참여자
- Builder : 객체의 일부 요소들을 생성하기 위한 추상인터페이스 정의
- ConcreteBuilder : 인터페이스 구현, BuildA, BuildB 등 각 부분에 대한 생성 로직이 들어있다.(제품의 부품들을 모아 빌더를 복합한다는 표현을 씀).
  - 생성한 요소의 표현을 정의하고 관리
- 제품을 검색(결과물 요청)하는 데 필요한 인터페이스 제공(이건 Builder 로 올릴수있다)
- Director : Builder 인터페이스를 사용하는 객체를 합성
 - Builder에게 요청을 하는 클래스
- Product : 생성할 복합 객체를 표현(생성될 객체)
 - ConcreteBuilder는 제품의 내부표현 구축, 복합 객체가 어떻게 구성되는지에 관한 절차를 정의

## 협력 방법
다이어그램 참고

## 결과
- 제품에 대한 내부 표현을 다양하게 변화할수 있다
 - 
- 
