public class Exercicio6 
{
	public static void main(String[] args) {
		long a = 1L;
		long b = 0L;
		long c = 1L;
		int i = 0;
		do{
			System.out.println(a);
			a = b+a;
			b = c;
			c = a;
			i++; 
		} while(i < 100);
	}
}