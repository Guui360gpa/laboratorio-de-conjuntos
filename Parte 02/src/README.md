# Parte 02 — Classificador de Números e Operações Numéricas

## 1. Objetivo

Esta etapa do **Laboratório de Conjuntos** implementa, em Java, a classificação de números nos conjuntos numéricos e duas funcionalidades complementares: geração de números primos e listagem de divisores. O objetivo é relacionar conceitos de teoria dos conjuntos e teoria dos números com estruturas de controle, validação de entradas e algoritmos.

## 2. Funcionalidades

| Classe | Responsabilidade |
| --- | --- |
| `Classificador.java` | Identifica a representação numérica e classifica o valor em ℕ, ℤ, ℚ, 𝕀 e ℝ; calcula frações geratrizes de dízimas periódicas. |
| `Divisores.java` | Encontra e ordena os divisores positivos de um inteiro positivo. |
| `Primos.java` | Gera todos os números primos de 2 até um limite informado, inclusive, usando o Crivo de Eratóstenes. |
| `TesteClassificador.java` | Executa uma sequência de 18 entradas de demonstração e, depois, permite testes interativos. |
| `TesteDivisores.java` | Disponibiliza interface interativa para consultar divisores. |
| `TestePrimos.java` | Disponibiliza interface interativa para gerar primos até um limite. |

## 3. Fundamentação matemática

Os conjuntos numéricos considerados são:

- **ℕ — Naturais:** inteiros não negativos, incluindo `0` na convenção adotada pelo programa.
- **ℤ — Inteiros:** negativos, zero e positivos, sem parte fracionária.
- **ℚ — Racionais:** números representáveis como `a/b`, com `a, b ∈ ℤ` e `b ≠ 0`; incluem decimais finitos e dízimas periódicas.
- **𝕀 — Irracionais:** reais que não podem ser representados por uma razão de inteiros.
- **ℝ — Reais:** união dos racionais com os irracionais.

Assim, **ℕ ⊆ ℤ ⊆ ℚ ⊆ ℝ**, **𝕀 ⊆ ℝ** e **ℚ ∩ 𝕀 = ∅**.

Exemplos: `5 ∈ ℕ, ℤ, ℚ, ℝ`; `-7 ∈ ℤ, ℚ, ℝ`; `1/3 ∈ ℚ, ℝ`; `√2 ∈ 𝕀, ℝ`.

## 4. Decisões de implementação

### 4.1 Classificação de números

O método `Classificador.classificar(String entrada)` escolhe o processamento conforme o formato da entrada. A ordem é importante: primeiro identifica constantes e raízes simbólicas; depois frações, dízimas, inteiros e decimais finitos. Entradas não reconhecidas são rejeitadas.

- **`BigInteger`:** utilizado para representar inteiros de grande magnitude, calcular raiz quadrada inteira, máximo divisor comum (`gcd`) e reduzir frações geratrizes sem depender da precisão de `double`.
- **Expressões regulares (`Pattern` e `Matcher`):** distinguem dízimas no formato `0.(3)` ou `1.1(4)`, raízes como `√2` e `sqrt(9)`, constantes `pi`, `π`, `e`, e decimais com ponto ou vírgula.
- **Frações:** verifica se numerador e denominador são inteiros e se o denominador é diferente de zero. Quando a divisão é exata, encaminha o quociente à classificação de inteiros; caso contrário, classifica como racional e real.
- **Raízes:** calcula `n.sqrt()` e verifica se o quadrado da raiz inteira é igual a `n`. Se for, o resultado é inteiro; se não for, a raiz quadrada de um inteiro não negativo é irracional.
- **Inteiros:** o sinal determina se o número pertence também a ℕ. O programa considera `0` natural.

**Observação:** o código classifica decimais finitos diretamente como ℚ e ℝ, mesmo quando seu valor matemático é inteiro (por exemplo, `5.0`). Trata-se de uma limitação da classificação implementada, não da definição matemática.

### 4.2 Fração geratriz das dízimas

Para uma dízima composta de parte inteira, parte decimal não periódica e período, o código constrói:

- `tudo`: concatenação da parte inteira, parte não periódica e período;
- `base`: concatenação da parte inteira e parte não periódica;
- numerador: `tudo - base`;
- denominador: `(10^p - 1) × 10^k`, onde `p` é o tamanho do período e `k` é o tamanho da parte não periódica.

O sinal é aplicado ao numerador, e a fração é simplificada por `gcd`.

Exemplos:

- `0.(3) = (3 - 0)/9 = 1/3`.
- `0.1(6) = (16 - 1)/90 = 1/6`.
- `1.1(4) = (114 - 11)/90 = 103/90`.
- `0.(9) = 9/9 = 1`, portanto é classificado como natural, inteiro, racional e real.

### 4.3 Crivo de Eratóstenes

Em `Primos.crivoDeEratostenes(int limite)`, um vetor `boolean[] ehComposto` representa quais inteiros já foram marcados como compostos. Para cada primo `p` até `√limite`, o algoritmo marca seus múltiplos a partir de `p²`. Os índices não marcados de `2` até o limite são adicionados a uma lista.

Essa abordagem evita testar a primalidade de cada número separadamente. Sua complexidade típica é **O(n log log n)** em tempo e **O(n)** em memória.

### 4.4 Listagem de divisores

Em `Divisores.divisores(int numero)`, o algoritmo percorre candidatos `i` até `√numero`. Se `numero % i == 0`, adiciona tanto `i` quanto `numero/i`, evitando duplicação quando ambos são iguais (quadrados perfeitos). Ao final, `Collections.sort` organiza o resultado em ordem crescente. O número de verificações é da ordem de **O(√n)**, além do custo da ordenação dos divisores encontrados.

### 4.5 Organização e validação

