#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct edge;

struct vertex
{
	string element;
	vector<edge*> AjaEdge;
	bool unexplored;
	long label;
	vertex(string e) {
		element = e;
		unexplored = true;
	}
};
struct edge
{
	long weight;
	vertex *vertex1, *vertex2;
	bool unexplored;
	edge(long w, vertex* v1, vertex* v2) {
		weight = w;
		vertex1 = v1; vertex2 = v2;
		unexplored = true;
	}
};

class Graph
{
private:
	vector<vertex*> listVertex;
	vector<edge*> listEdge;
public:
	Graph() {};
	~Graph() {};
	void input_by_matrix() {
		int numberOfVertex;
		cout << "Enter the number of vertexes: ";
		cin >> numberOfVertex;
		cout << "Enter names of vertexes: ";
		vector<vertex*> list;
		string *name;
		name = new string[numberOfVertex+1];
		for (int i=1; i<=numberOfVertex; i++) {
			cin >> name[i];
			list.push_back(insertVertex(name[i]));
		}
		int **AdjaMatrix;
		cout << "Enter adjacent matrix: " << endl;
		AdjaMatrix = new int*[numberOfVertex];
		for (int i=0; i<numberOfVertex; i++) {
			AdjaMatrix[i] = new int[numberOfVertex];
			for (int j=0; j<numberOfVertex; j++) {
				cin >> AdjaMatrix[i][j];
			}
		}
		int weig;
		for (int i=0; i<numberOfVertex; i++) {
			for (int j=0; j<numberOfVertex; j++) {
				if (j>i) {
					if (AdjaMatrix[i][j]==1) {
						cout << "Enter the weight of edge (" 
						<< list[i]->element << "," << list[j]->element << "): ";
						cin >> weig;
						insertEdge(weig,list[i],list[j]);
					}
				}
			}
		}
	}
	vertex* findVertex(string c) {
		vertex* v = NULL;
		for (unsigned i=0; i<listVertex.size(); i++) {
			if (listVertex[i]->element==c) v = listVertex[i];
		}
		return v;
	}
	edge* findEdge(string s1, string s2) {
		vertex* v1 = findVertex(s1), *v2 = findVertex(s2);
		edge* e = NULL;
		for (unsigned i=0; i<listEdge.size(); i++) {
			if ((listEdge[i]->vertex1==v1 && listEdge[i]->vertex2==v2) || 
				(listEdge[i]->vertex2==v1 && listEdge[i]->vertex1==v2)) {
				e = listEdge[i];
			}
		}
		return e;
	}
	vertex* opposite(vertex* v, edge* e) {
		if (v==NULL || e==NULL) return NULL;
		if (e->vertex1==v) return e->vertex2;
		else {
			if (e->vertex2==v) return e->vertex1;
			else return NULL;
		}
	}
	bool areAdjacent(vertex* v1, vertex* v2) {
		for (unsigned i=0; i<v1->AjaEdge.size(); i++) {
			if (opposite(v1,v1->AjaEdge[i])==v2) return true;
		}
		return false;
	}
	void replace(long wei, string v, string w) {
		vertex* v1 = findVertex(v), *v2 = findVertex(w);
		if (v1==NULL || v2==NULL) return;
		for (unsigned i=0; i<listEdge.size(); i++) {
			edge* e = listEdge[i];
			if ((e->vertex1==v1 && e->vertex2==v2) || (e->vertex2==v1 && e->vertex1==v2)) {
				e->weight = wei;
			}
		}
		return;
	}
	void setVertexLabel() {
		for (unsigned i=0; i<listVertex.size(); i++) {
			listVertex[i]->unexplored = true;
		}
	}
	void setEdgeLabel() {
		for (unsigned i=0; i<listEdge.size(); i++) {
			listEdge[i]->unexplored = true;
		}
	}
	vertex* insertVertex(string e) {
		vertex* newVertex = new  vertex(e);
		listVertex.push_back(newVertex);
		return newVertex;
	}
	edge* insertEdge(long wei, vertex* v1, vertex* v2) {
		if (v1==NULL || v2==NULL) return NULL;
		edge* newEdge = new edge(wei,v1,v2);
		listEdge.push_back(newEdge);
		v1->AjaEdge.push_back(newEdge); v2->AjaEdge.push_back(newEdge);
		return newEdge;
	}
	void removeEdge(string v, string w) {
		vertex* v1 = findVertex(v), *v2 = findVertex(w);
		if (v1==NULL || v2==NULL) return;
		edge* e = NULL;
		unsigned indexEdge = 0;
		for (unsigned i=0; i<listEdge.size(); i++) {
			if ((listEdge[i]->vertex1==v1 && listEdge[i]->vertex2==v2) || 
			listEdge[i]->vertex1==v2 || listEdge[i]->vertex2==v1) {
				e = listEdge[i];
				indexEdge = i;
			}
		}
		if (e==NULL) return ;
		unsigned tmp = 0;
		for (unsigned i=0; i<v1->AjaEdge.size(); i++) {
			if (v1->AjaEdge[i]==e) tmp = i;
		}
		v1->AjaEdge.erase(v1->AjaEdge.begin()+tmp);
		for (unsigned i=0; i<v2->AjaEdge.size(); i++) {
			if (v2->AjaEdge[i]==e) tmp = i;
		}
		v2->AjaEdge.erase(v2->AjaEdge.begin()+tmp);
		delete e;
		listEdge.erase(listEdge.begin()+indexEdge);
		return;
	}
	void removeVertex(string e) {
		vertex* v = NULL;
		unsigned indexVertex = 0;
		for (unsigned i=0; i<listVertex.size(); i++) {
			if (listVertex[i]->element==e) {
				v = listVertex[i];
				indexVertex = i;
			}
		}
		if (v==NULL) return;
		while (v->AjaEdge.size()!=0) {
			edge* tmp = v->AjaEdge[0];
			removeEdge(v->element,opposite(v,tmp)->element);
		}
		delete v;
		listVertex.erase(listVertex.begin()+indexVertex);
		return;
	}
	void depth_first_search(string c) {
		setVertexLabel(); setEdgeLabel();
		vertex* v = findVertex(c);
		if (v!=NULL) depth_first_search(v);
		cout << endl;
	}
	void depth_first_search(vertex* start) {
		cout << start->element << "  ";
		start->unexplored = false;
		for (unsigned i=0; i<start->AjaEdge.size(); i++) {
			if (start->AjaEdge[i]->unexplored) {
				vertex* next = opposite(start,start->AjaEdge[i]);
				if (next->unexplored) depth_first_search(next);
			}
			
		}
	}
	void breadth_first_search(string c) {
		vertex* v = findVertex(c);
		if (v==NULL) return;
		setVertexLabel(); setEdgeLabel();
		cout << c << "  "; v->unexplored = false;
		queue <vertex*> temp; 
		temp.push(v);
		while (temp.size()!=0) {
			for (unsigned i=1; i<=temp.size(); i++) {
				vertex* tmp = temp.front(); temp.pop();
				for (unsigned j=0; j<tmp->AjaEdge.size(); j++) {
					if (tmp->AjaEdge[j]->unexplored) {
						vertex* next = opposite(tmp,tmp->AjaEdge[j]);
						if (next->unexplored) {
							tmp->AjaEdge[j]->unexplored = false;
							cout << next->element << "  ";
							next->unexplored = false;
							temp.push(next);
						}
					}
				}
			}
		}
		cout << endl;
	}

