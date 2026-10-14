# Parte 01 — Operações com Conjuntos

## Objetivo

Implementar, em linguagem C, operações fundamentais da teoria dos conjuntos sobre dois conjuntos de números inteiros, **A** e **B**, informados pelo usuário por meio do terminal.

## Tecnologias e organização

- **Linguagem:** C (compilação recomendada com GCC e padrão C99 ou posterior).
- **Bibliotecas do programa principal:** `stdio.h`, `stdbool.h` e `unistd.h` (`sleep`, em ambientes POSIX).
- **Organização:** `main.c` controla a entrada e o menu; `funcoes/conjuntos.h` declara as funções; a implementação das funções deve estar em um arquivo `.c` correspondente (por exemplo, `funcoes/conjuntos.c`). Ajuste os caminhos aos nomes reais dos arquivos do repositório.

## Operações disponíveis

| Opção | Operação | Significado |
|---|---|---|
| 1 | União `A ∪ B` | Elementos que pertencem a A ou B |
| 2 | Interseção `A ∩ B` | Elementos comuns aos dois conjuntos |
| 3 | Diferença `A − B` | Elementos de A ausentes em B |
| 4 | Diferença `B − A` | Elementos de B ausentes em A |
| 5 | Diferença simétrica `A △ B` | Elementos que pertencem a apenas um dos conjuntos |
| 6 | Pertinência `x ∈ A` ou `x ∈ B` | Verifica se um elemento pertence ao conjunto escolhido |
| 7–8 | Inclusão `A ⊆ B` e `B ⊆ A` | Verifica se todos os elementos de um conjunto estão no outro |
| 9–10 | Inclusão própria | Verifica inclusão com desigualdade entre os conjuntos |
| 11–12 | Cardinalidade `|A|` e `|B|` | Conta os elementos distintos |
| 13–14 | Complemento `Aᶜ` e `Bᶜ` | Elementos do universo U ausentes no conjunto escolhido |
| 0 | Sair | Encerra a aplicação |

## Decisões de implementação

1. **Vetores de inteiros:** `conjuntoA[100]` e `conjuntoB[100]` armazenam as entradas, enquanto `qtdA` e `qtdB` controlam as quantidades informadas. A entrada é feita com `scanf`.
2. **Funções separadas:** cada operação tem uma função específica, acionada por `switch` no menu. O programa continua em execução até a opção `0`.
3. **Comparação por busca sequencial:** laços `for` aninhados verificam a presença ou ausência de elementos. A união procura elementos de B em A; a interseção procura correspondências; as diferenças selecionam os elementos sem correspondência.
4. **Diferença simétrica:** o algoritmo percorre A e B separadamente, exibindo os elementos exclusivos de cada um. Essa implementação corresponde à ideia `(A − B) ∪ (B − A)`.
5. **Inclusão própria:** além de verificar a presença dos elementos, a implementação compara as quantidades informadas (`qtdA < qtdB` ou o inverso).
6. **Cardinalidade:** a função auxiliar `contarDistintos` ignora repetições anteriores no vetor para contar apenas valores distintos.
7. **Complemento:** o universo U é solicitado no momento da operação e o programa exibe os valores de U que não pertencem a A ou B.

## Como compilar e executar

Considerando a seguinte organização de arquivos:

```text
Parte 01/
└── src/
    ├── main.c
    └── funcoes/
        ├── conjuntos.h
        └── conjuntos.c
```

No terminal, dentro de `Parte 01/src`, execute:

```bash
gcc -std=c99 -Wall -Wextra main.c funcoes/conjuntos.c -o conjuntos
./conjuntos
```

> **Atenção:** os nomes e caminhos acima são um exemplo de organização compatível com o `#include "funcoes/conjuntos.h"` mostrado no `main.c`. Se o arquivo de implementação tiver outro nome ou localização, ajuste o comando. Em Windows, o executável poderá ser `conjuntos.exe`. O uso de `unistd.h`/`sleep` pode exigir adaptação fora de ambientes POSIX.

