public class Main{
	public static void main(String[] args) {
		Cliente cliente1 = new Cliente();
		double depositado = 200;
		double sacado = 100;

		cliente1.titular = "Robson";
		cliente1.agencia = "123";
		cliente1.data_de_abertura = "13/02/2024";
		cliente1.numero = 01;
		cliente1.saldo = 0;

		Cliente cliente2 = new Cliente();
		cliente2 = cliente1;

		if(cliente1 == cliente2) {
			System.out.println("Sao iguais");
		}	else {
			System.out.println("Sao diferentes");
		}

		cliente1.deposito(cliente1, depositado);
		cliente1.saque(cliente1, sacado);
		cliente1.rendimento(cliente1);
		System.out.println("\n" + cliente1.recuperaDadosParaImpressao());
	}
}