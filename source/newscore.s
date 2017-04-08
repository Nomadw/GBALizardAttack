.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  newscore		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
newscore:				@ function start

push { r4-r7, lr }

ldrb r4, [r0]
ldrb r5, [r1]
ldrb r6, [r2]

add r4, #1
cmp r4, #10
beq trueten
bal skip

trueten:
mov r4, #0
add r5, #1
cmp r5, #10
beq truehund
bal skip

truehund:
mov r5, #0
add r6, #1
cmp r6, #10
beq zeroall
bal skip

zeroall:
mov r4, #10
mov r5, #10
mov r6, #10

skip:
strb r4, [r0]
strb r5, [r1]
strb r6, [r2]

pop { r4-r7 }
pop { r3 }
bx r3