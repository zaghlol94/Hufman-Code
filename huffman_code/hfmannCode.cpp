#include "MinPriorityQueue.cpp"
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
 
using namespace std;
class Node {
public:
    char name;
    int f;
    Node *left, *right;
    string code;

    Node() {
        name = ' ';
        code = "";
        f = INT_MAX;
        left = right = 0;
    }

    Node(int ff, char n ) {
        name = n;
        f = ff;
        left = right = 0;
        code = "";
    }

    ~Node() {
        delete left;
        delete right;
    }

    bool operator<(Node &param) {
        return f < param.f;
    }

    bool operator>(Node &param) {
        return f > param.f;
    }

    bool operator==(Node &param) {
        return f == param.f;
    }

    static void display(Node*, bool);
    static void encode(Node*);

    friend ostream& operator <<(ostream&, Node&);
};
vector<Node>n;
void Node::display(Node* node, bool leavesOnly = 1) {
    if (node == 0) {
        return;
    }
    display(node->left, leavesOnly);
    if (leavesOnly) {
        if (node->left == 0 && node->right == 0)
		{
            cout << *node << ", ";
			n.push_back(*node);
        }
    } else {
        cout << *node << ", ";
		n.push_back(*node);
    }
    display(node->right, leavesOnly);
}
void Node::encode(Node* node) {
    if (node == 0) {
        return;
    }
    if (node->left != 0) {
        node->left->code = node->code + "0";
    }
    if (node->right != 0) {
        node->right->code = node->code + "1";
    }
    encode(node->left);
    encode(node->right);
}
ostream& operator <<(ostream &out, Node &node) {
    out << node.name << "(" << node.f << ")" << ":" << node.code;
    return out;
}
void HuffmanCode(vector<int>freqs, vector<char> names, int length) {
    Q<Node> *q = new Q<Node > (length);
    for (int i = 0; i < length; i++) {
        q->insert(new Node(freqs[i], names[i]));
    }

    for (int i = 0; i < length - 1; i++) {
        Node *x = q->extractMin();
        Node *y = q->extractMin();
        Node *z = new Node(x->f + y->f, x->name + y->name);
        z->left = x;
        z->right = y;
        q->insert(z);
    }
    Node *root = q->extractMin();

    cout << "Huffman Code:\n";
    Node::encode(root);
    Node::display(root);
}

int main() {
vector<int>freqs;
vector<char>names;
ifstream f;
ofstream o;
f.open("inputfile.txt");
   char c[1000],ch;
   int i,count;
   cout << "the file is read\n";
   
  f.getline(c, 1000);
   for(int n=0;c[n]!='\0';n++)
   {
	   bool found=false;
	   for(int l=0;l<names.size();l++)
	   {
		   
		   if(c[n]==names[l])
			   found=true;
	   }
	   if(found)
		   continue;
	   count=0;
	   ch=c[n];
	     for(i=0;c[i]!='\0';++i)
   {
       if(ch==c[i])
           ++count;
   }
		 names.push_back(ch);
		 freqs.push_back(count);
   }
   o.open("decoded_file.txt");
 
   HuffmanCode(freqs, names, freqs.size());
   cout<<"\nthe string encoded is  ";
   for(int i=0;i<strlen(c);i++)
   {
	   for(int j=0;j<n.size();j++)
	   
	   {
		   if(c[i]==n[j].name)
			   {
				   cout<<n[j].code;
				   o<<n[j].code;
				  
		       }
	   
	   }
   
   
   
   }
   cout<<"\nthe file decoded saved also";
    
	system("pause");
	

	
}