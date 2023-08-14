package basketball;
public class Player {
    private byte points;
    private byte triples;
    private byte doubles;
    private byte fouls;
    private String short_color;
    private String jersey_color;
    private boolean bench;  //true or false
    public Player() {
    }
    public Player(byte points, byte triples, byte doubles, byte fouls, String short_color, String jersey_color, boolean bench) {
        this.points = points;
        this.triples = triples;
        this.doubles = doubles;
        this.fouls = fouls;
        this.short_color = short_color;
        this.jersey_color = jersey_color;
        this.bench = bench;
    }
    public byte getDoubles() {
        return doubles;
    }
    public byte getFouls() {
        return fouls;
    }
    public String getJersey_color() {
        return jersey_color;
    }
    public byte getPoints() {
        return points;
    }
    public String getShort_color() {
        return short_color;
    }
    public byte getTriples() {
        return triples;
    }
    public boolean get_bench() {
        return bench;
    }
    public void makes_Triples() {
        triples++;
        points+=3;
    }
    public void makes_Doubles() {
        doubles++;
        points+=2;
    }
    public void makes_Foul(){
        if(bench==false && fouls<5){
            fouls++;
        }
        
        if(fouls == 5){
            bench = true;
        }
    }
    public void set_shortAndJersey(String shortColor, String jerseyColor){
        this.short_color = shortColor;
        this.jersey_color = jerseyColor;
    }
    public void to_play(){
        bench = false;
    }
    public void to_bench(){
        bench = true;
    }
    public void view_stats(){
        System.out.println("points = " + points);
        System.out.println("doubles = " + doubles);
        System.out.println("triples = " + triples);
        System.out.println("fouls = " + fouls);
    }
}
