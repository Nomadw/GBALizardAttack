.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  movementupdateX		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
movementupdateX:				@ function start

push { r4-r7, lr }

ldrb r4, [r0]
ldrb r5, [r1]
ldrb r6, [r2]

cmp r4, #0
beq skip

movecheck:
cmp r4, #1
beq moveright
cmp r4, #2
beq moveleft
bal skip

moveright:
sub r5, r5, r6
bal skip

moveleft:
add r5, r5, r6

skip:
strb r4, [r0]
strb r5, [r1]
strb r6, [r2]

pop { r4-r7 }
pop { r3 }
bx r3