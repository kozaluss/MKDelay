# MKDelay

TimeOut & Delta made easy (Arduino C)

MKDelay v1.0
Author: Mateusz Kozicki "Kozaluss"

Date: 2023.11.05

## What is this?

Manage time with ease - timeout events and deltas.

## How to use:

1. Include header:

```
#include "MKDelay.h"
```

2. Declare object:

```
MKDelay MyDelay;
```

3. In setup - initialize with timeout value (millis), then reset:

```
MyDelay.SetTimeOut(1000);
MyDelay.Reset();
```

4. In loop - check if timeout happened.

```
if( MyDelay.IsTimeOut() ){...}
```

## Class functions reference:

`void SetTimeOut(long parTimeOut);`

>Set time out in milliseconds. Event will fire every parTimeOut.

`void Reset();`

>Reset timer to zero.

`bool IsTimeOut();`

>Check if the time run out.
If so, it automatically resets to be ready to catch next one.

`long GetDelta();`

>Get the time, that passed since last reset/timeout.

`long GetSubDelta();`

>Get the time, that passed since last time check.
Used internally by GetDelta, but can be useful alone as well.
Warning - max value 100000, then resets.

---