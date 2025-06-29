## **Trabalho prático 2: Happy String (1405)**

**Gustavo dos Santos Leon**
*turma M2.*

## **Descrição:**

Um string s é chamada de feliz se atender às seguintes condições:

* s apenas contém as letras 'a', 'b' e 'c'.
* s não contém nenhuma das sequências "aaa", "bbb" ou "ccc" como substring.
* s contém no máximo a ocorrências da letra 'a'.
* s contém no máximo b ocorrências da letra 'b'.
* s contém no máximo c ocorrências da letra 'c'.

Dado três inteiros a, b e c, retorne a string feliz mais longa possível. Se houver múltiplas strings felizes mais longas, retorne qualquer uma delas. Se não houver nenhuma string feliz, retorne a string vazia "".

## **Exemplos:**

* **Exemplo 1:**
 + Entrada: a = 1, b = 1, c = 7
 + Saída: "ccaccbcc"
 + Explicação: "ccbccacc" também seria uma resposta correta.
* **Exemplo 2:**
 + Entrada: a = 7, b = 1, c = 0
 + Saída: "aabaa"
 + Explicação: É a única resposta correta nesse caso.
* **Exemplo 2:**
 + Entrada: a = 1, b = 0, c = 3
 + Saída: "ccac"
 + Explicação: É a única resposta correta nesse caso.

## **Restrições:**

* 0 <= a, b, c <= 100
* a + b + c > 0

