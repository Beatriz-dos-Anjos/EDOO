.data
a: .word 10
b: .word 20
msg_and: .asciiz "AND- 1\n"
msg_and_false: .asciiz "AND- 0\n"
msg_or: .asciiz "OR- 1\n"
msg_or_false: .asciiz "OR- 0\n"
msg_c_gt_d: .asciiz "C é maior que D\n"
msg_d_gt_c: .asciiz "D é maior ou igual a C ou AND errado\n"

.text
.globl main

main:
    lw $t0, a           # Carregar a
    lw $t1, b           # Carregar b

    add $t2, $t0, $t1   # c = a + b
    mul $t3, $t0, $t1   # d = a * b

    slti $t4, $t0, 6    # a > 5 (invertido para lógica)
    slti $t5, $t1, 25   # b < 25
    and $t6, $t4, $t5   # and_result = (a > 5) && (b < 25)

    slti $t7, $t0, 5    # a < 5
    slti $t8, $t1, 16   # b > 15
    or $t9, $t7, $t8    # or_result = (a < 5) || (b > 15)

    # Imprimir AND
    beq $t6, 1, print_and_true
    la $a0, msg_and_false
    li $v0, 4
    syscall
    j print_or

print_and_true:
    la $a0, msg_and
    li $v0, 4
    syscall

# Imprimir OR
print_or:
    beq $t9, 1, print_or_true
    la $a0, msg_or_false
    li $v0, 4
    syscall
    j compare_c_d

print_or_true:
    la $a0, msg_or
    li $v0, 4
    syscall

# Comparar C e D
compare_c_d:
    bgt $t2, $t3, print_c_gt_d
    la $a0, msg_d_gt_c
    li $v0, 4
    syscall
    j end_program

print_c_gt_d:
    la $a0, msg_c_gt_d
    li $v0, 4
    syscall

end_program:
    li $v0, 10
    syscall
