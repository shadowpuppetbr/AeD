int hIndex(int* citations, int citationsSize) {
    int h;
    int persist= -1;
   
    if(citationsSize == 1){ 
        if( citations[0] < 1){
        return 0;
    }
        return 1;
    }
    for(int i=citationsSize; i>=1; i--){
        int citation=0;
        h = i;
        
        for( int j=0;j<citationsSize;j++){
            if(citations[j] >= h ){
                citation++;
            }
        }
        if(citation == 0 && h == 1){
            return 0;
        }
        if(citation == h){
            return h;
        }
        if(citation > h && h > persist){
            persist = h;
        }
    }
    if( persist != -1){
        return persist;
    }
    return h;
}