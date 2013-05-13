respostas = []
while(1):
	pilha = []
	resposta = ""
	substituidos = 0
	linha1 = raw_input().split()
	n = int(linha1[0])
	d = int(linha1[1])
	if n == 0 and d == 0:
		break
	c = raw_input()
	for numero in c:
		num = int(numero)
		while(len(pilha) != 0 and pilha[len(pilha) - 1] < num and substituidos < d):
			pilha.pop()
			substituidos += 1
		pilha.append(num)
	while(substituidos < d):
		pilha.pop()
		substituidos += 1
	for p in pilha:
		resposta += str(p)
	respostas.append(resposta)
for r in respostas:
	print r
	
