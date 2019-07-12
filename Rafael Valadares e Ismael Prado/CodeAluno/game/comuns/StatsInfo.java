package game.comuns;
import game.resistencias.Resistencia;

/** Define os métodos para uma classe que contém informações sobre o status de cada entidade.
 *   
 */
public interface StatsInfo {
     
     public String getName();
     public int getMP();
     public int getHP();
     public int getAtk();
     public int getEsq();
     public Resistencia[] res();
     public int id();
     public String statsStr();
}
