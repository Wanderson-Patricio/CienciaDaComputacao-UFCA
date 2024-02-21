package Estruturas;

public class Node{
	private int order; //order of the node
	private int n; //number of keys currently in the node
	private int[] keys; //keys in the node
	private boolean isLeaf; //says is is a Leaf or not
	private Node[] childrens; //pointers to childrens
	
	public Node(int order, boolean isLeaf){
		this.order = order;
		this.n = 0;
		this.keys = new int[2*order];
		this.childrens = new Node[2*order + 1];
		this.isLeaf = isLeaf;
	}

	public int getOrder() {
		return order;
	}

	public void setOrder(int order) {
		this.order = order;
	}

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}

	public int[] getKeys() {
		return keys;
	}

	public void setKeys(int[] keys) {
		this.keys = keys;
	}

	public boolean isLeaf() {
		return isLeaf;
	}

	public void setLeaf(boolean isLeaf) {
		this.isLeaf = isLeaf;
	}

	public Node[] getChildrens() {
		return childrens;
	}

	public void setChildrens(Node[] childrens) {
		this.childrens = childrens;
	}
	
	public boolean isFull(){
		return this.n == 2*this.order;
	}
	
	public boolean isEmpty(){
		return this.n==0;
	}
	
	public void print(){
		System.out.println("Keys:");
		for(int i = 0; i<this.n - 1; i++){
			System.out.print(this.keys[i] + " - ");
		}
		if(this.n >= 1){
			System.out.println(this.keys[n-1] + "  (" + this.getN() + " chaves)");
		}
		if(! this.isLeaf){
			System.out.println("Childrens"
					+ ":");
			for(int i=0; i<this.n+1; i++){
				this.childrens[i].print();
			}
		}
	}
	
	// Implementation for the functions
	
	public int[] search(int x){
		int i = 0;
		while(i < this.n && x > this.keys[i]){
			i++;
		}
		
		if(i < this.n && x == this.keys[i]){
			return this.keys;
		}else if(this.isLeaf){
			return null;
		}else{
			return this.childrens[i].search(x);
		}
		
	}
	
	public void splitChild(int i){
		Node y = this.childrens[i];
		Node z = new Node(this.order, true);
		z.isLeaf = y.isLeaf;
		z.n = this.order-1;
		
		for(int j = 1; j < this.order; j++){
			z.keys[j-1] = y.keys[j+this.order];
		}
		
		if(! y.isLeaf){
			for(int j = 0; j<= this.order; j++){
				z.childrens[j] = y.childrens[j + this.order];
			}
		}
		
		y.n = this.order;
		
		for(int j = this.n; j>=i+1; j--){
			this.childrens[j+1] = this.childrens[j];
		}
		
		this.childrens[i+1] = z;
		
		for(int j = this.n -1; j>=i; j--){
			this.keys[j+1] = this.keys[j];
		}
		
		this.keys[i] = y.keys[this.order];
		this.n++;
		
	}
	
	public void insertNonFull(int x){
		int i = this.n -1;
		if(this.isLeaf){
			
			while(i >= 0 && x<this.keys[i]){
				this.keys[i+1] = this.keys[i];
				i--;
			}
			
			this.keys[i+1] = x;
			this.n++;
		}else{
			
			while(i >= 0 && x<this.keys[i]){
				i--;
			}
			i++;
			if(this.childrens[i].isFull()){
				this.splitChild(i);
				
				if(x > this.keys[i]){
					i++;
				}
			}
			
			this.childrens[i].insertNonFull(x);
		}
	}
	
}