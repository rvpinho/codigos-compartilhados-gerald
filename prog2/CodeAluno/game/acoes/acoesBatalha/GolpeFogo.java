package game.acoes.acoesBatalha;

import game.personagens.Entidade;

game.danos.Dano;

public class GolpeFogo extends AcaoMagica{

    public GolpeFogo(Entidade agente, int IDAlvo){
        super(agente, IDAlvo, 150, 5));
    }
}