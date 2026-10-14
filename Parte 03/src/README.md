# Parte 03 — Operações com Intervalos Reais

## 1. Objetivo

Esta etapa do **Laboratório de Conjuntos** implementa, em Java, a representação de intervalos da reta real e três operações fundamentais: **pertinência**, **interseção** e **união**. O programa diferencia extremidades abertas e fechadas, admite limites infinitos e executa testes de comportamento e validação.

## 2. Organização e tecnologias

| Arquivo | Responsabilidade |
| --- | --- |
| `Intervalo.java` | Representar intervalos e implementar `contem`, `interseccao`, `uniao` e `toString`. |
| `Main.java` | Executar casos de teste e exibir resultados no terminal. |

**Linguagem:** Java. **Bibliotecas:** `java.util.Optional`, `java.util.List` e `java.util.ArrayList`. Não há dependências externas. Para compilar, utilize um JDK com suporte às APIs empregadas (por exemplo, Java 17).

## 3. Fundamentação matemática

Um intervalo reúne números reais entre dois limites, respeitando a inclusão ou exclusão das extremidades:

- **Fechado:** `[1, 5]` inclui 1 e 5.
- **Aberto:** `(1, 5)` exclui 1 e 5.
- **Semiaberto:** `[1, 5)` inclui 1 e exclui 5.
- **Ilimitado:** `[0, +∞)` inclui todos os reais maiores ou iguais a zero; infinito nunca é um elemento incluído.

As operações correspondem a:

- **Pertinência:** `x ∈ A` verifica se um número está no intervalo.
- **Interseção:** `A ∩ B` reúne os elementos comuns aos dois intervalos.
- **União:** `A ∪ B` reúne os elementos que pertencem a pelo menos um dos intervalos.

Por exemplo, `[1, 5] ∩ [3, 8] = [3, 5]` e `[1, 3] ∪ [2, 5] = [1, 5]`. Já `[1, 3] ∪ [5, 8]` permanece como dois intervalos separados.

## 4. Decisões de implementação

### 4.1 Representação dos intervalos

A classe `Intervalo` guarda quatro campos privados e `final`: `double inicio`, `double fim`, `boolean fechadoInicio` e `boolean fechadoFim`. Assim, cada objeto mantém os mesmos limites e indicadores de fechamento após a construção.

O construtor rejeita início maior que fim (`IllegalArgumentException`) e intervalos com limites iguais quando alguma extremidade é aberta. O intervalo pontual `[3, 3]` é permitido. Quando um limite é infinito, seu indicador de fechamento é forçado a `false`.

### 4.2 Pertinência — `contem(double x)`

O método compara `x` aos limites: igualdade com uma extremidade só é aceita quando ela está fechada. O resultado é `true` apenas quando as duas condições são satisfeitas.

### 4.3 Interseção — `interseccao(Intervalo outro)`

A interseção utiliza o **maior início** e o **menor fim** dos intervalos. Se os inícios forem iguais, a extremidade resultante só é fechada se ambas forem fechadas; o mesmo vale para os fins. Se não houver elementos comuns, retorna `Optional.empty()` em vez de criar um intervalo inválido. Um encontro em um único ponto só produz interseção se esse ponto pertencer aos dois intervalos.

### 4.4 União — `uniao(Intervalo outro)`

O método primeiro ordena os intervalos pelo início. Se eles se sobrepõem ou se encontram em um ponto incluído por pelo menos um deles, devolve um único intervalo que cobre ambos. Caso contrário, devolve os dois intervalos em uma `List<Intervalo>`. Isso é necessário porque a união de intervalos separados nem sempre é um intervalo único.

### 4.5 Exibição e testes

`toString()` usa `[` e `]` para extremidades fechadas e `(` e `)` para abertas. A classe `Main` agrupa os exemplos em `testarContem`, `testarInterseccao`, `testarUniao`, `testarValidacoes` e `testarInfinitos`. O método auxiliar `tentarCriar` captura exceções esperadas para que os testes continuem.

## 5. Como compilar e executar

Coloque `Intervalo.java` e `Main.java` na mesma pasta e execute, em um terminal com JDK instalado:

```bash
javac Intervalo.java Main.java
java Main
```

O programa executa automaticamente todos os testes, sem solicitar entradas pelo teclado.

## 6. Casos de teste

As tabelas abaixo descrevem **resultados esperados pela leitura do código fornecido**. Não representam logs capturados de uma execução efetiva.

### 6.1 Pertinência

