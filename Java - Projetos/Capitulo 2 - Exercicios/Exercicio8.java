public class Exercicio8 {
    public static void main(String[] args) {
        for(int i = 1; i<=10; i++){
            System.out.println();
            int cont = 1;
            for(int j = i; cont < i+1; cont++, j=i*cont){
                System.out.print(j + " ");
            }
        }
    }
}