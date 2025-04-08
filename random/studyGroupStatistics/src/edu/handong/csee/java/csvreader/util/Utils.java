package edu.handong.csee.java.csvreader.util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Utils {
    public static ArrayList<String> readTextFile(String path){
        ArrayList<String> lines = new ArrayList<String>();
        String line = "";

        try (BufferedReader br = new BufferedReader(new FileReader(path))){
            while ((line = br.readLine())!= null){
                lines.add(line);
            }
        }catch (IOException e){
            e.printStackTrace();
        }

        return lines;
    }
}
