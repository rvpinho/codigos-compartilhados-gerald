package game.acoes.acoesBatalha;

import game.personagens.Entidade;

game.danos.Dano;

public class GolpeGelo extends AcaoMagica{

    public GolpeGelo(Entidade agente, int IDAlvo){
        super(agente, IDAlvo, 150, 5));
    }
}