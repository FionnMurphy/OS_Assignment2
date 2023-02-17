.text 
.globl start 

start: 

	la t3, sp
		
	# sub t3, t3, .word 
	
	lw a0, -1(t3) # stores value
	lw a1, -2(t3) # stores row
	lw a2, -3(t3) # stores col
			
	# li a0, 5 #x
	# li a1, 8 #y
	li t0, 0xffff8000 #board
	
	beq a0, 1, setBitToOne
	beq a0, 0, setBitToZero
	
setBitToOne:
	sll a1,a1,2 
	add t0,t0,a1 
	
	li t1,1
	sll t1,t1,a2
	
	lw t2, 0(t0)
	or t2,t2,t1
	sw t2, 0(t0)

setBitToZero: 
	sll a1,a1,2 
	add t0,t0,a1 
	
	li t1,1
	sll t1,t1,a2
	not t1, t1
	
	lw t2, 0(t0)
	or t2,t2,t1
	sw t2, 0(t0)

	li a7, 10
	ecall