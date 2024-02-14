class Fibonnaci {
    int a = 1;
    int b = 0;
   
    int calculaFibonnaci(int numero) {
        if(numero%2 == 0){
            b += a;
            return b;
        } else {
            a += b;
            return a;
        }
    }
}