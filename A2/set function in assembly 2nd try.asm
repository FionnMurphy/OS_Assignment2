.text 

.globl start 


start: 


		
	# sub t3, t3, .word 
	
	lw t6, 0(a0) # stores row
	lw t5, 0(a1) # stores column
	lw t4, 0(a2) # stores value
	li t0, 0xffff8000 #board
	
	li t3, 1
	beq t4, t3, setBitToOne
	li t3, 0
	beq t4, t3, setBitToZero
	
setBitToOne:
	li t3, 2
	sll t6,t6,t3
	add t0,t0,t6
	
	li t1,1
	sll t1,t1,t5
	
	lw t2, 0(t0)
	or t2,t2,t1
	sw t2, 0(t0)
	
	li a7, 10
	ecall

setBitToZero: 
	li t3, 2
	sll t6,t6,t3
	add t0,t0,t6
	
	li t1,1
	sll t1,t1,t5
	not t1, t1
	
	lw t2, 0(t0)
	or t2,t2,t1
	sw t2, 0(t0)

	li a7, 10
	ecall