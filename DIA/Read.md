### Voip.ms

Prefix - Country Code

```mermaid
graph LR
A[Calls] --> B[International Calls]
A --> C[Local Calls]
B --> D[With Domain]
B --> E[No Domain]
D --> F[With prefix]
D --> G[No prefix]
E --> H[With prefix]
E --> I[No prefix]

