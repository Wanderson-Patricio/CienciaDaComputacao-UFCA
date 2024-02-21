package main;
import Estruturas.*;

public class Main {
	public static void main(String[] args) {
		int order = 5;
		BTree T = new BTree(order);
		
		for(int i = 1; i<=20; i++){
			T.insert(i);
		}
		T.delete(20);
		T.delete(31);
		
		
		T.print();
	}
}
