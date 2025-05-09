
BITS 64
SECTION .text

GLOBAL strncmp
strncmp:
    MOV RAX, 0                      ; set res value to 0
    MOV RCX, 0                      ; set count value to 0
    CMP RDI, 0                      ; comp if src is null
    JE finish                       ; quit fonction if src is empty
    CMP RDX, 0                      ; comp count and 0
    JE end                          ; quit function if nbr to cmp are null

    loop:
        CMP RDX, RCX                ; comp count and n
        JE finish                   ; quit loop if n element are reached
        MOV BL, BYTE [RDI + RCX]    ; put actual element of str1 in temp value
        MOV R8B, BYTE [RSI + RCX]   ; put actual element of str2 in temp value
        CMP BL, R8B                 ; comp 2 temp value
        JNE finish                  ; quit loop if 2 temp value are dif
        CMP BL, 0                   ; comp if first temp value wuth 0
        JE finish                   ; quit loop if first temp value is null
        CMP R8B, 0                  ; comp if second temp value wuth 0
        JE finish                   ; quit loop if second temp value is null
        INC RCX                     ; add 1 to count
        JMP loop                    ; go at start of loop

    finish:
        SUB BL, R8B                 ; stock comp between first and second temps value
        MOVSX RAX, BL               ; put the result of comparaison in res and cast it in 64 bits
        RET                         ; quit fonction

    end:
        RET                         ; quit fonction
