import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class Intervalo {

    private final double inicio;
    private final double fim;
    private final boolean fechadoInicio;
    private final boolean fechadoFim;

    public Intervalo(double inicio, boolean fechadoInicio, double fim, boolean fechadoFim) {
        if (inicio > fim) {
            throw new IllegalArgumentException("O início não pode ser maior que o fim.");
        }
        if (inicio == fim && !(fechadoInicio && fechadoFim)) {
            throw new IllegalArgumentException("Intervalo vazio.");
        }
        this.inicio = inicio;
        this.fim = fim;
        // infinito nunca é fechado
        this.fechadoInicio = fechadoInicio && !Double.isInfinite(inicio);
        this.fechadoFim = fechadoFim && !Double.isInfinite(fim);
    }

    public boolean contem(double x) {
        boolean depoisDoInicio = x > inicio || (fechadoInicio && x == inicio);
        boolean antesDoFim = x < fim || (fechadoFim && x == fim);
        return depoisDoInicio && antesDoFim;
    }

    public Optional<Intervalo> interseccao(Intervalo outro) {
        double novoInicio;
        boolean novoFechadoInicio;
        if (inicio > outro.inicio) {
            novoInicio = inicio;
            novoFechadoInicio = fechadoInicio;
        } else if (inicio < outro.inicio) {
            novoInicio = outro.inicio;
            novoFechadoInicio = outro.fechadoInicio;
        } else {
            novoInicio = inicio;
            novoFechadoInicio = fechadoInicio && outro.fechadoInicio;
        }

        double novoFim;
        boolean novoFechadoFim;
        if (fim < outro.fim) {
            novoFim = fim;
            novoFechadoFim = fechadoFim;
        } else if (fim > outro.fim) {
            novoFim = outro.fim;
            novoFechadoFim = outro.fechadoFim;
        } else {
            novoFim = fim;
            novoFechadoFim = fechadoFim && outro.fechadoFim;
        }

        if (novoInicio > novoFim) return Optional.empty();
        if (novoInicio == novoFim && !(novoFechadoInicio && novoFechadoFim)) return Optional.empty();

        return Optional.of(new Intervalo(novoInicio, novoFechadoInicio, novoFim, novoFechadoFim));
    }

    public List<Intervalo> uniao(Intervalo outro) {
        // 'a' é o que começa primeiro
        Intervalo a = this;
        Intervalo b = outro;
        if (outro.inicio < inicio || (outro.inicio == inicio && outro.fechadoInicio && !fechadoInicio)) {
            a = outro;
            b = this;
        }

        boolean seEncontram = b.inicio < a.fim
                || (b.inicio == a.fim && (a.fechadoFim || b.fechadoInicio));

        List<Intervalo> resultado = new ArrayList<>();

        if (!seEncontram) {
            resultado.add(a);
            resultado.add(b);
            return resultado;
        }

        boolean fechadoIni = (a.inicio == b.inicio) ? (a.fechadoInicio || b.fechadoInicio) : a.fechadoInicio;

        double novoFim;
        boolean fechadoFim;
        if (a.fim > b.fim) {
            novoFim = a.fim;
            fechadoFim = a.fechadoFim;
        } else if (a.fim < b.fim) {
            novoFim = b.fim;
            fechadoFim = b.fechadoFim;
        } else {
            novoFim = a.fim;
            fechadoFim = a.fechadoFim || b.fechadoFim;
        }

        resultado.add(new Intervalo(a.inicio, fechadoIni, novoFim, fechadoFim));
        return resultado;
    }

    @Override
    public String toString() {
        return (fechadoInicio ? "[" : "(") + inicio + ", " + fim + (fechadoFim ? "]" : ")");
    }
}