	bool findPath(vertex* v1, vertex* v2, stack<vertex*>& track) {
		track.push(v1);
		if (v1==v2) {
			while (!track.empty()) {
				cout << track.top()->element << "  ";
				track.pop();
			}
			return true;
		}
		for (unsigned i=0; i<v1->AjaEdge.size(); i++) {
			if (v1->AjaEdge[i]->unexplored) {
				vertex* next = opposite(v1,v1->AjaEdge[i]);
				if (next->unexplored) {
					v1->unexplored = false;
					v1->AjaEdge[i]->unexplored = false;
					bool end = findPath(next,v2,track);
					if (end) return end;
				}
			}
		}
		track.pop();
		return false;
	}
	void findPath(string c1, string c2) {
		vertex* v1 = findVertex(c1), *v2 = findVertex(c2);
		if (v1==NULL || v2==NULL) return;
		setEdgeLabel(); setVertexLabel();
		stack<vertex*> track;
		v2->unexplored = false;
		findPath(v2,v1,track);
		cout << endl;
	}
	void cycleFinding(string c) {
		vertex* v = findVertex(c);
		if (v==NULL) return;
		setEdgeLabel(); setVertexLabel();
		stack<vertex*> track;
		track.push(v);
		if (v->AjaEdge.size()<2) {
			cout << v->element; return;
		}
		vertex* w = opposite(v,v->AjaEdge[0]);
		v->AjaEdge[0]->unexplored = 0;
		findPath(w,v,track);
		cout << endl;
	}
	long shortest_path(string start, string finish) {
		vertex* w = findVertex(start), *v = findVertex(finish);
		if (v==NULL || v==w) return 0;
		setVertexLabel(); v->unexplored = false;
		for (unsigned i=0; i<listVertex.size(); i++) {
			listVertex[i]->label = 1000000000;
		}
		vertex* next;
		v->label = 0;
		stack<vertex*> path; path.push(v);
		do {
			for (unsigned i=0; i<v->AjaEdge.size(); i++) {
				next = opposite(v,v->AjaEdge[i]);
				if (next->unexplored) {
					long tempLabel = v->label + v->AjaEdge[i]->weight;
					if (tempLabel<next->label) next->label = tempLabel;
				}
			}
			long minLabel = 1000000000;
			for (unsigned i=0; i<listVertex.size(); i++) {
				if (listVertex[i]->label<minLabel && listVertex[i]->unexplored) {
					minLabel = listVertex[i]->label;
					next = listVertex[i];
				}
			}
			v = next;
			v->unexplored = false; path.push(v);
		} while (v!=w);
		long distance = 0;
		v = path.top(); path.pop(); cout << v->element << "  ";
		while (!path.empty()) {
			bool cont;
			do {
				w = path.top(); path.pop();
				if (areAdjacent(v,w)) {
					cont = (v->label-w->label!=findEdge(v->element,w->element)->weight);
				} else cont = true;
			} while (cont);
			distance += v->label-w->label;
			v = w; cout << v->element << "  ";
		}
		cout << endl;
		return distance;
	}
	void minimum_spanning_tree() {
		setEdgeLabel(); setVertexLabel();
		vector<vertex*> cloud;
		edge* init = listEdge[0];
		for (unsigned i=1; i<listEdge.size(); i++) {
			if (listEdge[i]->weight < init->weight) init = listEdge[i];
		}
		init->vertex1->unexplored = false; init->vertex2->unexplored = false;
		init->unexplored = false;
		cloud.push_back(init->vertex1); cloud.push_back(init->vertex2);
		for (unsigned i=0; i<listVertex.size()-2; i++) {
			edge* minEdge;
			vertex* minVer;
			int count = 0;
			for (unsigned j=0; j<cloud.size(); j++) {
				for (unsigned k=0; k<cloud[j]->AjaEdge.size(); k++) {
					if (cloud[j]->AjaEdge[k]->unexplored && count==0) {
						minEdge = cloud[j]->AjaEdge[k];
						minVer = cloud[j];
						count++;
					}
					else if (cloud[j]->AjaEdge[k]->unexplored && minEdge->weight > cloud[j]->AjaEdge[k]->weight) {
						minEdge = cloud[j]->AjaEdge[k];
						minVer = cloud[j];
					}
				}
			}
			minEdge->unexplored = false;
			opposite(minVer,minEdge)->unexplored = false;
			cloud.push_back(opposite(minVer,minEdge));
		}
		for (unsigned i=0; i<listEdge.size(); i++) {
			if (!listEdge[i]->unexplored) {
				cout << "(" << listEdge[i]->vertex1->element << "," << listEdge[i]->vertex2->element << ")";
				if (i!=listVertex.size()-2) cout << " ; ";
			}
		}
	}
};

