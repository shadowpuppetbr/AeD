# Gustavo dos santos leon

## 1763. Longest Nice Substring

A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

Exemplo 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.

Exemplo 2:
Input: s = "dDzeE"
Output: "dD"


Exemplo 3:
Input: s = "ijIJwuUnW"
Output: "ijIJ"

No código feito em aula consegui passar nos três casos iniciais do LeetCode, porem estava com um erro de buffer overflow que não resolvi até o final da aula, funcionava no VScode os casos de exemplo

Ao chegar em casa e concluir o código, no Submit vários outros erros foram encontrados e não consgui bolar uma solução que abrangesse todos os casos

Apenas ao final como ultimo recurso eu pesquisei uma solução e implementei segundo ela tentando entender o que eu estava fazendo de errado

