//Exercicio 4 e 5
public class Exercicio4e5
{
	public static void main(String[] args) {
		for(int i = 40; i > 0; i--){
		long soma = 1L;
		    for(int x = i; x > 0; x--){
		        soma *= x;
		    }
		    System.out.println(i +" fatorial e "+ soma);
		}
	}
}
