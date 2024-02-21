# main.asm


.data
    # Your data section here (if any)

.text
    # Include functions from functions.asm
    .include "functions.asm"

    # Your main code here
    main:
        # Call function add_numbers
        li $a0, 4
        li $a1, 5
        jal add_numbers
        # Result is in $v0
        
        move $a0, $v0
        li $v0, 1
        syscall

        # Call function multiply_numbers
        li $a0, 3
        li $a1, 7
        jal multiply_numbers
        # Result is in $v0
	
	move $a0, $v0
        li $v0, 1
        syscall

        # Your main code continues here

        # Exit program
        li $v0, 10
        syscall