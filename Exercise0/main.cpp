int main()
{
	
	/* un puntatore è un oggetto che contiene un indirizzo mentre 
	 * una referenza è un alias -> ha lo stesso indirizzo di ciò che 
	 * referenzia */
	 
	 
	int a = 2;
	const int &b = a;

	int *p = &a;
	
	
	
	// se ho invece //
	const int *p = &a;
	// non posso usare p per modificare a tipo con (*p)++ //
	
	int c = 4;
	p = &c;
	
	
	// per rendere costante anche il puntatore devo fare//
	const int * const p
	
	
	// alias per un puntatore ad intero //
	int * &ptr = p;
	
	///Array 
	
	// la dimensione è un unsigned int //
	
	
	
	
    return 0;
    
    
    
    
    
    
}

