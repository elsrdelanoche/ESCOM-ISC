/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.alfredobr.fundamentos;

/**
 *
 * @author Alfredo
 */
public class cadenas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String calificado = "mexico";
        String eliminado = "polonia";
        
        System.out.println("calificado= "+calificado);
        System.out.println("eliminado= "+eliminado);
        System.out.println(calificado.toUpperCase());
        System.out.println(eliminado.replace('o','@'));
        System.out.println(calificado.toLowerCase());
        System.out.println(eliminado.charAt(2));
        System.out.println(calificado.length());
        System.out.println(eliminado.indexOf('n'));
        System.out.println(calificado.concat(eliminado));
        System.out.println(calificado.equals(eliminado));
        System.out.println(calificado.compareTo(calificado));
        
        StringBuffer mex_player = new StringBuffer("Chucky");
        StringBuffer pol_player = new StringBuffer("Lewandosky");
        
        System.out.println(mex_player.append(" Lozano"));
        System.out.println(pol_player.append(9));
        //Comentario de una linea
        /*Comentario de varias lineas*/
        System.out.println(mex_player.delete(2, 6));
        System.out.println(pol_player.deleteCharAt(0));
        System.out.println(mex_player.reverse());
        
        StringBuffer arg_player = new StringBuffer("messi");
        System.out.println(arg_player.reverse().deleteCharAt(0));
        System.out.println(arg_player.insert(0, 'i'));
        System.out.println(arg_player.reverse());
        StringBuilder worldcup = new StringBuilder("Qatar 2022");
        System.out.println(worldcup.append(9.5));
        System.out.println(worldcup.append(Math.PI));
        System.out.println(worldcup.replace(3,5,"do"));
        System.out.println(worldcup.toString().replace(" ",""));
    }
    
}