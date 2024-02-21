# functions.asm
.globl add_numbers
.globl multiply_numbers

.data
    num1: .word 32
    num2: .word 3

.text
    # Function 1
    add_numbers:
        add $v0, $a0, $a1
        jr $ra

    # Function 2
    multiply_numbers:
        mul $v0, $a0, $a1
        jr $ra