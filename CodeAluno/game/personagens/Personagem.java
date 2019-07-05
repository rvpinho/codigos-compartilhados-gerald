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
abstract public class Personagem extends Entidade {

         private StatusControle exp;
         private int exp_ant;

         /**Constrói um Personagem com um dado nome, experiência e seus respectivos atributos.
          * @param exp: A experiência do personagem.
          * @param attrVal: A matriz de inteiros de 7x3, contendo em cada linha os valores das constantes
                            C,T e I do atributo. As linhas contém : 0:HP , 1:MP, 2 Atk, 3 Esq,
                            4 R. Fogo, 5 R. Gelo, 6 R. Física.
          * @param nome: O nome do personagem.
          */
         public Personagem(StatusControle exp, String nome, int[][] attrVal, Resistencia[] rs){
              super(nome, attrVal, rs);
              this.exp = exp;
              for(Resistencia re : resitencias()){
                  re.setExpControle(exp);
              }
         }

         /** Constrói um personagem com umada experiência. O
             personamge terá o nome padrão de "Jão Ninguém" seguido
             de um número.
          *  @param exp: A experência do pesonagem.
          */
         public Personagem(StatusControle exp,  int attrVal[][],  Resistencia[] rs){
              super(attrVal, rs);
              this.exp = exp;
         }

         /** Retorna a experiência corrente do personagem.
          *  @return Experiência do personagem.
          */
         public final int getExp(){ return exp.getExp();}
         public final int getHP(){ return exp.getHP();}
         public final int getMP(){ return exp.getMP();}

         /** Executa um teste de segurança no controlador de experiência.
          *  @param ExpControle: Controlador de experiência de referência.
          *  @return True se o controlador de experiência passa pelo teste,
          *          falso caso contrário.
          */
         public final boolean secCheck(StatusControle e){ return true;}

         public final void danificar(int d) {exp.danificar(d);}
         public abstract AcaoMover mover();

         public abstract AcaoBatalha agir(Identificavel p[]);
         public final boolean useMP(int m){return exp.useMP(m);}
         public abstract char classeDesc();
         public abstract char[] subDesc();

}
