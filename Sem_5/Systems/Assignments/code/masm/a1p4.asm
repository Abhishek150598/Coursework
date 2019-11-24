.MODEL SMALL
.STACK 100H

.DATA
	PROMPT1 DB 'Enter the elements of the array: $'
	MSG1 DB 13D, 10D, '2nd maximum element is: $'
	MSG2 db 13D, 10D, '2nd minimum element is is: $'
	MAX1 DW ?
	MAX2 DW ? 
	MIN1 DW ? 
	MIN2 DW ? 

.CODE
	START:
        MOV AX, @DATA
        MOV DS, AX

        MOV MAX1, 0
        MOV MAX2, 0
        MOV MIN1, 9999
        MOV MIN2, 9999

        LEA DX, PROMPT1
        MOV AH, 9
        INT 21H

    L0: MOV BX, 0				; Storing the elements in BX
    L1: MOV AH, 1				; Taking character input
        INT 21H

        CMP AL, 13				; Checking for enter key
        JE L3

        CMP AL, 32				; Checking for space
        JE L2

        SUB AL, '0'				; Converting ASCII value to numeric value
       
       	PUSH AX
        MOV AX, BX 				
        MOV CX, 10
        MUL CX 					; Multiplying the previous input by 10
        MOV BX, AX
        POP AX

        MOV AH, 0
        ADD BX, AX 				; Adding the current character input to the number
        JMP L1

    L2: CMP MAX1, BX 			; Comparing the number with max1
        JNL L4

        MOV CX, MAX1
        MOV MAX2, CX
        MOV MAX1, BX     		; If BX > max1, moving value of max1 to max2 and BX to max1
        JMP LB2

    L4: CMP MAX2, BX 			; Comparing the number with max2
        JNL LB2

        MOV MAX2, BX 			; If BX > max2, moving value of BX to max2
        JMP LB2
    
    LB2:CMP MIN1, BX 			; Comparing the number with min1
        JNG LB4

        MOV CX, MIN1 	
        MOV MIN2, CX
        MOV MIN1, BX 			; If BX < min1, moving min1 to min2 and BX to min1
        JMP L0
        
    LB4:CMP MIN2, BX 			; Comparing the number with min2
        JNG L0

        MOV MIN2, BX 			; If BX < min2, moving value of BX to min2
        JMP L0

    L3: LEA DX, MSG1 			; Displaying message for 2nd maximum element
        MOV AH, 9
        INT 21H

        MOV AX, MAX2 			; Displaying 2nd maximum element
        CALL PUTN

        LEA DX, MSG2 			; Displaying message for 2nd minimum element
        MOV AH, 9
        INT 21H
        
        MOV AX, MIN2 			; Displaying 2nd minimum element
       	CALL PUTN

        MOV AH, 4CH
        INT 21H

	PUTN:               		; Display number in ax
                				; ax contains number (and also div C in above)
                				; dx contains remainder (rem in C above)
                				; cx contains 10 for division
	    PUSH BX
	    PUSH CX
	    PUSH DX
	 
	    MOV DX, 0           	; dx = 0
	    PUSH DX          		; push 0 as sentinel
	    MOV CX, 10      		; cx = 10
	 
	    CMP AX, 0
	    JGE CALC_DIGITS     	; number is non-negative
	    NEG AX          		; ax = -ax; ax is now positive
	    PUSH AX          		; save ax
	    MOV AL, '-'     		; display - sign
	    CALL PUTC
	    POP AX         			; restore ax
 
	CALC_DIGITS:
	    DIV CX         			; ax = ax / cx
	                    		; ax = result, dx = remainder
	    ADD DX, '0'     		; convert dx to digit
	    CMP DX,57
	    JLE L33
	    ADD DX, 7

	L33:PUSH DX          		; save digit on stack
	    MOV DX, 0      			; dx = 0
	    CMP AX, 0           	; finished ?
	    JNE CALC_DIGITS     	; if no, repeat process
 
;   all digits now on stack, display them in reverse
 
	DISP_LOOP:
	    POP DX          	; get last digit from stack
	    CMP DX, 0           ; is it sentinel
	    JE  END_DISP_LOOP   ; if yes, we are finished 
	    MOV AL, DL     		; al = dl
	    CALL PUTC           ; otherwise display digit
	    JMP DISP_LOOP
	 
	END_DISP_LOOP:
	    POP DX          	; restore registers
	    POP CX
	    POP BX
	    RET
 
	PUTC: 					; Display character in AL
 
        PUSH AX 			; save ax
        PUSH BX				; save bx 
        PUSH CX				; save cx
        PUSH DX				; save dx
 
        MOV DL, AL
        MOV AH, 2
        INT 21H
 
        POP DX				; restore dx
        POP CX 				; restore cx
        POP BX				; restore bx
        POP AX 				; restore ax
        RET
	
	END START
