.section .text

.extern _ZN16InterruptManager15handleInterruptEht

int_bottom:
	pusha
	pushl %ds
	pushl $es
	pushl $fs
	pushl $gs
	
	pushl %esp
	push (interruptnumber)
	call _ZN16InterruptManager15handleInterruptEht
	# addl $5, %esp
	movl %eax, %esp
	
	popl %gs
	popl %fs
	popl %es
	popl %ds
	popa
	
	iret

.data
	interruptnumber: .byte 0