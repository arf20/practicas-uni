NodoPtr imparesPositivos(int n) {
	NodoPtr p = malloc(sizeof(struct Nodo));
	p->sig = NULL;
	NodoPtr l = p;

	for (int i = 0; i < n; i++) {
		NodoPtr n = malloc(sizeof(struct Nodo));
		n->elem = 2*i + 1;
		n->sig = NULL;
		l->sig = n;
		l = l->sig;
	}
	
	return p;
}
