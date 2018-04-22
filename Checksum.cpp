Checksum::Checksum(){

}

Checksum::check(Byte[] speicher){
    for (int i = 0; i < speicher.length(); i++) {
        
        for (int j = 0; j < speicher[i].)
    }
}

Checksum::auswerten(bool[] input){
    int pos = 0;
    for (int i = 0; i < input.length(); i++){
        if (input[i] = true){
            pos++;
        }
    }
    return pos;
}

Checksum::zerlegen(Byte a){
    bool[] b = new bool[8];
    for (int i = 0; i < 8; i++) {
        b[i] = false;
    }
    while (a != 0){
        if (a >= 128){
            b[7] = true;
            a = a - 128;
        }
        if (a >= 64){
            b[6] = true;
            a = a - 64;
        }
        if (a >= 32){
            b[5] = true;
            a = a - 32;
        }
        if (a >= 16){
            b[4] = true;
            a = a - 16;
        }
        if (a >= 8){
            b[3] = true;
            a = a - 8;
        }
        if (a >= 4){
            b[2] = true;
            a =  a - 4;
        }
        if (a >= 2){
            b[1] = true;
            a = a - 2;
        }
        if (a >= 1){
            b[0] = true;
            a = a - 1;
        }
    }
    
    return b;
}