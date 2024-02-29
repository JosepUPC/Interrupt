# Mermaid

here we'll see a little tutorial of how use the markdown extension app mermaid.

```C++
erDiagram
          CUSTOMER }|..|{ DELIVERY-ADDRESS : has
          CUSTOMER ||--o{ ORDER : places
          CUSTOMER ||--o{ INVOICE : "liable for"
          DELIVERY-ADDRESS ||--o{ ORDER : receives
          INVOICE ||--|{ ORDER : covers
          ORDER ||--|{ ORDER-ITEM : includes
          PRODUCT-CATEGORY ||--|{ PRODUCT : contains
          PRODUCT ||--o{ ORDER-ITEM : "ordered in"

```
```mermaid
erDiagram
          CUSTOMER }|..|{ DELIVERY-ADDRESS : has
          CUSTOMER ||--o{ ORDER : places
          CUSTOMER ||--o{ INVOICE : "liable for"
          DELIVERY-ADDRESS ||--o{ ORDER : receives
          INVOICE ||--|{ ORDER : covers
          ORDER ||--|{ ORDER-ITEM : includes
          PRODUCT-CATEGORY ||--|{ PRODUCT : contains
          PRODUCT ||--o{ ORDER-ITEM : "ordered in"
```

```C++
graph TD
    H{SETUP} --> B
    A|sistem bitRate| --> B(Serial.Begin)
    B --> C(attachInterrupt)
    D[inputPin] --> C
    E(activeFunction) --> C
    F [pinState] --> C
    C --> G{LOOP}
    G --> E
    E --> G
```
```mermaid
flowchart BT
    H{SETUP} --> |next| B
    A[sistem bitRate] --> |115200| B(Serial.Begin)
    B --> |next| C(attachInterrupt)
    D[inputPin] --> |GPIOX| C
    E(activeFunction) --> |actions| C
    F[pinState] --> |RISING| C
    C --> |next| G{LOOP}
    G --> |run| E
    E --> |comeback| G
```

```mermaid
graph TB
A(NiObject) --> B(NiAccumulator);
B --> C(NiClusterAccumulator);
C --> D(NiAlphaAccumulator);
A --> E(NiExtraData);
E --> F(BrickNiExtraData);
E --> G(TES3ObjectExtraData);
E --> H(NiStringExtraData);
E --> I(NiTextKeyExtraData);
E --> J(NiVertWeightsExtraData);
A --> K(NiObjectNET);
K --> L(NiDynamicEffect);
L --> M(NiLight);
M --> N(NiPointLight);
N --> O(NiSpotLight);
classDef notExposed fill:#ADFF2F,stroke:#333,stroke-width:2px;
class B,C,D notExposed;
classDef notResearched fill:#40E0D0,stroke:#333,stroke-width:2px;
class F,J notResearched;
```
```
---
title: Animal example
---
classDiagram
    note "From Duck till Zebra"
    Animal <|-- Duck
    note for Duck "can fly\ncan swim\ncan dive\ncan help in debugging"
    Animal <|-- Fish
    Animal <|-- Zebra
    Animal : +int age
    Animal : +String gender
    Animal: +isMammal()
    Animal: +mate()
    class Duck{
        +String beakColor
        +swim()
        +quack()
    }
    class Fish{
        -int sizeInFeet
        -canEat()
    }
    class Zebra{
        +bool is_wild
        +run()
    }
```