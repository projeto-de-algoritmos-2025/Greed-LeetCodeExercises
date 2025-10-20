# Trabalho 2: Soluções de Algoritmos Ambiciosos (LeetCode)

**Disciplina**: Projeto de Algoritmos (FGA0124) 

**Professor**: Maurício Serrano

## 📖 Sobre o Projeto

Este repositório contém as soluções desenvolvidas para o **Trabalho 3** da disciplina de Projeto de Algoritmos. O objetivo principal foi aplicar e demonstrar o conhecimento teórico adquirido em aula através da resolução de desafios práticos da plataforma LeetCode.

Nós selecionamos e implementamos a solução para três problemas, sendo os três de nível Difícil, focando em diferentes algoritmos e estruturas de dados, como Estratégias Ambiciosas (Greedy).

## 👥 Equipe

| Matrícula  | Aluno                               |
| :--------- | :---------------------------------- |
| 231028989  | Joao Pedro Ferreira Moraes          |
| 231026680  | Cibelly Lourenço Ferreira           |


## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++

## 🚀 Desafios Resolvidos

Abaixo estão detalhados os problemas abordados, com uma breve explicação da estratégia utilizada e o comprovante de submissão.

---
### 1. [44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/)
![](assets/44.png)


#### **Estratégia: Algoritmo Ambicioso (Greedy) com Backtracking** 
A estratégia utilizada foi uma solução otimizada em espaço ($O(1)$) que usa uma abordagem ambiciosa (greedy) com backtracking.

- A ideia é usar dois ponteiros (`s_ptr`, `p_ptr`) para avançar na string e no padrão, tentando sempre uma correspondência direta.
- O `*` é o ponto-chave. Quando um `*` é encontrado, salvamos sua posição (`star_ptr`) e a posição correspondente em `s` (`s_match_ptr`). Em seguida, avançamos `p_ptr` (esta é a escolha ambiciosa: assumimos que o `*` corresponde a 0 caracteres).
- Se uma falha (mismatch) ocorre, verificamos se já vimos um `*`.
- Se sim, fazemos o backtracking:
    - 1.Restauramos `p_ptr` para a posição após o `*` salvo.
    - 2.Avançamos `s_match_ptr` em 1 (fazendo o `*` "comer" 1 caractere).
    - 3.Movemos `s_ptr` para essa nova posição `s_match_ptr`.
- Se a falha ocorre e não há `*` para fazer backtrack, a correspondência falha.

**Submissão:**
[Submissão LeetCode 44](https://leetcode.com/problems/wildcard-matching/submissions/1807087294)

![](assets/44Submit.png)





