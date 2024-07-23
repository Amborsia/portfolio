# portfolio

### 안녕하세요. 백엔드 개발자 남홍근 입니다.

![이력서사진](https://github.com/user-attachments/assets/8b70ca72-2f95-4839-945f-04c6ce83a95f)


문과 전공자지만 게임 클라이언트 개발에 대한 열정으로 입문했고, 꾸준히 노력한 결과 3년 동안 개발 경험을 쌓아 올 수 있었던 남홍근입니다. 비전공자라는 한계를 느끼기도 했지만 자기 학습과 프로젝트 경험을 바탕으로 기술 역량을 키워왔습니다. 이 과정에서 클라이언트와 서버 간의 효율적인 통신의 중요함을 깨닫고, 백엔드 개발에 관해 관심을 갖게 되었습니다. 

Pintos와 최근 진행한 프로젝트인 에그톡과 같은 프로젝트를 진행하며, 서버 시스템 설계와 구현에 큰 흥미를 느끼게 되었습니다. 이러한 경험을 바탕으로 백엔드 개발자로서 안정적이고 확장 가능하고 세상에 큰 기여를 할 수 있는 시스템을 구축해 나가고 싶습니다. 

---

## Contact & Channel

email : ghdrms1220@naver.com

number : 010-3254-5455

blog : https://blog.naver.com/ghdrms1220

github : https://github.com/Amborsia

notion : https://www.notion.so/7eb05592b3024b6fa74a0bf87d62bdcb

# Skills

---

## Backend

- **Languages & Frameworks**: Node.js, TypeScript, Express.js, Nest.js, C#, C, Python
- **Databases**: MongoDB, Redis
- **Real-time Communication**: Socket.IO
- **Tools**: Git, Visual Studio Code, XCode

## DevOps

- **Cloud Services**: AWS EC2, S3
- **CI/CD**: Jenkins

## Collaboration

- **Project Management**: Trello, Jira, GitHub Projects
- **Documentation**: Notion, Swagger, Postman
- **Version Control**: Git, GitHub

# Projects

---

## 에그톡

### 팀장

2024.06 ~ 2024.07

https://github.com/Amborsia/portfolio/blob/main/eggTalk/readme.md

**아바타와 아이스 브레이킹과 함께하는 3:3 소개팅 서비스**

- OpenVidu를 활용한 화상 채팅 서비스 기능 구현
    - 실시간 스트리밍 및 다자간 화상 채팅 기능을 효율적으로 처리하기 위해 OpenVidu의 세션 및 토큰 관리를 효과적으로 사용
- 남녀 큐 분리 및 최적화
    - 사용자 경험을 극대화 하기 위한 남녀 3:3 매칭 큐 작업
    - 친구 매칭 방지 알고리즘을 만들어 참가자 간의 불편함 최소화
    - Redis 및 cache-manager를 사용하여 큐 매칭 시스템 상 메모리를 효율적으로 처리
- 메인 컨텐츠 개발
    - 키워드 게임, 큐피드 타임 등 사용자의 참여도와 만족도를 높이기 위한 사용자 인터렉션을 유도하는 다양한 기능 추가
    - Socket.IO를 활용하여 실시간으로 사용자 간의 상호작용을 관리하고, 게임 진행 상황을 타이머를 통해 실시간으로 업데이트
- 코드 리팩토링 및 성능 최적화
    - 기존의 monolithic 서비스를 여러개의 독립적인 서비스로 분리하여 코드 가독성과 유지 보수성을 향상.
    - 중복 코드를 제거하고, DI에 따른 리팩토링 진행. 각 모듈 간의 의존성을 줄여 시스템의 안정성을 강화
- 성능 최적화 작업
    - Redis를 활용한 캐싱 전략 도입으로 데이터베이스 부하를 줄이고 응답 속도를 개선. 대기열 및 매칭 데이터의 빠른 조회와 업데이트를 진행함.
- 팀 리더십 및 협업 관리
    - 팀장으로서 매일 아침 10시 회의를 주최하고 팀의 목표를 상의하며 프로젝트 진행 상황을 모니터링. 백엔드와 프런트엔드간의 원활한 소통을 제시함.
    - 개개인의 강점을 파악하여 각 팀원의 역량을 최대한 발휘할 수 있는 업무를 분배. Github Project와 Discord를 활용하여 팀 내 프로젝트 관리 및 원활한 커뮤니케이션 작업 완료.

## 동물키우기

개인프로젝트

2023.10 ~ 2023.11

https://github.com/Amborsia/portfolio/tree/main/Idle_Game

- **백엔드 및 광고 설정**
    - **Firebase 설정:** 데이터베이스, 인증, 분석 기능 구현.
    - **AdMob 설정:** 광고 설정 및 수익화 작업 수행.
    - **GPGS 설정:** Google Play Games Services를 설정하여 게임 서비스 기능 추가 (출시 예정).
- **게임 관리 및 데이터 처리**
    - **GameManager 인스턴스화:** 게임의 핵심 로직과 상태 관리.
    - **엑셀 파싱 작업:** Excel 파일을 파싱하여 데이터 관리 및 업데이트 자동화, 데이터 수정 및 관리의 효율성 증대.
- **UI/UX 개발**
    - **UGUI 사용:** Unity의 UGUI를 사용하여 사용자 인터페이스(UI) 설계 및 구현.
    - **Canvas 관리:** Canvas에 다양한 이미지 요소들을 통합하여 효율적인 UI 구성.
    - **오프라인 시간 보상 설정:** 오프라인 상태에서도 시간 보상 기능을 설정하여 사용자 경험 개선.
- **리소스 최적화**
    - **프리팹 활용:** 프리팹을 통해 리소스를 재활용하고 게임의 성능 최적화.

**성과:**

- 효율적인 데이터 관리와 수정 가능성을 높여 유지보수 용이성 확보.
- 광고 수익화 및 게임 서비스 기능 도입으로 프로젝트 완성도 향상.
- UI/UX 설계를 통해 사용자 친화적인 인터페이스 구현.

# Career

---

## 네이버 엔테크서비스

2021.12 ~ 2023.02

## 쥬니버스쿨 
[실제링크](https://play.google.com/store/apps/details?id=com.nts.edu4k&hl=ko)

**유니티 사용 프로젝트**

- 유니티 엔진을 활용하여 다양한 프로젝트 개발
- 주요 기능 및 모듈 설계, 앱 내 컨텐츠 구현

**공통화 모듈 개발 및 수정**

- 여러 프로젝트에서 사용할 수 있는 공통 모듈 개발 및 수정
- 성능 개선 및 버그 수정 작업을 통해 모듈의 효율성 및 안정성 향상

**프로젝트 마이그레이션 작업**

- 기존 모듈 시스템에서 새로운 모듈 시스템으로 데이터 및 서비스 마이그레이션 수행
- 마이그레이션 과정에서 데이터 무결성과 시스템 안정성을 유지하며 성능 향상

**Git 및 Jenkins 사용 및 라이브 경험**

- Git을 사용한 버전 관리 및 협업 환경 구축
- Jenkins를 활용한 CI/CD 파이프라인 설계 및 구현
- 라이브 환경에서의 배포 및 유지보수 경험

## 플레로게임즈

2021.05 ~ 2021.11

## 에브리타운 
[실제링크](https://play.google.com/store/apps/details?id=kr.co.feverstudio.apps.everytown&hl=ko)

- **컨텐츠 업데이트**
    - SNG 게임 내 이벤트 작업 및 신규 컨텐츠 추가
    - 게임 내 버그 수정 및 안정성 향상 작업 수행
- **iOS 및 AOS 빌드**
    - iOS 및 Android(AOS) 빌드 진행 및 배포
    - Xcode를 사용한 iOS 빌드 작업
- **기술 사용**
    - Cocos2d 및 Lua를 활용한 게임 개발 및 업데이트

## 원컴즈

2020.09 ~ 2021.03

## 아이러브 파스타
[실제링크](https://play.google.com/store/apps/details?id=com.patigames.ilovepasta4kakao&hl=ko)

**Lua 및 Cocos2d 사용**

- Lua와 Cocos2d를 활용한 게임 개발 및 업데이트
- 게임 내 다양한 기능 구현 및 성능 최적화

**안드로이드 스튜디오를 통한 SDK 작업 및 어플 관리**

- 안드로이드 스튜디오를 사용하여 SDK 작업 및 어플리케이션 관리
- 어플리케이션의 업데이트 및 유지보수 수행

**프레임워크 작업(디자인툴 수정)**

- 디자인 툴 수정 및 프레임워크 작업
- UI/UX 개선을 위한 디자인 변경 및 구현

**SNG 게임 컨텐츠 업데이트**

- SNG 게임의 신규 컨텐츠 추가 및 이벤트 작업
- 버그 수정 및 게임 안정성 향상

**AOS 빌드**

- Android 운영체제(AOS) 빌드 작업
- 빌드 및 배포 프로세스 관리

**리팩토링 작업 진행**

- 코드 리팩토링을 통해 기존 코드의 가독성 및 유지보수성 개선
- 성능 최적화 및 버그 수정

## 피비컴

2019.12 ~ 2020.09

## S&G게임
[실제링크](https://play.google.com/store/apps/details?id=com.sng.SNG1&hl=ko)

**게임 개발**

- 미니게임 5개 개발
- 랭킹 시스템 구현
- TCP/IP 서버 통신 구현
- 출석 시스템 및 프로필 기능 구현
- 글로벌 작업 수행 (다국어 지원, 글로벌 서버 연동 등)

**SDK 작업**

- Google SDK 작업 및 적용
- Firebase 통합 및 활용
- Google Play Games Services(GPGS) 적용
- Facebook SDK 작업 및 연동
- IronSource 광고 네트워크 통합

**GitFlow 사용 및 Jenkins 구축 및 사용**

- GitFlow를 활용한 효율적인 버전 관리 및 협업
- Jenkins 구축 및 CI/CD 파이프라인 설정
- Jenkins를 통한 10회 이상의 업데이트 적용 및 관리

# Education

---

## SW 사관학교 정글

2024.03 ~ 2024.07

- 카이스트 주관 개발자 양성 교육 과정
    - 실무 수준의 과제 수행을 통해 백엔드 개발자 포지션 적합성 및 실무 투입 역량 확보
    - 카이스트 수준의 전산학 공부와 프로젝트를 통해 백엔드 개발자로서 적합성과 실무 역량 확보
    - 프로젝트 중심 교육
    - 마지막 프로젝트 팀장으로 참여

## 한림대학교

2016.03 ~ 2020.02

- 국어국문과 / 4차산업혁명전공 복수 전공
- 4년제 학사 졸업 (3.85 / 4.5)
