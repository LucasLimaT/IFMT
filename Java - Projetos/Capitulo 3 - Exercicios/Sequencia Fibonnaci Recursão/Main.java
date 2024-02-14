public class Main {
    public static void main(String[] args) {
        Fibonnaci sequenciaFibonnaci = new Fibonnaci();
        for (int i = 1; i <= 10; i++){         
            int resultado = sequenciaFibonnaci.calculaFibonnaci(i);
            System.out.println(resultado);
        }
    }
}