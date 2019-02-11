# STM32L0x3 GPIO Driver Project (Keil MDK5)
STM32L0x3 GPIO Driver lite version (barebone) template with the help of using Keil uVision MDK5-ARM, its toolchain, STM32CubeMX, RTE for CMSIS driver startup code, stack, heap, and vector table definitions and initializations. 

### Expected Output
Generates a square wave ⎍⎍⎍⎍⎍⎍⎍⎍⎍ at Port A pin 5 and Port B pin 4 with the following params...
* Freq: at about 0.525 Hz
* Pulse width: ~1 second
* Period: ~1.9-2 seconds
* Duty cycle: 50%
```
           |~~~~~|     |~~~~~|
           |     |     |     |
           |     |     |     |
           |     |     |     |
      ~~~~~|     |~~~~~|     |~~~~~
```