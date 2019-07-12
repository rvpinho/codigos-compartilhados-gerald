package game Personagem;
import game.acoes.acoesBatalha.GolpeFogo;
import game.Identificavel;
import game.comuns.StatusControle;
import game.comuns.Resistencia;
import game.comuns.ResistenciaFogo;



public abstract class MagoFogo extends Personagem{
   
    public MagoFogo(String nome, StatusControle e){
        super(e, nome, new int[][] {{400, 220, 10} {1500, 250, 80} {150, 210, 0} {180, 250, 0}}, new Resistencia[] {new ResistenciaGelo(200, 450)});
    }

    public abstract GolpeFogo agir (Identificavel p[]);

    
}