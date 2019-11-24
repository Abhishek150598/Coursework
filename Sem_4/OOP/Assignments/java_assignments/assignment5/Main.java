package asg_5;

import java.io.*;
import java.util.*;

class Index{
    HashMap<String, ArrayList<Integer>> occurences;
    TreeMap<String, ArrayList<Integer>> occurencesNew;
    Index( Readable text){
        Scanner input = new Scanner(text);
        occurences = new HashMap<String, ArrayList<Integer>>();
        int lineNumber = 1;
        try{
            while(input.hasNextLine()){
                String line = input.nextLine();
                line = line.replaceAll("[\\W]"," ");
                String[] str =  line.split("\\s");
                for( String word : str){
                    word = word.toLowerCase();
                    ArrayList<Integer> list = occurences.get(word);
                    if(list == null){
                        list = new ArrayList<>();
                        list.add(lineNumber);
                    }
                    else
                        list.add(lineNumber);

                    occurences.put(word,list);
                }
                lineNumber++;
            }
        } finally{
            input.close();
        }

    }
    public String toString()
    {
        occurencesNew = new TreeMap<>();
        occurencesNew.putAll(occurences);
        return occurencesNew.toString();
    }

}

public class Main{
    public static void main(String[] args) {
        try {

            File file = new File("G:\\JAVA PROGRAMS\\OOP\\src\\asg_5\\Main.txt");
            BufferedReader br = new BufferedReader(new FileReader(file));
            String indexString = new Index(br).toString();
            System.out.println(indexString);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}