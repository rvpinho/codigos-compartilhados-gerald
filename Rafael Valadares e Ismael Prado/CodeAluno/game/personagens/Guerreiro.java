package game Personagem;
import game.acoes.acoesBatalha.AcaoMagica;;
import game.Identificavel;
import game.comuns.StatusControle;
import game.comuns.Resistencia;
import game.comuns.Resistencia.*;



public abstract class Guerreiro extends Personagem{
   
    public Guerreiro(String nome, StatusControle e){
        super(e, nome, new int[][] {{800, 250, 20} {15, 250, 5} {220, 250, 0} {80, 250, 0}}, new Resistencia[] {new ResistenciaGelo(300, 400)});
    }


    
}