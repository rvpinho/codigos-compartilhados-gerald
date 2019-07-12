package game.jogoBase;
import game.comuns.StatusControle;

class Experi implements StatusControle{

    private int Exp;
    private int HP;
    private int MP;
    private int m;
    private int d;

    public Experi(){

    }


    public int getExp(){return Exp;}
    public int GetHP(){return HP;}
    public int GetMP(){return MP;}
    public boolean useMP(int m){

        if (this.MP) - m >= 0{
            this.MP -= m;
            return true;
        }
        return false;
    }

    public void danificar(int d){

    }

    public void setExp(Exp){
        this.Exp +=Exp;
    }

}