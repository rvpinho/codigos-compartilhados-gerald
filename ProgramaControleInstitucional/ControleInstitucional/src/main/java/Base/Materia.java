/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Base;

/**
 *
 * @author Rafael
 */
public class Materia {
    
    private String ID;

    public Materia(String ID, String disciplina, int professor) {
        this.ID = ID;
        this.disciplina = disciplina;
        this.professor = professor;
    }
    private String disciplina;
    private int professor;

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getDisciplina() {
        return disciplina;
    }

    public void setDisciplina(String disciplina) {
        this.disciplina = disciplina;
    }

    public int getProfessor() {
        return professor;
    }

    public void setProfessor(int professor) {
        this.professor = professor;
    }
}
