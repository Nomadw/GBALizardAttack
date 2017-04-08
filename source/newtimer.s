.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  newtime		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
newtime:				@ function start

push { r4-r7, lr }

ldrb r4, [r0]
ldrb r5, [r1]
ldrb r6, [r2]
ldrb r7, [r3]

sub r4, #1
cmp r4, #0
beq trueten
bal skip

trueten:
mov r4, #10
sub r5, #1
cmp r5, #0
beq truehund
bal skip

truehund:
mov r5, #10
sub r6, #1
cmp r6, #0
beq truethou
bal skip

truethou:
mov r6, #10
sub r7, #1
cmp r7, #0
beq zeroall
bal skip

zeroall:
mov r4, #1
mov r5, #1
mov r6, #1
mov r7, #1

skip:
strb r4, [r0]
strb r5, [r1]
strb r6, [r2]
strb r7, [r3]

pop { r4-r7 }
pop { r4 }
bx r4