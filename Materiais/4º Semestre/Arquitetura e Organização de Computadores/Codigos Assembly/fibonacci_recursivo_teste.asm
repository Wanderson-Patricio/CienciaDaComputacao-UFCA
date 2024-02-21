.text
main:
	li	$a0, 3
	jal	fib
	move 	$a0, $v0
	jal	print_int
	jal	print_newline
	
fib:	
        addi 	$sp, $sp, -12
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	
	move	$s0, $a0
	beq	$s0, $0, base_case
	li	$t0, 1
	beq	$s0, $t0, base_case
	
	addi	$a0, $s0, -1
	jal	fib
	move	$s1, $v0
	addi	$a0, $s0, -2
	jal	fib
	add	$v0, $v0, $s1
	j	finish
	
base_case:	
        addu	$v0, $0, $s0
	j	finish
	
finish: 
        lw	$s1, 8($sp)
	lw	$s0, 4($sp)
	lw	$ra, 0($sp)
	addi	$sp, $sp, 12
	jr	$ra

print_int:
	move	$a0, $v0
	li	$v0, 1
	syscall
	jr	$ra
	
print_newline:
	li	$a0, '\n'
	li	$v0, 11
	syscall
	jr	$ra	
