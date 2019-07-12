package game Personagem;
import game.acoes.acoesBatalha.GolpeGelo;
import game.Identificavel;
import game.comuns.StatusControle;
import game.comuns.Resistencia;
import game.comuns.ResistenciaGelo;



public abstract class MagoGelo extends Personagem{
   
    public MagoGelo(String nome, StatusControle e){
        super(e, nome, new int[][] {{400, 220, 10} {1200, 250, 60} {115, 220, 0} {120, 230, 0}}, new Resistencia[] {new ResistenciaGelo(300, 250)});
    }

    public abstract GolpeGelo agir (Identificavel p[]);

    
}