A lógica principal fica separada das classes `Teste*`, que possuem `main` e permitem execução pelo terminal. As entradas são lidas com `Scanner`. As validações para primos e divisores usam `Integer.parseInt`, enquanto o classificador aceita inteiros maiores com `BigInteger`.

## 5. Requisitos e execução

- **JDK 17 ou superior** (necessário, entre outros motivos, para `BigInteger.sqrt()`, introduzido no Java 9).
- Terminal com `java` e `javac` disponíveis.
- Arquivos `.java` salvos com os nomes correspondentes às classes públicas.

Se os seis arquivos estiverem na mesma pasta, execute:

```bash
javac -encoding UTF-8 Classificador.java Divisores.java Primos.java TesteClassificador.java TesteDivisores.java TestePrimos.java
```

Para abrir cada módulo:

```bash
java TesteClassificador
java TesteDivisores
java TestePrimos
```

Execute **um comando por vez**, conforme a funcionalidade desejada. No modo interativo, digite `sair` para encerrar.

> **Atenção:** o código colado na conversa apresenta caracteres de escape e formatação de Markdown. Os comandos acima pressupõem os arquivos Java originais, com strings e expressões regulares válidas, salvos separadamente.

## 6. Casos de teste

### 6.1 Classificador — 18 entradas presentes em `TesteClassificador.java`

As saídas abaixo são **resultados esperados pela lógica do código enviado**, não logs capturados de uma execução.

| Entrada | Resultado esperado |
| --- | --- |
| `0.(3)` | Fração geratriz `1/3`; racional e real |
| `1.1(4)` | Fração geratriz `103/90`; racional e real |
| `0.1(6)` | Fração geratriz `1/6`; racional e real |
| `1.(45)` | Fração geratriz `16/11`; racional e real |
| `-0.(3)` | Fração geratriz `-1/3`; racional e real |
| `.(3)` | Fração geratriz `1/3`; racional e real |
| `0.(9)` | Fração geratriz `1/1`; natural, inteiro, racional e real |
| `-0.(9)` | Fração geratriz `-1/1`; inteiro, racional e real |
| `5` | Natural, inteiro, racional e real |
| `-7` | Inteiro, racional e real |
| `3.14` | Racional e real |
| `6/3` | Natural, inteiro, racional e real |
| `1/3` | Racional e real |
| `5/0` | Mensagem de divisão por zero |
| `pi` | Irracional e real |
| `√2` | Irracional e real |
| `sqrt(9)` | Natural, inteiro, racional e real |
| `abc` | Entrada inválida |

### 6.2 Primos — testes sugeridos

| Entrada | Saída esperada |
| --- | --- |
| `0` | `Primos até 0: []` |
| `1` | `Primos até 1: []` |
| `2` | `Primos até 2: [2]` |
| `10` | `Primos até 10: [2, 3, 5, 7]` |
| `20` | `Primos até 20: [2, 3, 5, 7, 11, 13, 17, 19]` |
| `-3` | Mensagem de entrada inválida |

### 6.3 Divisores — testes sugeridos

| Entrada | Saída esperada |
| --- | --- |
| `1` | `Divisores de 1: [1]` |
| `12` | `Divisores de 12: [1, 2, 3, 4, 6, 12]` |
| `16` | `Divisores de 16: [1, 2, 4, 8, 16]` |
| `17` | `Divisores de 17: [1, 17]` |
| `0` | Mensagem de entrada inválida |

## 7. Evidências de execução

Os prints e logs reais **ainda devem ser capturados no ambiente de desenvolvimento**. Recomenda-se registrar pelo menos:

1. Compilação bem-sucedida dos seis arquivos.
2. Execução de `java TesteClassificador`, mostrando dízima, fração, inteiro negativo e raiz irracional.
3. Execução de `java TestePrimos` com entrada `20`.
4. Execução de `java TesteDivisores` com entrada `12`.
5. Tratamento de uma entrada inválida e de uma divisão por zero.

Após capturar as imagens, salve-as, por exemplo, em `imagens/` e substitua os caminhos abaixo pelos nomes reais:

```markdown
![Testes do classificador](imagens/testes-classificador.png)
![Crivo de Eratóstenes](imagens/teste-primos.png)
![Listagem de divisores](imagens/teste-divisores.png)
```

## 8. Limitações e melhorias possíveis

- Decimais finitos como `5.0` são classificados apenas como racionais e reais, sem reconhecer que representam inteiros.
- O classificador imprime os conjuntos, mas não apresenta uma justificativa textual detalhada em todos os caminhos de execução.
- A identificação de raízes cobre apenas as formas positivas previstas na expressão regular e as constantes simbólicas reconhecidas.
- O crivo usa um vetor proporcional ao limite informado, o que pode consumir muita memória para entradas elevadas.
- Em `Primos`, expressões como `primo * primo` e `limite + 1` podem sofrer overflow para limites próximos ao máximo de `int`; uma melhoria é utilizar `long` nos cálculos intermediários e validar o limite de alocação.
- Em `Divisores`, a condição `i * i <= numero` também pode sofrer overflow para entradas muito grandes; uma alternativa é `i <= numero / i`.
- As classes de teste são programas de demonstração e interação, não testes automatizados com verificações (`assert`) de resultados.

## 9. Conclusão

A Parte 02 aplica relações de pertinência e inclusão entre conjuntos numéricos na classificação de valores e utiliza algoritmos de teoria dos números para primos e divisores. A divisão em classes especializadas facilita a leitura e os testes. O cálculo exato de frações geratrizes com `BigInteger` é uma decisão importante para evitar erros de arredondamento, enquanto o Crivo de Eratóstenes e a busca de divisores até a raiz quadrada demonstram escolhas de algoritmos mais eficientes do que abordagens ingênuas.
