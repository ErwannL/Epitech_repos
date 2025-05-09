
BITS 64
SECTION .text

GLOBAL strcasecmp
strcasecmp:
    MOV RAX, 0                      ; set res value to 0
    MOV RCX, 0                      ; set count value to 0
    CMP RDI, 0                      ; comp if src is null
    JE end                          ; quit fonction if src is empty

    loop:
        MOV BL, BYTE [RDI + RCX]    ; put actual element of str1 in temp value
        MOV R8B, BYTE [RSI + RCX]   ; put actual element of str2 in temp value
        CMP BL, R8B                 ; comp 2 temp value
        JL check_upper              ; if they are dif,  go check the case

        check:
            CMP BL, 0               ; comp if first temp value wuth 0
            JE end                  ; quit loop if first temp value is null
            CMP R8B, 0              ; comp if second temp value wuth 0
            JE end                  ; quit loop if second temp value is null
            INC RCX                 ; add 1 to count
            JMP loop                ; go at start of loop

    check_upper:
        CMP BL, 90                  ; comp if the upper case is really a upper letter
        JNG check                   ; if the letter is a lower letter finish check
        ADD BL, 32                  ; transform the upper letter in a lower letter
        CMP BL, R8B                 ; cmp 2 lower letter
        JNE end                     ; quit heck if 2 lower letter are dif
        JMP check                   ; finish check

    end:
        SUB BL, R8B                 ; stock comp between first and second temps value
        MOVSX RAX, BL               ; put the result of comparaison in res and cast it in 64 bits
        RET                         ; quit fonction
