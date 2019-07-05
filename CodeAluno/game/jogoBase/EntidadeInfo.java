package game.jogoBase;

import game.comuns.StatsInfo;
import game.resistencias.Resistencia;
import game.personagens.Entidade;

/** Define os métodos para uma classe que contém informações sobre o status de cada entidade.
 *   
 */
class EntidadeInfo implements StatsInfo {
     private Entidade e;
     
     public EntidadeInfo(Entidade e){this.e = e;}
     public String getName(){return e.getNome();}
     public int getMP(){return e.getMP();}
     public int getHP(){return e.getHPMax();}
     public int getAtk(){return e.getAtk();}
     public int getEsq(){return e.getEsq();}
     public Resistencia[] res(){return e.resitencias();}
     public int id(){return e.getID();}
     public String statsStr(){  return e.statString(); }
}