| Intervalo | Valor | Esperado |
| --- | ---: | --- |
| `[1, 5]` | `1` | `true` |
| `[1, 5]` | `5` | `true` |
| `[1, 5]` | `3` | `true` |
| `[1, 5]` | `0.99` | `false` |
| `[1, 5]` | `5.1` | `false` |
| `(1, 5)` | `1` | `false` |
| `(1, 5)` | `5` | `false` |
| `(1, 5)` | `3` | `true` |

### 6.2 Interseção

| Intervalos | Esperado |
| --- | --- |
| `[1, 5] ∩ [3, 8]` | `[3, 5]` |
| `[1, 5] ∩ [5, 8]` | `[5, 5]` |
| `[1, 5] ∩ (5, 8]` | Vazia |
| `[1, 5) ∩ [5, 8]` | Vazia |
| `[1, 2] ∩ [3, 4]` | Vazia |
| `[1, 5] ∩ (1, 5)` | `(1, 5)` |

### 6.3 União

| Intervalos | Esperado |
| --- | --- |
| `[1, 3] ∪ [2, 5]` | `[1, 5]` |
| `[1, 3] ∪ [5, 8]` | `[1, 3]` e `[5, 8]` |
| `[5, 8] ∪ [1, 3]` | `[1, 3]` e `[5, 8]`, em ordem |
| `[1, 3) ∪ (3, 5]` | `[1, 3)` e `(3, 5]` |
| `[1, 3) ∪ [3, 5]` | `[1, 5]` |
| `[1, 3] ∪ (3, 5]` | `[1, 5]` |
| `[1, 10] ∪ [3, 4]` | `[1, 10]` |
| `(1, 5) ∪ [1, 5]` | `[1, 5]` |

### 6.4 Validação do construtor

| Tentativa | Esperado |
| --- | --- |
| `[5, 1]` | Erro: `O início não pode ser maior que o fim.` |
| `[3, 3)` | Erro: `Intervalo vazio.` |
| `(3, 3]` | Erro: `Intervalo vazio.` |
| `[3, 3]` | Criado: `[3.0, 3.0]` |

### 6.5 Limites infinitos

| Operação | Esperado |
| --- | --- |
| Criar `[0, +∞)` | `[0.0, Infinity)` |
| Verificar `1e300 ∈ [0, +∞)` | `true` |
| Verificar `-1 ∈ [0, +∞)` | `false` |
| `(-∞, 3] ∩ [0, +∞)` | `[0, 3]` |
| `(-∞, 0) ∪ [0, +∞)` | `(-∞, +∞)` |

**Total:** 31 verificações/resultados esperados (8 de pertinência, 6 de interseção, 8 de união, 4 de validação e 5 envolvendo infinito, incluindo a criação do intervalo).

### Exemplo de saída esperada

```text
===== interseccao =====
[1.0, 5.0] ∩ [3.0, 8.0] = [3.0, 5.0]
[1.0, 5.0] ∩ [5.0, 8.0] = [5.0, 5.0]
[1.0, 5.0] ∩ (5.0, 8.0] = vazia
```

## 7. Evidências de execução

Para gerar um log real, execute os comandos a seguir no terminal:

```bash
javac Intervalo.java Main.java
java Main > execucao-parte03.log
```

Depois, abra `execucao-parte03.log` e capture prints das seções `contem`, `interseccao`, `uniao`, `validacoes` e `infinitos`. Salve as imagens, por exemplo, em `imagens/` e inclua-as neste README após confirmar que os arquivos existem:

```markdown
![Testes de interseção](imagens/testes-interseccao.png)
![Testes de união](imagens/testes-uniao.png)
```

**Nota:** não foram fornecidos prints nem logs de execução real. Os nomes de imagens acima são sugestões, não arquivos já existentes.

## 8. Limitações e possíveis melhorias

- **`double` e precisão:** a representação de números reais é aproximada; comparações de igualdade podem sofrer efeitos de arredondamento em cálculos anteriores.
- **`NaN`:** o construtor não rejeita `Double.NaN`; isso pode gerar objetos sem significado matemático claro.
- **Valores especiais:** convém validar explicitamente `NaN` e entradas infinitas em métodos públicos, para tornar as regras do domínio mais claras.
- **Testes:** os exemplos são impressos no console, sem asserções automáticas que sinalizem falhas. Uma evolução seria utilizar JUnit.
- **Escopo:** a implementação trabalha com dois intervalos por operação; uma extensão poderia operar sobre coleções de intervalos e normalizar seus resultados.

## 9. Conclusão

A Parte 03 traduz conceitos de conjuntos da reta real para uma implementação orientada a objetos. As decisões sobre abertura e fechamento das extremidades são essenciais para determinar corretamente pertinência, interseção e união, principalmente quando dois intervalos se encontram em um único ponto.
