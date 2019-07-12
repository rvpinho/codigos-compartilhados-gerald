package game.personagens;

import game.comuns.StatusControle;
import game.comuns.Identificavel;
import game.danos.Dano;
import game.danos.DanoFogo;
import game.danos.DanoGelo;
import game.danos.DanoFisico;
import game.acoes.AcaoMover;
import game.acoes.acoesBatalha.AcaoBatalha;
import game.resistencias.*;
import game.celulas.Celula;

/** Modelas as características básicas de um personagem.
 *  @author Elton M. Cardoso
 *  @date 10/06/2019
 */
abstract public class Monster extends Entidade {
          private class FakeEC implements StatusControle {
                     private int e, hp, mp;
                     public FakeEC(int e,int hp, int mp){ 
                    	 this.e=e;
                    	 this.hp= hp;
                    	 this.mp = mp;
                     }
                     public int getExp(){ return e;}
					 public int getHP() {return hp;}
					 public int getMP() {return mp;}
					 public boolean useMP(int m){ 
			             boolean b = m <=  mp;
			             if(b){mp -= m;  }
			             return b;
			        }
			         public void danificar(int d) { hp-=d;}
          }
          private int exp;
          private StatusControle e;
          /**Constrói um Personagem com um dado nome, experiência e seus respectivos atributos.
          * @param experience: A experiência do personagem.
          * @param attrVal: A matriz de inteiros de 7x3, contendo em cada linha os valores das constantes
                            C,T e I do atributo. As linhas contém : 0:HP , 1:MP, 2 Atk, 3 Esq,
                            4 R. Fogo, 5 R. Gelo, 6 R. Física.
          * @param nome: O nome do personagem.
          */

        public Monster(int experience, String nome, int[][] attrVal, Resistencia[] rs){
             super(nome, attrVal, rs );
             exp = experience;
             e = new FakeEC(exp,getHPMax(), getMPMax());
             for(Resistencia re : resitencias()){
                  re.setExpControle(e);
              }
             
        }
        public void danificar(int d) {e.danificar(d);}
        public final int getHP(){return e.getHP();}
        public final int getMP(){return e.getMP();}
        public final boolean useMP(int m){return e.useMP(m);}
        public final int getExp(){return exp;}
        public final StatusControle getExpControle(){return e;}
        public final char classeDesc(){return 'M';}
}
