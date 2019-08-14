package game.acoes.acoesBatalha;

import game.personagens.Entidade;

game.danos.Dano;

public class GolpeMachadada extends AcaoMagica{

    public GolpeMachadada(Entidade agente, int IDAlvo){
        super(agente, IDAlvo, 100));
    }    
}