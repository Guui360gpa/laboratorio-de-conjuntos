import java.util.List;
import java.util.Optional;

public class Main {

    public static void main(String[] args) {
        testarContem();
        testarInterseccao();
        testarUniao();
        testarValidacoes();
        testarInfinitos();
    }

    // ---------- contem ----------
    static void testarContem() {
        System.out.println("===== contem =====");

        Intervalo fechado = new Intervalo(1, true, 5, true);
        Intervalo aberto = new Intervalo(1, false, 5, false);

        System.out.println(fechado + " contem 1?    " + fechado.contem(1));    // true
        System.out.println(fechado + " contem 5?    " + fechado.contem(5));    // true
        System.out.println(fechado + " contem 3?    " + fechado.contem(3));    // true
        System.out.println(fechado + " contem 0.99? " + fechado.contem(0.99)); // false
        System.out.println(fechado + " contem 5.1?  " + fechado.contem(5.1));  // false

        System.out.println(aberto + " contem 1?    " + aberto.contem(1));      // false
        System.out.println(aberto + " contem 5?    " + aberto.contem(5));      // false
        System.out.println(aberto + " contem 3?    " + aberto.contem(3));      // true
        System.out.println();
    }

    // ---------- interseccao ----------
    static void testarInterseccao() {
        System.out.println("===== interseccao =====");

        interseccao(new Intervalo(1, true, 5, true),  new Intervalo(3, true, 8, true));   // [3.0, 5.0]
        interseccao(new Intervalo(1, true, 5, true),  new Intervalo(5, true, 8, true));   // [5.0, 5.0]
        interseccao(new Intervalo(1, true, 5, true),  new Intervalo(5, false, 8, true));  // vazia
        interseccao(new Intervalo(1, true, 5, false), new Intervalo(5, true, 8, true));   // vazia
        interseccao(new Intervalo(1, true, 2, true),  new Intervalo(3, true, 4, true));   // vazia
        interseccao(new Intervalo(1, true, 5, true),  new Intervalo(1, false, 5, false)); // (1.0, 5.0)
        System.out.println();
    }

    // ---------- uniao ----------
    static void testarUniao() {
        System.out.println("===== uniao =====");

        uniao(new Intervalo(1, true, 3, true),  new Intervalo(2, true, 5, true));   // [1.0, 5.0]
        uniao(new Intervalo(1, true, 3, true),  new Intervalo(5, true, 8, true));   // dois intervalos
        uniao(new Intervalo(5, true, 8, true),  new Intervalo(1, true, 3, true));   // dois, em ordem
        uniao(new Intervalo(1, true, 3, false), new Intervalo(3, false, 5, true));  // dois (o 3 fica de fora)
        uniao(new Intervalo(1, true, 3, false), new Intervalo(3, true, 5, true));   // [1.0, 5.0]
        uniao(new Intervalo(1, true, 3, true),  new Intervalo(3, false, 5, true));  // [1.0, 5.0]
        uniao(new Intervalo(1, true, 10, true), new Intervalo(3, true, 4, true));   // [1.0, 10.0]
        uniao(new Intervalo(1, false, 5, false), new Intervalo(1, true, 5, true));  // [1.0, 5.0]
        System.out.println();
    }

    // ---------- construtor ----------
    static void testarValidacoes() {
        System.out.println("===== validacoes =====");

        tentarCriar(5, true, 1, true);   // erro: início maior que o fim
        tentarCriar(3, true, 3, false);  // erro: intervalo vazio
        tentarCriar(3, false, 3, true);  // erro: intervalo vazio
        tentarCriar(3, true, 3, true);   // ok: [3.0, 3.0]
        System.out.println();
    }

    // ---------- infinito ----------
    static void testarInfinitos() {
        System.out.println("===== infinitos =====");

        double inf = Double.POSITIVE_INFINITY;
        double menosInf = Double.NEGATIVE_INFINITY;

        Intervalo semLimiteSuperior = new Intervalo(0, true, inf, true);
        System.out.println("Criado: " + semLimiteSuperior);                           // [0.0, Infinity)
        System.out.println("contem 1e300? " + semLimiteSuperior.contem(1e300));       // true
        System.out.println("contem -1?    " + semLimiteSuperior.contem(-1));          // false

        interseccao(new Intervalo(menosInf, false, 3, true), new Intervalo(0, true, inf, false)); // [0.0, 3.0]
        uniao(new Intervalo(menosInf, false, 0, false), new Intervalo(0, true, inf, false));      // (-Infinity, Infinity)
        System.out.println();
    }

    // ---------- auxiliares ----------
    static void interseccao(Intervalo a, Intervalo b) {
        Optional<Intervalo> r = a.interseccao(b);
        System.out.println(a + " ∩ " + b + " = " + (r.isPresent() ? r.get() : "vazia"));
    }

    static void uniao(Intervalo a, Intervalo b) {
        List<Intervalo> r = a.uniao(b);
        System.out.println(a + " ∪ " + b + " = " + r);
    }

    static void tentarCriar(double ini, boolean fIni, double fim, boolean fFim) {
        try {
            Intervalo i = new Intervalo(ini, fIni, fim, fFim);
            System.out.println("Criado: " + i);
        } catch (IllegalArgumentException e) {
            System.out.println("Erro ao criar: " + e.getMessage());
        }
    }
}