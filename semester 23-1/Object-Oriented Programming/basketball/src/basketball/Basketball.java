package basketball;
class Basketball {
    public static void main(String[] args) {
        // crtl + e     borrar linea
        Player p = new Player();
        short num = 32767;
        byte num2=127;
        p.makes_Doubles();
        for (int i = 0; i < 41; i++) {
            p.makes_Triples();
        }
        p.makes_Foul();
        p.set_shortAndJersey("blue", "blue");
        p.view_stats();
    }
    Goat g = new Goat();
        g.makes_Doubles();
        g.view_stats();
        g.view_stats();
        g.make_TV_ad(200000);
        g.view_millions();
        g.view_stats();
}
