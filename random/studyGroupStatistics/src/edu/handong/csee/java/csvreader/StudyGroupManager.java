package edu.handong.csee.java.csvreader;

import java.util.ArrayList;

import edu.handong.csee.java.csvreader.data.Student;
import edu.handong.csee.java.csvreader.util.Utils;

public class StudyGroupManager {
    public static void main(String[] args) {
        StudyGroupManager myManager = new StudyGroupManager();
        myManager.run(args);
    }

    public void run(String[] args){
        String path = args[0];

        ArrayList<String> lines = Utils.readTextFile(path);
        ArrayList<Student> students = new ArrayList<Student>();

        for (int i = 1; i < lines.size(); i++){
            String line = lines.get(i);
            if (!line.equals("")){
                String[] values = line.split(",");
                Student student = new Student(values[2]);
                //Student student  = new Student(values[0], values[1], values[2], values[3], values[4], values[5], values[7]);
                students.add(student);
            }
        }

        for(Student student:students){
            System.out.println(student.getName());
        }
    }
}