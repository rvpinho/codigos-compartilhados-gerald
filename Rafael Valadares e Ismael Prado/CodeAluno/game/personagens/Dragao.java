package game.personagens;
import game.resistencias.Resistencia;
import game.resistencias.ResistenciaFisico;

public class Dragao extends Monster{

    super (1000, "Dragao", new int [][]{{7000, 500, 300} {1500, 500, 1000} {1, 2000, 0}}, new Resistencia[] {new ResistenciaFogo(400, 450), new ResistenciaFisico(250, 450)})
}