package com.alfredobr.fundamentos;

public class ObjetosyClases {
    public static void main(String[] args){
        StringBuilder team = new StringBuilder("Costa Rica");
        team.append(" de Concacaf");
        team.append(Math.PI).append(64);
        System.out.println(team);
        
        StringBuffer arbitra = new StringBuffer("Karen Diaz");
        System.out.println(arbitra.charAt(9));
        System.out.println(arbitra.charAt(0));
        
        System.out.println(arbitra.insert(6, "Medina").insert(0, "Fernanda"));
        
        String player = new String("Miguel Romero");
        System.out.println(player.length());
        System.out.println(player.trim());
        System.out.println(player.trim().length());
        
        System.out.println(team.delete(0, 5));
        
        System.out.println(player.replace("i","I").replace("R", "@"));
               
    }
}
