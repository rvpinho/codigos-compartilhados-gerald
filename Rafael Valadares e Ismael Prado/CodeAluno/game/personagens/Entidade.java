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
abstract public class Entidade {

         private String nome;
         private int id;
         private int attr[][];
         private static int last;
         private Resistencia r[];
         private Celula c;
         private int hp_ant;
         private int mp_ant;

         /**Constrói um Personagem com um dado nome, experiência e seus respectivos atributos.
          * @param exp: A experiência do personagem.
          * @param attrVal: A matriz de inteiros de 4x3, contendo em cada linha os valores das constantes
                            C,T e I, respectivamente, do atributo. As linhas contém : 0:HP , 1:MP, 2 Atk e 3 Esq,
          * @param nome: O nome do personagem.
          */
         public Entidade(String nome, int[][] attrVal, Resistencia[] rs){
              this.nome = nome;
              id = last;
              last++;
              attr = new int[4][3];
              for(int i = 0; i< Math.min(attrVal.length,4); i++){
                  for(int j = 0; j< Math.min(attrVal[i].length,3); j++){
                      attr[i][j] = attrVal[i][j];
                  }
              }
              attr[3][0] = Math.min(attr[3][0],1000);
              r = rs.clone();
         }

        /** Constrói um personagem com umada experiência. O
         *   personamge terá o nome padrão de "Jão Ninguém" seguido
         *   de um número.
         *   @param exp: A experência do pesonagem.
         */
         public Entidade(int attrVal[][],  Resistencia[] rs){
              this("João Ninguém "+last, attrVal, rs);
         }
         
         /** Atualiza a posição do personagem. Esse método é chamado pela Máquina de jogo para informar ao presonagem sua posiçao. 
           *  @param c: A posição atual do personagem.
           */
         public final void updatePos(Celula c){ this.c = c;}
         public final Celula getPos(){return c;}



         /** Determina o valor de atributo com base na experiência do personagem.
          *  @param a: Referência do atributo.
          *  @return O valor do atributo para este personagem.
          */
         private final int attrValor(int a){
             return Math.round(attr[a][2] +  attr[a][0]*(1 - (float)Math.exp(- ((double)getExp() / attr[a][1]))) );
         }


         /** Retorna o nome do personagem.
          *  @return O nome do personagem.
          */
         public final String getNome(){ return nome;}

         /** Retorna o ID do personagem.
          *  @return O ID do personagem que é um valor inteiro único para
          *          cada personagem.
          */
         public final int getID(){ return id;}

         /** Retorna o valor do HP máximo do personagem.
          *  @return O valor do Hp do personagem.
          */
         public final int getHPMax(){ return attrValor(0);}
         

         /** Retorna o valor do MP máximo do personagem.
          *  @return O valor do Mp do personagem.
          */
         public final int getMPMax(){return attrValor(1);}
         

         
         
         /** Retorna o valor do ataque do personagem.
          *  @return O valor do ataque do personagem.
          */
         public final int getAtk(){ return attrValor(2); }

         /** Retorna o valor da esquiva do personagem.
          *  @return O valor do esquiva do personagem.
          */
         public final int getEsq(){ return attrValor(3); }

         /** Retorna o valor do atributo de resistências deste personagem
          *  @return O vetor de resistências deste personagem.
          */
          public final Resistencia[] resitencias(){
               return r.clone();
          }
         
               
         /** Usa o MP deste personagem. Desconta o valor solicitado do MP desta entidade. 
           *  Retorna true se o valor puder se descontado do MP e false caso contrário. 
           * @param m: O valor de MP a ser descontado.
           * @return True se o valor puder descontado do MP desta entidade , false caso contrário
           */
         public abstract boolean useMP(int m);
         
         public abstract int getHP();
         
         public abstract int getMP();
         
                  
         public abstract void danificar(int d);

         /** Retorna a experiência corrente do personagem.
          *  @return Experiência do personagem.
          */
         public abstract int getExp();
         public abstract AcaoMover mover();
         public abstract AcaoBatalha agir(Identificavel p[]);
         
         /** Retorna um carácter que representa a classe deste personagem.
           * Duas classes nunca devem retornar o mesmo valor.
           */
         public abstract char classeDesc();
        
        /** Retorna a um vetor de carácters que identifica a classe de uma entidade específica.
          * Esses dados são utilizados para propósitos de identificação.
          *
          */
        public abstract char[] subDesc();
        
        /** Determina se essa entidade está morta. 
         *   @return true se a entidade está morta ou false caso contrário.
         */
         public final boolean morto(){return getHP() <= 0;}
         
         /**Retorna uma representação do estatus deste personagem em String.
           *
           */
         public String statString(){
             String s = nome + "{ hp:" + getHP() + ", mp: " + getMP() + ", exp: " + getExp() + ", atk: " + getAtk() + ", esq: " + getEsq();
             for(Resistencia rs : r){
                 s += " ," + rs.toString();
             }
             s += "}";
             return s;
         }
}
