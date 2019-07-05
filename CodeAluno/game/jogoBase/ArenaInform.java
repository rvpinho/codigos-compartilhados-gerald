package game.jogoBase;

import game.comuns.StatsInfo;
import game.comuns.ArenaInfo;
import game.resistencias.Resistencia;
import game.personagens.Entidade;

/** Define os métodos para uma classe que contém informações sobre o status de cada entidade.
 *   
 */
class ArenaInform implements ArenaInfo {
     private Arena a;
     public ArenaInform(Arena a){this.a = a;}
     public int getCellID(){return a.getCell().getUID();}
     public StatsInfo[] getEntidades(){ return a.lutadores();}

}
