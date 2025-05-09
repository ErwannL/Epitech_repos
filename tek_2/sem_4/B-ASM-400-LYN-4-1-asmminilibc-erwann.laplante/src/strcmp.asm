
BITS 64
SECTION .text

GLOBAL strcmp
strcmp:
    MOV RAX, 0                      ; set res value to 0
    MOV RCX, 0                      ; set count value to 0
    CMP RDI, 0                      ; comp if src is null
    JE end                          ; quit fonction if src is empty

    loop:
        MOV BL, BYTE [RDI + RCX]    ; put actual element of str1 in temp value
        MOV R8B, BYTE [RSI + RCX]   ; put actual element of str2 in temp value
        CMP BL, R8B                 ; comp 2 temp value
        JNE end                     ; quit loop if 2 temp value are dif
        CMP BL, 0                   ; comp if first temp value wuth 0
        JE end                      ; quit loop if first temp value is null
        CMP R8B, 0                  ; comp if second temp value wuth 0
        JE end                      ; quit loop if second temp value is null
        INC RCX                     ; add 1 to count
        JMP loop                    ; go at start of loop

    end:
        SUB BL, R8B                 ; stock comp between first and second temps value
        MOVSX RAX, BL               ; put the result of comparaison in res and cast it in 64 bits
        RET                         ; quit fonction
