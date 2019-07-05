package game.celulas;

import game.personagens.Personagem;
import game.personagens.Monster;

public interface Celula {

         public boolean testeBatalha();
         public boolean emBatalha();
         public boolean mvAcima();
         public boolean mvAbaixo();
         public boolean mvEsquerda();
         public boolean mvDireita();
         public int getUID();
         
         public Monster[] habitantes();
         
}
