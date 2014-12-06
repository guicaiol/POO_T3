=====
Trabalho 3 - SCC0604 - Programação Orientada a Objetos
Aluno: Guilherme Caixeta de Oliveira - 8504368
=====

O projeto funciona como um simulador de batalhas de até 2-4 times de 3 jogadores.
O usuário faz uma configuração básica dos times e os characters são gerados na maior parte aleatoriamente.

O jogo inicia com cada time em um canto do campo, de forma que eles se movimentam e atacam os outros times.
Ganha o time que sobrar vivo (pelo menos 1 jogador); ou pode haver empate, caso atinja o tempo limite do round.

Foram utilizadas threads para o jogo e para cada jogador, de forma que há independência entre eles.
Como a saída é o terminal, haveria sobreposição dos textos por conta das threads.
Por isso, utilizei um mutex para controlar a saída. Sei que por conta dele pode haver bloqueio não desejado nas threads
dos characters, mas foi necessário para montar uma saída menos caótica.

Há a opção de re-simular um jogo com os mesmos times.
Ela estará disponível após rodar o primeiro jogo, quando são criados os times.

A ideia geral da movimentação e do ataque foi bem simplificada, não tratando colisões nem coisas do tipo.

