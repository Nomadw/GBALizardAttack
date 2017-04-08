.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  ChangeState		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
ChangeState:				@ function start

push { r4-r7, lr }

ldrb r4, [r0]
ldrb r5, [r1]

mov r4, r5
strb r4, [r0]
strb r5, [r1]

pop { r4-r7 }
pop { r3 }
bx r3