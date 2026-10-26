global setgdt

section .rodata
setgdt:
    dq 0
    
.code equ $ - setgdt
    dq (1<<44) | (1<<47) | (1<<41) | (1<<43) | (1<<53)
    
.data equ $ - setgdt
    dq (1<<44) | (1<<47) | (1<<41)
    
.pointer:
    dw .pointer - setgdt - 1
    dq setgdt
    
    lgdt[setgdt.pointer]
    
ret