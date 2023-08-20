
ponteiro: clear
	@echo "========================================="
	@echo "		AJUDA		"
	@echo "========================================="
	@echo "Compilando o programa ponteiro"
	gcc ponteiro.c -o ponteiro
	@echo "Tornando o programa ponteiro executável"
	chmod +x ponteiro
	@echo "Execuando o programa ponteiro executável"
	./ponteiro
	@echo "========================================="
ola: clear
	@echo "========================================="
	@echo "		AJUDA		"
	@echo "========================================="
	@echo "Compilando o programa olamundo"
	@gcc olamundo.c -o ola
	@echo "Tornando o programa olamundo executável"
	@chmod +x ola
	@echo "Execuando o programa olamundo executável"
	@./ola
	@echo "========================================="
clear:
	@echo "========================================="
	@echo "Removendo os programas compilados"
	@echo "========================================="
	@echo "Removendo o olamundo"
	rm -f ola
	@echo "========================================="
help:
	@echo "==================="
	@echo "      AJUDA        "
	@echo "==================="
	@echo "help 	|ajuda"
	@echo "ola  	|executa mensagem de teste"
	@echo "clear	|apaga códigos compilados"