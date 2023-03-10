#Alguns exercícios com processos

1- Rode o programa anterior para valores grandes de n. As
mensagens sempre estarão ordenadas pelo valor de i?
R: O valor de i foi impresso de maneira ordenada:

i:1788 process ID:4620 parent ID:1 child ID:4621
i:1789 process ID:4621 parent ID:1 child ID:4622
i:1790 process ID:4622 parent ID:1 child ID:4623
i:1791 process ID:4623 parent ID:1 child ID:4624
i:1792 process ID:4624 parent ID:1 child ID:4625
i:1793 process ID:4625 parent ID:1 child ID:4626
i:1794 process ID:4626 parent ID:1 child ID:4627
i:1795 process ID:4627 parent ID:1 child ID:4628

2- que acontece se o programa anterior escreve-se as mensagens
para sys.stdout, usando print, ao invés de para sys.stderr?

Tendo alterado o código e compilado, não foram encontradas mudanças significativas no log.
i:1788 process ID:24263 parent ID:1 child ID:24264
i:1789 process ID:24264 parent ID:1 child ID:24265
i:1790 process ID:24265 parent ID:1 child ID:24266
i:1791 process ID:24266 parent ID:1 child ID:24267
i:1792 process ID:24267 parent ID:1 child ID:24268
i:1793 process ID:24268 parent ID:1 child ID:24269
i:1794 process ID:24269 parent ID:1 child ID:24270
i:1795 process ID:24270 parent ID:1 child ID:24271


