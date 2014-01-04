    .ORIG x3000

; Read the number of disks
    TRAP x23
    LD R3, AsciiZero
    ADD R2, R0, R3 ; R2 will hold the number of disks

; If n<=1 display nErrStr
    AND R1, R1, #0
    ADD R1, R1, #-1
    ADD R1, R1, R2
    BRnz nErr
; Else jump to MAIN
    BRnzp MAIN

; Solve Hanoi
H
    STR R7, R6, #1 ; push the return address

    LDR R2, R6, #3 ; get the number of disks
    LDR R3, R6, #4 ; get the source rod
    LDR R4, R6, #5 ; get the helper rod
    LDR R5, R6, #6 ; get the destination rod

    ; Test for the termination condition (n == 1)
    AND R1, R1, #0
    ADD R1, R1, #-1
    ADD R1, R1, R2
    BRz DisplayAndReturn

    ADD R2, R2, #-1

    STR R6, R6, #9 ; push the current frame pointer
    ADD R6, R6, #7 ; move the frame pointer

    ; Push the arguments, see MAIN
    STR R2, R6, #3
    STR R3, R6, #4
    STR R5, R6, #5
    STR R4, R6, #6

    ; H(n-1, source, dest, helper)
    JSR H

    ; Since the previous call could have messed the registers,
    ; restore them from the stack
    LDR R2, R6, #3
    LDR R3, R6, #4
    LDR R4, R6, #5
    LDR R5, R6, #6

    JSR Display

    ADD R2, R2, #-1

    STR R6, R6, #9 ; push the current frame pointer
    ADD R6, R6, #7 ; move the frame pointer

    ; Push the arguments, see MAIN
    STR R2, R6, #3
    STR R4, R6, #4
    STR R3, R6, #5
    STR R5, R6, #6

    ; H(n-1, helper, source, dest)
    JSR H

    BRnzp RETURN

; Display nErrStr
nErr
    LEA R0, nErrStr
    TRAP x22
    HALT

MAIN
    LD R3, CharA ; R3 represents the source rod
    LD R4, CharB ; R4 is the helper rod
    LD R5, CharC ; R5 is the destination rod

    STR R2, R6, #3 ; push the number of disks
    STR R3, R6, #4 ; push the source rod
    STR R4, R6, #5 ; push the helper rod
    STR R5, R6, #6 ; push the destination rod

    ; H(n, source, helper, dest)
    JSR H
    HALT

RETURN
    LDR R7, R6, #1 ; restore the return address
    LDR R6, R6, #2 ; restore the previous frame pointer
    RET

Display
    ST R7, SaveR7
    ; Display the source rod
    AND R0, R0, #0
    ADD R0, R0, R3
    TRAP x21

    ; Display the destination rod
    AND R0, R0, #0
    ADD R0, R0, R5
    TRAP x21

    ; Display the endline character
    AND R0, R0, #0
    ADD R0, R0, xA
    TRAP x21
    LD R7, SaveR7

    RET

DisplayAndReturn
    JSR Display
    BRnzp RETURN

AsciiZero
    .FILL xFFD0 ; -48
CharA
    .STRINGZ "A"
CharB
    .STRINGZ "B"
CharC
    .STRINGZ "C"
nErrStr
    .STRINGZ "\nn>1 please\n"
SaveR7
    .BLKW 1

    .END
