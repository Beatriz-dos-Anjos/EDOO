    .data
prompt:     .asciiz "Digite o numero do dia da semana (1-3): "  # Mensagem para o usuário
dias:       .asciiz "Segunda\0Terça\0Quarta"  # Resultados concatenados
erro:       .asciiz "Erro"

    .text
    .globl main
main:
    li $v0, 4                  # Serviço para imprimir string
    la $a0, prompt             # Endereço da mensagem
    syscall

    li $v0, 5                  # Serviço para ler um inteiro
    syscall
    move $t0, $v0              # Armazena a entrada (número do dia) em $t0

    # Multiplica o número do dia por 7 (número de caracteres em cada dia)
    sub $t0, $t0, 1            # Ajuste para indexação (1 -> 0, 2 -> 1, 3 -> 2)
    li $t1, 7                  # Tamanho de cada nome de dia
    mul $t0, $t0, $t1          # Multiplica o índice pelo tamanho
    la $a0, dias               # Endereço inicial da string "Segunda"
    add $a0, $a0, $t0          # Ajusta o ponteiro para o dia correto

    # Verifica se o valor é 0, 7 ou 14 (acessa o nome do dia correto)
    li $t2, 0                  # Caso 1: Segunda
    beq $t0, $t2, print_day
    li $t2, 7                  # Caso 2: Terça
    beq $t0, $t2, print_day
    li $t2, 14                 # Caso 3: Quarta
    beq $t0, $t2, print_day

    # Caso default: Erro
    li $v0, 4                  # Serviço para imprimir string
    la $a0, erro               # Endereço de "Erro"
    syscall
    j end_program              # Finaliza o programa

print_day:
    li $v0, 4                  # Serviço para imprimir string
    syscall                    # Imprime o nome do dia

end_program:
    li $v0, 10                 # Código para terminar o programa
    syscall
