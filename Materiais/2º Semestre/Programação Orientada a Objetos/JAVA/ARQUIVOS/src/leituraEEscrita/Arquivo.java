package leituraEEscrita;

import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Arquivo {
	public static String read(String directory) {
		
		String content = "";
		
		try {
			
			FileReader archive = new FileReader(directory);
			BufferedReader reader = new BufferedReader(archive);
			
			String line = "";
			
			try {
				
				line = reader.readLine();
				
				while(line != null) {
					
					content += line + "\r\n";
					line = reader.readLine();
					
				}
				
				archive.close();
				
			}catch(IOException e) {
				
				content = "Erro na leitura do arquivo.";
				
			}
			
		}catch(FileNotFoundException e){
			
			content = "Erro na procura do arquivo.";
			
			
		}
		
		return content;
	}
	
	
	
	/********************************************************************/
	/********************************************************************/
	/********************************************************************/
	
	
	
	public static boolean write(String directory, String text){
		try {
			
			FileWriter archive = new FileWriter(directory);
			PrintWriter printer = new PrintWriter(archive);
			
			printer.println(text);
			printer.close();
			
			return true;
			
		}catch(IOException e) {
			
			System.out.println(e.getMessage());
			return false;
			
		}
	}
}
