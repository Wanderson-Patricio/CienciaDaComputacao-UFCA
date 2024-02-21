.text
	li $a0, 4			#reserva a variável n em $a0 para ser o parâmetro da função
	jal fib
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	#finaliza o programa
	li $v0, 10
	syscall
	
fib:
	addi $sp, $sp, -8		#reseva espaço para duas variáveis na memória
	sw $ra, 4($sp)			#guarda o endereço de retorno
	sw $a0, 0($sp)			#guarda o argumento
	
	slti $t0, $a0, 3		#if n<3 then t0 = 1 else t0 = 0
	beq $t0, $0, rec_case
	
	li $v0, 1			#caso base (n == 1 ou n == 2)
	addi $sp, $sp, 8		#restaura a pilha
	jr $ra				#volta o escopo de quem chamou
	
rec_case:

	addi $a0, $a0, -1		#decrementa n em 1
	jal fib				#chama fib(n-1)
	move $t1, $v0
	
	lw $a0, 0($sp) 			# restaura n original
 	lw $ra, 4($sp) 			# restaura $ra
 	addi $sp, $sp, 8 		# Restaura pilha, pop 2 itens
	
	addi $a0, $a0, -2		#decrementa n em 2
	jal fib				#chama fib(n-2)
	lw $a0, 0($sp) 			# restaura n original
 	lw $ra, 4($sp) 			# restaura $ra
 	addi $sp, $sp, 8 		# Restaura pilha, pop 2 itens
	
 	add $v0, $v0, $t1
	jr $ra


