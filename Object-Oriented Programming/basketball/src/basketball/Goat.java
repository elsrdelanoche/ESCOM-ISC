package basketball;

public class Goat extends Player {  //Poedmoas traducir extends como ES_Un o IS_A
    private double millions;
    public void view_millions(){
        System.out.println("millions = " + millions);
    }
    public void make_TV_ad(double millions){
        this.millions += millions;
    }
}
