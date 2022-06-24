	.data  # 0x10010000 - Itens subsequentes são armazenados no segmento de dados, exe.: variáveis globais, arrays
X:	.word 3
Y:	.word 2
Z:	.word 4
							
	.text  # 0x00400000 - Itens subsequentes são colocados no segmento de texto.
	.globl main  # Declara que o rótulo main é global e pode ser referênciado a partir de outros arquivos
	
main:		
	lw $s0, X	# (load word) carregar o valor de um endereço de memoria X para o registrador $s0 ($s0 = X)
	
	lw $s1, Y	# (load word) carregar o valor de um endereço de memoria Y para o registrador $s1 ($s1 = Y)
	
	lw $s2, Z	# (load word) carregar o valor de um endereço de memoria Z para o registrador $s1 ($s2 = Z)
	
	add $s3,$s0,$s1	# O registrador $s3 recebe o resultado da soma do valor dor registrador $s0 + o valor do registador $s1 ($s3 = $s0 + $s1)
	
	sub $s1,$s3,$s2 # O registrador $s1 recebe o resultado da subtração do valor dor registrador $s3 - o valor do registador $s2 ($s1 = $s3 + $s2)

	sw $s1, Y	# (store word) armazenar o valor do registrador $s1 em um edereço na memoria Y (Y = $s1)
Exit:
	
