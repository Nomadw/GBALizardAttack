.THUMB				@ turn on thumb
.ALIGN  2			@ no idea why we do this
.GLOBL  timered		@ name of function goes here



.THUMB_FUNC			@ we are about to declare a thumb function
timered:				@ function start

push { r4-r7, lr }

ldrb r4, [r0]

sub r4, #1
strb r4, [r0]

pop { r4-r7 }
pop { r3 }
bx r3