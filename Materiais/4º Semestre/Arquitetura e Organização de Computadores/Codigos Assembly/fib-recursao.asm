.text
main:
	li $a0, 5
	jal fib
	move $a0, $v0
	li $v0, 1
	syscall
	
	
	li $v0, 10
	syscall


fib:
	addi $sp, $sp, -16
	sw $ra, 12($sp)
	sw $s0, 8($sp)
	sw $s1, 4($sp)
	sw $s2, 0($sp)
	
	move $s0, $a0
	beq $s0, 0, base_case
	beq $s0, 1, base_case
	
	addi $a0, $s0, -1
	jal fib
	move $s1, $v0
	
	addi $a0, $s0, -2
	jal fib
	move $s2, $v0
	
	add $v0, $s1, $s2
	lw $s2, 0($sp)
	lw $s1, 4($sp)
	lw $s0, 8($sp)
	lw $ra, 12($sp)
	addi $sp, $sp, 12
	jr $ra 

base_case:
	move $v0, $s0
	lw $s2, 0($sp)
	lw $s1, 4($sp)
	lw $s0, 8($sp)
	lw $ra, 12($sp)
	addi $sp, $sp, 12
	jr $ra 
	