## Casos de teste

Use inicialmente os conjuntos **A = {1, 2, 3}** e **B = {3, 4, 5}**. Os resultados abaixo são **esperados a partir da lógica do código**, e não transcrições de uma execução comprovada.

| Opção | Teste | Resultado esperado |
|---|---|---|
| 1 | União | `{1, 2, 3, 4, 5}` |
| 2 | Interseção | `{3}` |
| 3 | A − B | `{1, 2}` |
| 4 | B − A | `{4, 5}` |
| 5 | Diferença simétrica | `{1, 2, 4, 5}` |
| 6 | Elemento `3` em A | Pertence |
| 6 | Elemento `4` em A | Não pertence |
| 7 | A ⊆ B | Não |
| 8 | B ⊆ A | Não |
| 9 | A propriamente contido em B | Não |
| 10 | B propriamente contido em A | Não |
| 11 | Cardinalidade de A | `3` |
| 12 | Cardinalidade de B | `3` |
| 13 | Complemento de A, com U = {1,2,3,4,5,6} | `{4, 5, 6}` |
| 14 | Complemento de B, com o mesmo U | `{1, 2, 6}` |

### Testes adicionais

- **Inclusão própria positiva:** A = `{1, 2}`, B = `{1, 2, 3}` → A está propriamente contido em B.
- **Cardinalidade com repetição:** A informado como `1, 1, 2, 3` → `|A| = 3`, porque `contarDistintos` desconsidera repetições.
- **Conjuntos disjuntos:** A = `{1, 2}`, B = `{3, 4}` → interseção vazia.

## Evidências de execução

Após compilar e executar o programa, adicione capturas de tela reais, por exemplo:

```text
imagens/
├── entrada-e-menu.png
├── uniao-e-intersecao.png
├── diferencas.png
├── inclusao-e-pertinencia.png
└── cardinalidade-e-complemento.png
```

Exemplo de inclusão no README, **após criar a imagem**:

```markdown
![Menu e entrada dos conjuntos](imagens/entrada-e-menu.png)
```

### Exemplo ilustrativo de saída

Para A = `{1, 2, 3}`, B = `{3, 4, 5}` e opção `5`, o programa deve exibir algo equivalente a:

```text
Diferença simétrica = { 1 2 4 5 }
```

> O trecho acima é uma saída **prevista pelo código**, não um log coletado de execução.

## Limitações e melhorias possíveis

- **Elementos repetidos:** a entrada não impede duplicatas. União, interseção e outras operações podem imprimir elementos repetidos, contrariando a representação matemática de conjuntos; a cardinalidade, por outro lado, conta valores distintos.
- **Capacidade dos vetores:** o programa reserva 100 posições para A e B, mas não valida se as quantidades informadas estão entre 0 e 100.
- **Validação de entrada:** não há tratamento para `scanf` com entrada inválida ou para tamanhos negativos. O universo do complemento também não é validado.
- **Inclusão própria:** compara quantidades informadas, não cardinalidades distintas. Com valores repetidos, a conclusão pode ser incorreta.
- **Formatação:** em `diferencaAB` e `diferencaBA`, quando o resultado é vazio, a função retorna antes de imprimir a chave de fechamento.
- **Cabeçalho:** as funções `cardinalidadeA` e `cardinalidadeB` são chamadas em `main.c`, mas não aparecem no `conjuntos.h` fornecido. É necessário adicionar seus protótipos para evitar problemas de compilação em C moderno.

## Conclusão

A Parte 01 aplica conceitos da teoria dos conjuntos por meio de vetores, laços de repetição, comparações e funções em C. O programa cobre operações fundamentais e permite observar como propriedades matemáticas podem ser traduzidas em algoritmos. As melhorias prioritárias são validar as entradas, impedir duplicatas e ajustar as declarações das funções.
