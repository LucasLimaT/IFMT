class Cliente{
    String titular;
    String agencia;
    String data_de_abertura;
    int numero;
    double saldo;

    void rendimento(Cliente cliente){
        double rendimento = cliente.saldo * 0.1;
        System.out.println("O seu rendimento e de R$" + rendimento + " por mes");
    }

    boolean deposito(Cliente cliente, double valor){
        System.out.println("Saldo antigo: " + cliente.saldo);
        cliente.saldo += valor;
        System.out.println("Saldo novo: " + cliente.saldo);
        return true;
    }

    boolean saque(Cliente cliente, double valor){
        if(cliente.saldo >= valor){
            cliente.saldo -= valor;
            System.out.println("Voce sacou a quantia de " + valor + " e seu novo saldo e: " + cliente.saldo);
            return true;
        } else {
            System.out.println("Saldo insuficiente, operação invalida!\nSaldo disponivel: " + cliente.saldo);
            return false;
        }
    }
}