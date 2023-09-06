<h1> AP2-Trab1 </h1>
Trabalho 1 de Algoritmos e Programação 2
<h2> Alunos </h2>
<ul>
    <li>Marco Antonio Batista de Souza</li>
    <li>Rafael Romancini</li>
</ul>
<h2>Enunciados</h2>
<h3>Questão 1</h3>
<b>Caçadores de Mitos (Adaptado da OBI)</b>
<p>Jorge é um apresentador de televisão que comanda a versão brasileira do grande sucesso “Caçadores de Mitos”, onde se estuda um mito para descobrir se é fato ou apenas um boato.No próximo episódio, Jorge deverá apresentar o mito que diz que ”os raios não caem duas vezes no mesmo lugar”, referindo-se aos raios das tempestades de chuva.Para isso, foi até a cidade de Eletrolândia, que é a cidade com maior ocorrência de raios no mundo. O prefeito tem tanto orgulho desse título que mandou criar um sistema para registrar os raios. Jorge conseguiu um relatório com as ocorrências de cada raio que caiu na cidade nos últimos anos.O mapa de Eletrolândia é um retângulo. Para o sistema de registro a cidade é subdividida em quadrados de um metro de lado, denominados quadrantes. Assim, se a cidade tem 300 metros de largura e 1000 de comprimento, ela será subdividida em 300.000 quadrantes. O sistema de registro armazena o quadrante em que o raio caiu.Cada quadrante é identificado pelas suas coordenadas X e Y, conforme ilustra a figura abaixo, que exemplifica um mapa de uma cidade com oito metros de comprimento por cinco metros de largura (quarenta quadrantes). Além disso, cada quadrante deve conter a data que raio caiu (dia, mês, ano), o valor da intensidade do raio e as condições do tempo (ensolarado, chuvoso, nublado, etc).Como os quadrantes são relativamente pequenos, Jorge decidiu que se dois raios caíram no mesmo quadrante, pode-se considerar que caíram no mesmo lugar.

<b>Tarefa</b>

Sua missão é escrever um programa para ajudar o caçador de mitos a identificar se uma determinada cidade atende ao mito ou não. Você deverá escrever um programa que:
<ul>
    <li> monte um array que represente a largura x altura da cidade. Você pode definir a largura e altura da cidade usando o comando define </li>
    <li> apresente um menu com as seguintes opções: </li>
    <ul>
        <li> Marcar Raio: ler as coordenadas X e Y onde caiu um raio. Nesse caso ler também a data do ocorrido e a intensidade do raio. Caso um raio caiu duas vezes no mesmo lugar, uma mensagem deverá ser impressa na tela e o programa deverá ser encerrado. </li>
        <li> Quantos raios já caíram: imprimir o número de raios que já caíram na cidade. </li>
        <li> Quantas áreas não foram afetadas por raio: imprimir o número de regiões da cidade que não foram afetadas por raio. </li>
    </ul>
</ul>

<h3>Questão 2</h3>
<b>Festa olímpica (Adaptado da OBI)</b>
<p>Os atletas da Nlogônia obtiveram o melhor resultado do país em olimpíadas, e para comemorar o rei decidiu dar uma grande festa no Palácio Real. Todos os atletas foram convidados, mas o rei quer também convidar alguns de seus súditos.Como não é possível convidar todos os súditos, o rei determinou que a seguinte Lei seja utilizada para calcular a lista de convidados:
<p><i>Lei Especial Sobre Comemoração das Olimpíadas</i>
<p>Por ordem de Sua Majestade, fiquem todos sabendo que:
<ul>
    <li>Os N súditos de Nlogônia serão numerados 1, 2, 3, …, N e uma lista ordenada será criada com os números dos súditos. A primeira posição da lista será 1</li>
    <li>Um número M de turnos serão então executados; em cada turno i, será sorteado um número Ti que será usado para remover súditos da lista, da seguinte forma: no turno i, devem ser removidos da lista todos os súditos que ainda continuam na lista e que ocupam posições que são múltiplas de Ti; ou seja, devem ser removidos os súditos que estão nas posições (Ti, 2Ti, 3Ti, …) da lista corrente. Ao final do turno, para não haver posições vazias na lista (cujos súditos foram removidos) a lista é reagrupada, mantendo-se a mesma ordem relativa, e contendo apenas os números dos súditos remanescentes.</li>
    <li>Os súditos que permanecerem na lista ao final dos M turnos serão convidados para a grande festa de comemoração do resultado das olimpíadas.</li>
</ul>
Dados o número de súditos e os números sorteados em cada turno, sua tarefa é determinar os súditos que serão convidados de acordo com a Lei Especial.
<p><b>Entrada</b>
<p>O número inteiro N, refererente o número de súditos de Nlogônia será definido pelo comando define. O usuário deverá informar o inteiro M, que representa o número de turnos. Cada uma das M linhas seguintes contém um inteiro Ti, o número que foi sorteado para o turno i.
<p><b>Saída</b>
<p>Seu programa deve produzir a lista de convidados de acordo com a Lei Especial, com uma linha para cada convidado, cada linha contendo somente o número de um convidado. Como a lista total dos convidados pode ser muito grande, o rei ordenou que, caso o número de convidados seja maior que 10.000, você deve listar apenas os 10.000 primeiros (ou seja, os com menores números) convidados.
