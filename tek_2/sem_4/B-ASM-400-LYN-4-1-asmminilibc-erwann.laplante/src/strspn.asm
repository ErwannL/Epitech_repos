
BITS 64
SECTION .text

GLOBAL strspn
strspn:
    MOV RAX, 0                      ; set res to 0
    MOV RCX, 0                      ; set str1 count to 0

    loop:
        MOV R8, 0                   ; set str2 count to 0
        CMP BYTE [RDI], 0           ; cmp str1 with null
        JE end                      ; quit loop if end str
        MOV AL, BYTE [RDI + RCX]    ; put actual elem of str1 in temp value
        CMP AL, 0                   ; cmp if actual element of str1 is null
        JE end                      ; quit loop if end of str1
        INC RCX                     ; add 1 to str1 count

        cmp_loop:
            CMP BYTE [RSI + R8], 0  ; cmp actual element of str2 with 0
            JE end                  ; gqut function if end str2
            CMP BYTE [RSI + R8], AL ; cmp actual element of str2 with temp value
            JE loop                 ; go at strat of loop if temp value is find on str2
            INC R8                  ; add 1 to str2 count
            JMP cmp_loop            ; go at start of cmp_loop

        find:
            DEC RCX                 ; rm 1 to str1 count
            MOV RAX, RCX            ; put str1 count in res
            RET                     ; quit function

    end:
        DEC RCX                     ; rm 1 to str1 count
        MOV RAX, RCX                ; put str1 count in res
        RET                         ; quit function