int main()
{
	Graph g;
	//g.input_by_matrix();
	vertex *v1, *v2, *v3, *v4, *v5, *v6, *v7;
	v1 = g.insertVertex("s");
	v2 = g.insertVertex("l");
	v3 = g.insertVertex("d");
	v4 = g.insertVertex("c");
	v5 = g.insertVertex("b");
	v6 = g.insertVertex("n");
	v7 = g.insertVertex("de");
	g.insertEdge(3,v1,v2);
	g.insertEdge(4,v1,v7);
	g.insertEdge(5,v1,v4);
	g.insertEdge(7,v2,v4);
	g.insertEdge(5,v2,v3);
	g.insertEdge(4,v3,v7);
	g.insertEdge(5,v4,v3);
	g.insertEdge(6,v7,v4);
	g.insertEdge(3,v4,v5);
	g.insertEdge(4,v4,v6);
	g.insertEdge(2,v5,v6);
	g.insertEdge(6,v3,v6);
	//if (g.areAdjacent(v3,v5)) cout << g.findEdge("b","d")->weight;
	// string s;
	// cin >> s;
	// g.breadth_first_search("n");
	// g.depth_first_search("s");
	// g.cycleFinding("l");
	// g.findPath("s","d");
	//long d = g.shortest_path("a","z");
	g.minimum_spanning_tree();
	//cout << d;
}