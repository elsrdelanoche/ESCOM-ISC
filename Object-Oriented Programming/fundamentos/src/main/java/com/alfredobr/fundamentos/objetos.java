package com.alfredobr.fundamentos;
public class objetos {
    public static void main(String[] args){
            System.out.println(Math.pow(Math.cbrt(1000),2));
            System.out.println(Math.ceil(8.44422));
            System.out.println(Math.ceil(Math.E));
            System.out.println(Math.cos(2*Math.PI));
            System.out.println(String.valueOf(2.222333).substring(0));
            System.out.println(String.valueOf(Math.PI).length());
            String winner = "Camerun";
            System.out.println(winner.substring(2).substring(2));
            String loser = "Brazil";
            System.out.println(winner.length() < loser.length());
            System.out.println(winner.endsWith("run"));
            System.out.println(loser.startsWith("Bra"));
            System.out.println(winner.equals(loser));
            
            //Palindromo
            StringBuilder palindromo =
                    new StringBuilder("davalearrozalazorraelabad");
            StringBuilder inversa = palindromo.reverse();
            palindromo.reverse();
            System.out.println(palindromo.equals(inversa));
            
            StringBuilder palindromo2 = new StringBuilder("Mexico");
            System.out.println(palindromo2.reverse());
            System.out.println(palindromo2);
            System.out.println(Math.hypot(3, 4));
            
            
             /* 
            ---------metodos de objetos: palindromo.reverse (); 
            toman la informacion de los elementos Y y el objeto X
            ---------metodo de clase math.hypot(3,4)
            toman la informacion de los argumentos. 
            todos los metodods de clase math son de clase.
            */
    }
}