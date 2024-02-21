.text
	li $a0, 1024
	li $a1, 2
	
	jal pow_recursive
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall

pow_iterative:
	##x == $a0 e n == $a1 => retorna x^n
	li $t0, 0 		#t0 será nosso iterador
	li $t1, 1
	beq $t0, $a1, end
	
	#while t0 < n
	loop:
		mul $t1, $t1, $a0
		addi $t0, $t0, 1
		bne $t0, $a1, loop
	end:
		move $v0, $t1
		
	jr $ra
	
pow_recursive:
	##x == $a0 e n == $a1 => retorna x^n
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	bne $a1, $0, recursion
	
	#se chegou aqui é o caso n == 0
	li $v0, 1
	addi $sp, $sp, 4
	jr $ra
		
	recursion:
		addi $a1, $a1, -1
		jal pow_recursive
		mul $v0, $v0, $a0		#pow(x,n) = x * pow(x, n-1)
	
		lw $ra, 0($sp)
		addi $sp, $sp, 4
		jr $ra