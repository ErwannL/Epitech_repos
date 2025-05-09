
BITS 64
SECTION .text

GLOBAL strpbrk
strpbrk:
    MOV RAX, 0                      ; set res to 0
    MOV RCX, 0                      ; set str1 count to 0

    loop:
        MOV R8, 0                   ; set str2 count to 0
        CMP BYTE [RDI], 0           ; cmp str1 with null
        JE end                      ; quit loop if end str
        MOV BL, BYTE [RDI + RCX]    ; put actual elem in temp value
        INC RCX                     ; add 1 to str1 count
        CMP BL, 0                   ; cmp if actual element of str1 is null
        JE end                      ; quit loop if end of str1

        cmp_loop:
            CMP BYTE [RSI + R8], 0  ; cmp actual element of str2 with 0
            JE loop                 ; go at start of loop if end str2
            CMP BYTE [RSI + R8], BL ; cmp actual element of str2 with temp value
            JE find                 ; quit cmp_loop if temp value is find on str2
            INC R8                  ; add 1 to str2 count
            JMP cmp_loop            ; go at start of cmp_loop

        find:
            DEC RCX                 ; del 1 to str1 count
            ADD RDI, RCX            ; add fin elem at start of str1
            MOV RAX, RDI            ; put str1 in res value
            RET                     ; quit fonction

    end:
        RET                         ; quit fonction
