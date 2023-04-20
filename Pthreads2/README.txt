PThreads parte 2

a) No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?

R: O código apresentado implementa uma estimativa do valor de pi utilizando a série de Leibniz e processamento paralelo com threads. 
As diferenças entre os valores atingidos podem ocorrer devido a diferentes fatores, como: 
- a precisão dos valores utilizados na operação de ponto flutuante
- o número de threads usado 
- o número de termos da série de Leibniz utilizados 
- a distribuição dos termos entre as threads
Além disso, pode haver divergências devido a condições de corrida que ocorrem quando várias threads acessam e modificam uma variável compartilhada ao mesmo tempo, sem sincronização adequada. No código apresentado, a variável `sum` é compartilhada entre as threads e modificada de forma concorrente. Por isso, é necessário utilizar mecanismos de sincronização, como mutexes ou atomicidade, para evitar condições de corrida e garantir resultados consistentes.

b) Implemente uma solução utilizando Mutex e comparece com a anterior. O que mudou? Por quê?

A principal diferença entre os dois códigos é que o segundo utiliza uma variável mutex para garantir a exclusão mútua na seção crítica, que é o acesso à variável sum. A variável mutex é inicializada antes de criar as threads, é bloqueada antes de acessar a variável sum e é desbloqueada após a atualização da variável. Isso garante que apenas uma thread pode acessar a variável sum por vez, evitando possíveis conflitos entre as threads.
A implementação com mutex é mais segura e confiável em relação à implementação sem mutex, pois garante a exclusão mútua, o que significa que os resultados serão consistentes e corretos independentemente de como as threads forem escalonadas pelo sistema operacional. Sem o uso de mutex, existe a possibilidade de que duas ou mais threads acessem a variável sum ao mesmo tempo, causando uma condição de corrida e produzindo resultados inconsistentes e imprevisíveis.
