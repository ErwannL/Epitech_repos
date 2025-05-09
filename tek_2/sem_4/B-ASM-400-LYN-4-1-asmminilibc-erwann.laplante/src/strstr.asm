
BITS 64
SECTION .text

GLOBAL strstr
strstr:
    MOV RAX, 0                      ; set res value to 0
    MOV RCX, 0                      ; set str1 counter to 0
    MOV R8, 0                       ; set str2 counter to 0
    MOV R9, 0                       ; set prev equal value to true
    CMP RDI, RSI
    JE str_equal

    loop:
        MOV BL, BYTE [RDI + RCX]    ; put actual element of str1 in temp value
        MOV R10B, BYTE [RSI + R8]   ; put actual element of str2 in temp value
        CMP BL, 0                   ; cmp if actual element of str1 is null
        JE end                      ; quit loop if end of str1
        CMP  R10B, 0                ; cmp if actual element of str2 is null
        JE find                     ; quit loop if all str2 is find
        CMP BL, R10B                ; cmp the 2 temp value
        JE equal                    ; if 2 temp value are equal go to equal function
        JNE dif                     ; else go to different function

        end_dif:
            MOV R8, 0               ; set str2 counter to 0
            MOV R9, 1               ; set prev equal value to false
        JMP loop                    ; go at start of loop

    equal:
        INC RCX                     ; add 1 to str1 count
        INC R8                      ; add 2 to str1 count
        MOV R9, 0                   ; set prev equal value to true
        JMP loop                    ; go at start of loop

    dif:
        CMP R9, 0                   ; cmp if prev equal value is true
        JE end_dif                  ; if prev equal value is true, go finish the dif
        INC RCX                     ; add 1 to str1 count
        JMP end_dif                 ; go finish the dif

    find:
        SUB RCX, R8                 ; subtract the len of str2 of the count of str1
        ADD RDI, RCX                ; add the str2 at start of str1
        ADD RAX, RDI                ; put str1 in res value
        RET                         ; quit fonction

    str_equal:
        ADD RAX, RDI                ; put str1 in res value
        RET                         ; quit fonction

    end:
        RET                         ; quit fonction
