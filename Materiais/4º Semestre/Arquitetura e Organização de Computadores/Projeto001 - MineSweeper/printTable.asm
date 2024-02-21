.include "macros.asm"
.globl printTable

.data
	new_line: .asciiz "\n"
	space: .asciiz " "
	
.text

printTable:
	save_context
	li $s1, 0
	i_loop:
		li $t0, SIZE
		bge $s1, $t0, end_i_loop
		
		li $s2, 0
		j_loop:
			li $t0, SIZE
			bge $s2, $t0, end_j_loop
		
			move $a1, $s1
			move $a2, $s2
			get_ij_address
			add $t0, $t0, $s0
			lw $a0, 0($t0)
			li $v0, 1
			syscall
			
			la $a0, space
			li $v0, 4
			syscall
		
			addi $s2, $s2, 1
			j j_loop
		end_j_loop:
		la $a0, new_line
		li $v0, 4
		syscall
		
		addi $s1, $s1, 1
		j i_loop
	end_i_loop:
	restore_context
	jr $ra
