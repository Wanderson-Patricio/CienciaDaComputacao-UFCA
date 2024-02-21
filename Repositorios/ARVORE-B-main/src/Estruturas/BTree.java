package Estruturas;

public class BTree{
	private int order;
	private Node root;
	
	public BTree(int order){
		this.order = order;
		this.root = new Node(order, true);
	}

	public int getOrder() {
		return order;
	}

	public void setOrder(int order) {
		this.order = order;
	}

	public Node getRoot() {
		return root;
	}

	public void setRoot(Node root) {
		this.root = root;
	}
	
	public void print(){
		System.out.println("Arvore de ordem " + this.order);
		this.root.print();
	}
	
	public int[] search(int x){
		return this.root.search(x);
	}
	
	private Node splitRoot(){
		Node s = new Node(this.order, false);
		s.getChildrens()[0] = this.root;
		this.root = s;
		s.splitChild(0);
		return s;
	}
	
	public void insert(int x){
		Node r = this.root;
		if(r.search() != null) return;
		
		if(r.isFull()){
			Node s = this.splitRoot();
			s.insertNonFull(x);
		}else{
			r.insertNonFull(x);
		}
	}
	
	public void delete(int key) {
        if (root == null) {
            System.out.println("The B-tree is empty.");
            return;
        }

        // Perform the delete operation
        boolean keyDeleted = delete(root, key);

        // If the root node becomes empty after the delete operation, update the root
        if (root.isEmpty()) {
            Node newRoot = root.isLeaf() ? null : root.getChildrens()[0];
            root = newRoot;
        }

        // If the key was not found in the tree, print a message
        if (!keyDeleted) {
            System.out.println("Key not found in the B-tree.");
        }
    }
	
	private int findPredecessor(Node node, int index) {
        // Find the rightmost key in the subtree rooted at node.getChildrens()[index]
        Node current = node.getChildrens()[index];
        while (!current.isLeaf()) {
            current = current.getChildrens()[current.getN()];
        }
        return current.getKeys()[current.getN() - 1];
    }
	
	
	private boolean delete(Node node, int key) {
        // Find the index of the first key greater than or equal to the given key
        int index = 0;
        while (index < node.getN() && key > node.getKeys()[index]) {
            index++;
        }

        // If the key is found at this node
        if (index < node.getN() && key == node.getKeys()[index]) {
            if (node.isLeaf()) {
                // Case 1: The key is in a leaf node; delete it directly
                for (int i = index; i < node.getN() - 1; i++) {
                    node.getKeys()[i] = node.getKeys()[i + 1];
                }
                node.setN(node.getN() - 1);
                return true;
            } else {
                // Case 2: The key is in an internal node
                int keyToReplace = findPredecessor(node, index);
                node.getKeys()[index] = keyToReplace;
                return delete(node.getChildrens()[index], keyToReplace);
            }
        } else {
            // The key is not found at this node; continue searching
            if (node.isLeaf()) {
                // The key is not in the tree
                return false;
            } else {
                // Recursively search for the key in the appropriate child
                boolean keyDeleted = delete(node.getChildrens()[index], key);

                // Check if the child node is deficient and fix it if necessary
                if (node.getChildrens()[index].getN() < this.order) {
                    handleDeficientChild(node, index);
                }

                return keyDeleted;
            }
        }
    }
	
	private void handleDeficientChild(Node parent, int childIndex) {
        if (childIndex > 0 && parent.getChildrens()[childIndex - 1].getN() > this.order) {
            // Case 3a: Borrow a key from the left sibling
            borrowFromLeftSibling(parent, childIndex);
        } else if (childIndex < parent.getN() && parent.getChildrens()[childIndex + 1].getN() > this.order) {
            // Case 3b: Borrow a key from the right sibling
            borrowFromRightSibling(parent, childIndex);
        } else {
            // Case 3c: Merge the child with a sibling
            mergeWithSibling(parent, childIndex);
        }
    }
	
	private void borrowFromLeftSibling(Node parent, int childIndex){
		Node child = parent.getChildrens()[childIndex];
		Node sibling = parent.getChildrens()[childIndex - 1];
		
		child.insertNonFull(parent.getKeys()[childIndex - 1]);
		parent.getKeys()[childIndex - 1] = sibling.getKeys()[sibling.getN() - 1];
		sibling.setN(sibling.getN() - 1);
	}
	
	private void borrowFromRightSibling(Node parent, int childIndex){
		Node child = parent.getChildrens()[childIndex];
		Node sibling = parent.getChildrens()[childIndex+1];
		
		child.insertNonFull(parent.getKeys()[childIndex]);
		parent.getKeys()[childIndex] = sibling.getKeys()[0];

		for(int i=0; i<sibling.getN() - 1; i++){
			sibling.getKeys()[i] = sibling.getKeys()[i+1];
		}
		sibling.setN(sibling.getN()-1);
	}
	
	private void mergeWithSibling(Node parent, int childIndex) {
	    Node child = parent.getChildrens()[childIndex];

	    if (childIndex == 0) {
	        // Merge with the right sibling
	        Node rightSibling = parent.getChildrens()[1];

	        // Move the parent's key that separates the child and the right sibling to the child
	        child.getKeys()[child.getN()] = parent.getKeys()[0];
	        child.setN(child.getN() + 1);

	        // Copy keys from the right sibling to the child
	        for (int i = 0; i < rightSibling.getN()-1; i++) {
	            child.getKeys()[child.getN()] = rightSibling.getKeys()[i];
	            child.setN(child.getN() + 1);
	        }
	        
	        
	        parent.getKeys()[0] = rightSibling.getKeys()[rightSibling.getN() - 1];

	        // Shift child pointers in the parent to fill the gap
	        for (int i = 1; i < parent.getN(); i++) {
	            parent.getKeys()[i] = parent.getKeys()[i + 1];
	            parent.getChildrens()[i] = parent.getChildrens()[i + 1];
	        }
	        //parent.getChildrens()[parent.getN()-1] = parent.getChildrens()[parent.getN()];
	        
	        
	        parent.setN(parent.getN() - 1);
	        
	    } else {
	        // Merge with the left sibling
	        Node leftSibling = parent.getChildrens()[childIndex - 1];

	        // Move the parent's key that separates the left sibling and the child to the left sibling
	        leftSibling.getKeys()[leftSibling.getN()] = parent.getKeys()[childIndex - 1];
	        leftSibling.setN(leftSibling.getN() + 1);

	        // Copy keys from the child to the left sibling
	        for (int i = 0; i < child.getN(); i++) {
	            leftSibling.getKeys()[leftSibling.getN()] = child.getKeys()[i];
	            leftSibling.setN(leftSibling.getN() + 1);
	        }
	        
	        parent.getKeys()[childIndex - 1] = child.getKeys()[child.getN()-1];

	        // Shift child pointers in the parent to fill the gap
	        for (int i = childIndex - 1; i < parent.getN() - 1; i++) {
	            parent.getKeys()[i] = parent.getKeys()[i + 1];
	            parent.getChildrens()[i + 1] = parent.getChildrens()[i + 2];
	        }

	        parent.setN(parent.getN() - 1);
	    }
	}


}
